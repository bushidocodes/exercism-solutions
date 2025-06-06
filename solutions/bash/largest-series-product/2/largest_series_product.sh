#!/usr/bin/env bash

err_span_too_long() {
	echo "span must be smaller than string length"
	exit 1
}

err_neg_span() {
	echo "span must be greater than zero"
	exit 1
}

err_invalid_input() {
	echo "input must only contain digits"
	exit 1
}

main() {
	local -r input="$1"
	local -ir input_length="${#input}"
	local -ir span_length="$2"

	((span_length <= input_length)) || err_span_too_long
	((span_length >= 0)) || err_neg_span

	local span
	local -i max_product=0
	local -i span_product=1
	local digit

	for ((i = 0; i <= ${#input} - span_length; i++)); do
		span="${input:i:span_length}"
		span_product=1
		for ((j = 0; j < ${#span}; j++)); do
			digit=${span:j:1}
			[[ $digit =~ [[:digit:]] ]] || err_invalid_input
			((span_product *= digit))
		done
		((span_product > max_product)) && ((max_product = span_product))
	done

	echo "$max_product"
	return 0
}

main "$@"
