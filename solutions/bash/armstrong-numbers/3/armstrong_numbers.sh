#!/usr/bin/env bash

armstrong() {
	if (($# != 1)) || ! [[ $1 =~ ^[0-9]+$ ]]; then
		echo "usage: $0 [integer]"
		return 1
	fi

	local -i number=$1
	local -i sum=0

	# Shift digits off the right, raise to string length of number, and add to sum
	for ((buffer = number; buffer > 0; buffer /= 10)); do
		local -i digit=$((buffer % 10))
		sum+=$((digit ** ${#number}))
	done

	if ((sum == number)); then
		echo "true"
	else
		echo "false"
	fi
	return 0
}

armstrong "$@"
