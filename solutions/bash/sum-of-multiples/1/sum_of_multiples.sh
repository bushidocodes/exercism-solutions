#!/usr/bin/env bash

main() {
	local -ir limit="${1:?limit not defined}"
	local -ar factors=("${@:2}")
	local -a multiples=()

	for factor in "${factors[@]}"; do
		((factor < 1)) && continue
		for ((i = factor; i < limit; i += factor)); do
			multiples+=("$i")
		done
	done

	# Sort and filter duplicates
	readarray -t sorted < <(for multiple in "${multiples[@]}"; do echo "$multiple"; done | sort -u -n)

	local -i sum=0
	for multiple in "${sorted[@]}"; do
		((sum += multiple))
	done

	echo "$sum"
	return 0
}

main "$@"
