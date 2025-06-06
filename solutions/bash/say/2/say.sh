#!/usr/bin/env bash

declare -ra ones=(zero one two three four five six seven eight nine)
declare -ra tens=(zero ten twenty thirty forty fifty sixty seventy eighty ninety)

# Shifts off and clears the digit at offset, which is zero-based and indexed from the right
# offset 0 is thus the "ones place"
digit_shift() {
	local -n digit_shift_buffer="$1"
	local -i offset="$2"
	local -n digit_shift_return="$3"

	local -i _buffer="$digit_shift_buffer"
	for ((i = 0; i < offset; i++)); do
		((_buffer /= 10))
	done

	digit_shift_return="$((_buffer % 10))"
	((digit_shift_buffer -= (digit_shift_return * (10 ** offset))))
}

# Describing numbers between 1000 is inconsistent in English, but ones, thousands, millions, billions use same logic
sub_thousand() {
	local -n sub_thousand_buffer="$1"
	local -i sub_thousand_base_offset="$2"
	local -i sub_thousand_normalized=$((sub_thousand_buffer / (10 ** (sub_thousand_base_offset))))
	local -i digit

	if ((sub_thousand_normalized >= 100)); then
		digit_shift sub_thousand_buffer $((sub_thousand_base_offset + 2)) digit
		echo -n "${ones[$digit]} hundred"
		((sub_thousand_buffer > 0)) && echo -n " "
		sub_thousand_normalized=$((sub_thousand_buffer / (10 ** (sub_thousand_base_offset))))
	fi

	if ((sub_thousand_normalized >= 20 || sub_thousand_normalized == 10)); then
		digit_shift sub_thousand_buffer $((sub_thousand_base_offset + 1)) digit
		echo -n "${tens[$digit]}"
		((sub_thousand_buffer > 0)) && echo -n "-"
		sub_thousand_normalized=$((sub_thousand_buffer / (10 ** (sub_thousand_base_offset))))
	fi

	if ((sub_thousand_normalized > 10)); then
		digit_shift sub_thousand_buffer $((sub_thousand_base_offset)) digit
		echo -n "${ones[$digit]}teen"
		((sub_thousand_buffer -= 10 ** (sub_thousand_base_offset + 1)))
		sub_thousand_normalized=$((sub_thousand_buffer / (10 ** (sub_thousand_base_offset))))
	fi

	if ((sub_thousand_normalized > 0)); then
		digit_shift sub_thousand_buffer $((sub_thousand_base_offset)) digit
		echo -n "${ones[$digit]}"
	fi
}

err_out_of_range() {
	echo "input out of range"
	exit 1
}

main() {
	local -ir number="$1"
	((number >= 0 && number < 999999999999)) || err_out_of_range

	if ((number == 0)); then
		echo "zero"
		exit 0
	fi

	local -i buffer="$number"

	if ((buffer >= 1000000000)); then
		sub_thousand buffer 9
		echo -n " billion"
		((buffer > 0)) && echo -n " "
	fi

	if ((buffer >= 1000000)); then
		sub_thousand buffer 6
		echo -n " million"
		((buffer > 0)) && echo -n " "
	fi

	if ((buffer >= 1000)); then
		sub_thousand buffer 3
		echo -n " thousand"
		((buffer > 0)) && echo -n " "
	fi

	sub_thousand buffer 0

	echo ""

	return 0
}

main "$@"
