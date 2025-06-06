#!/usr/bin/env bash

main() {
	first_string=$1
	second_string=$2
	declare -i hamming_distance=0

	if (($# != 2)); then
		echo 'Usage: hamming.sh <string1> <string2>'
		return 1
	fi

	if ((${#first_string} != ${#second_string})); then
		echo 'left and right strands must be of equal length'
		return 1
	fi

	for ((i = 0; i < ${#first_string}; i++)); do
		[[ ${first_string:i:1} != "${second_string:i:1}" ]] && ((hamming_distance++))
	done

	echo "$hamming_distance"
}

main "$@"
