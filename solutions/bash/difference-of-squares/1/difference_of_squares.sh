#!/usr/bin/env bash

square_of_sum() {
	local -i sum=0
	for ((i = 1; i <= $1; i++)); do
		((sum += i))
	done
	echo "$((sum ** 2))"
	return 0
}

sum_of_squares() {
	local -i sum_of_squares=0
	for ((i = 1; i <= $1; i++)); do
		((sum_of_squares += (i ** 2)))
	done
	echo "$sum_of_squares"
	return 0
}

difference() {
	local -i square_of_sum
	local -i sum_of_squares
	square_of_sum=$(square_of_sum "$1")
	sum_of_squares=$(sum_of_squares "$1")

	echo "$((square_of_sum - sum_of_squares))"
	return 0
}

usage() {
	echo "usage: $0 {square_of_sum|sum_of_squares|difference} [integer > 1]"
	exit 1
}

main() {
	if (($# != 2)) || ! [[ $2 =~ ^[0-9]+$ ]] || (($2 < 1)); then
		usage
	fi

	case $1 in
		square_of_sum) square_of_sum "$2" ;;
		sum_of_squares) sum_of_squares "$2" ;;
		difference) difference "$2" ;;
		*) usage ;;
	esac

	exit 0
}

main "$@"
