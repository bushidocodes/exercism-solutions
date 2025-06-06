#!/usr/bin/env bash

declare -Ar numerals=(
	["M"]=1000
	["CM"]=900
	["D"]=500
	["CD"]=400
	["C"]=100
	["XC"]=90
	["L"]=50
	["XL"]=40
	["X"]=10
	["IX"]=9
	["V"]=5
	["IV"]=4
	["I"]=1
)

declare -ar ordered_numerals=("M" "CM" "D" "CD" "C" "XC" "L" "XL" "X" "IX" "V" "IV" "I")

usage() {
	echo "Usage: $0 number"
	echo "number should be a positive number greater than zero"
	exit
}

arabic_to_roman() {
	(($# != 1)) && usage
	(($1 <= 0)) && usage
	local -i buffer="$1"

	for numeral in "${ordered_numerals[@]}"; do
		local -i numeral_value="${numerals[$numeral]}"
		while ((buffer >= numeral_value)); do
			printf "%s" "$numeral"
			((buffer -= numeral_value))
		done
	done

	printf "\n"
	return 0
}

arabic_to_roman "$@"
