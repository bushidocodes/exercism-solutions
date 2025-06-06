#!/usr/bin/env bash

armstrong() {
	if (($# != 1)) || ! [[ $1 =~ ^[0-9]+$ ]]; then
		echo "usage: $0 [integer]"
		return 1
	fi

	local -ir number=$1

	local -ir digit_count="${#number}"
	local -i digit=0
	local -i sum=0

	# Shift digits off the right, raise to string length of number, and add to sum
	for ((buffer = number; buffer > 0; buffer /= 10)); do
		digit=$((buffer % 10))
		((sum += (digit ** digit_count)))
	done

	if ((sum == number)); then
		echo "true"
	else
		echo "false"
	fi
	return 0
}

armstrong "$@"
