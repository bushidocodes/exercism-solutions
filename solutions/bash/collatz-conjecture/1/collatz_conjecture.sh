#!/usr/bin/env bash

err() {
	(($# == 1)) && printf "Error: %s\n" "$1"
	exit 1
}

main() {
	(($# != 1)) && "Expected 1 argument, saw $#"

	local -i number="$1"
	((number <= 0)) && err "Only positive numbers are allowed"

	local -i steps=0
	for ((steps = 0; number != 1; steps++)); do
		if ((number % 2 == 0)); then
			((number /= 2))
		else
			number=$((3 * number + 1))
		fi
	done

	echo "$steps"
	return 0
}

main "$@"
