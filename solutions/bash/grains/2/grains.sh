#!/usr/bin/env bash

declare -ri MIN_SQUARE=1
declare -ri MAX_SQUARE=64

error() {
	printf "Error: invalid input\n"
	exit 1
}

# Sum exceeds 64-bit width of a bash number
# Concatenate a mathematical expression and fork a single bc subprocess
get_grains_on_board() {
	local bc_input=""
	for ((i = MIN_SQUARE; i <= MAX_SQUARE; i++)); do
		bc_input+="$(get_grains_on_square "$i")"
		((i != MAX_SQUARE)) && bc_input+="+"
	done
	bc <<< "$bc_input"
	return 0
}

# Can use bitwise operations in arithmetic expansion because
# number of squares equals fixed width of a bash integer
get_grains_on_square() {
	(("$1" < MIN_SQUARE || "$1" > MAX_SQUARE)) && error

	local -i square="$1"
	local -i grains=1
	((grains <<= (square - 1)))
	printf "%llu\n" "$grains"
	return 0
}

main() {
	(($# != 1)) && error

	case $1 in
		total)
			get_grains_on_board
			;;
		*)
			get_grains_on_square "$1"
			;;
	esac
}

main "$@"
