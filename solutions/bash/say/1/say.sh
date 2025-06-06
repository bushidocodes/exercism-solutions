#!/usr/bin/env bash

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

ones() {
	local -n ones_buffer="$1"
	local -i offset="$2"

	local -i digit
	digit_shift ones_buffer "$offset" digit

	case $digit in
		1) echo -n "one" ;;
		2) echo -n "two" ;;
		3) echo -n "three" ;;
		4) echo -n "four" ;;
		5) echo -n "five" ;;
		6) echo -n "six" ;;
		7) echo -n "seven" ;;
		8) echo -n "eight" ;;
		9) echo -n "nine" ;;
	esac
}

tens() {
	local -n tens_number="$1"
	local -i offset="$2"
	local -i digit
	digit_shift tens_number "$offset" digit

	case $digit in
		1) echo -n "ten" ;;
		2) echo -n "twenty" ;;
		3) echo -n "thirty" ;;
		4) echo -n "forty" ;;
		5) echo -n "fifty" ;;
		6) echo -n "sixty" ;;
		7) echo -n "seventy" ;;
		8) echo -n "eighty" ;;
		9) echo -n "ninety" ;;
	esac
}

sub_thousand() {
	local -n sub_thousand_buffer="$1"
	local -i sub_thousand_base_offset="$2"

	local -i sub_thousand_reduced=$((sub_thousand_buffer / (10 ** (sub_thousand_base_offset))))

	if ((sub_thousand_reduced >= 100)); then
		ones sub_thousand_buffer $((sub_thousand_base_offset + 2))
		echo -n " hundred"
		((sub_thousand_buffer > 0)) && echo -n " "
		sub_thousand_reduced=$((sub_thousand_buffer / (10 ** (sub_thousand_base_offset))))
	fi

	if ((sub_thousand_reduced >= 20)); then
		tens sub_thousand_buffer $((sub_thousand_base_offset + 1))
		((sub_thousand_buffer > 0)) && echo -n "-"
		sub_thousand_reduced=$((sub_thousand_buffer / (10 ** (sub_thousand_base_offset))))
	fi

	if ((sub_thousand_reduced > 10)); then
		ones sub_thousand_buffer "$sub_thousand_base_offset"
		((sub_thousand_buffer -= 10 ** (sub_thousand_base_offset + 1)))
		echo "teen"
	elif ((sub_thousand_reduced == 10)); then
		tens sub_thousand_buffer $((sub_thousand_base_offset + 1))
	elif ((sub_thousand_reduced > 0)); then
		ones sub_thousand_buffer $((sub_thousand_base_offset))
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
