#!/usr/bin/env bash

armstrong() {
	if (($# != 1)) || ! [[ $1 =~ ^[0-9]+$ ]]; then
		echo "usage: $0 [integer]"
		return 1
	fi

	local -i number=$1
	local -i sum=0
	local -a digits=()

	# Shift digits off the right, adding to an array
	for ((buffer = number; buffer > 0; buffer /= 10)); do
		local -i digit=$((buffer % 10))
		digits+=("$digit")
	done

	# Calculate sum of digits raised to the power of number of digits
	for digit in "${digits[@]}"; do
		sum+=$((digit ** ${#digits[@]}))
	done

	# Return result
	if ((sum == number)); then
		echo "true"
	else
		echo "false"
	fi
	return 0
}

# call armstrong with all of the positional arguments
armstrong "$@"
