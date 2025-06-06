#!/usr/bin/env bash

main() {
	if (($# != 1)); then
		printf "Invalid character count. Saw %d, Expected 1.\n" "$#"
		printf "Usage: %s \"the quick brown fox jumps over the lazy dog\"\n" "$0"
		return 1
	fi

	local -r sentence=$1

	local -A letter_count=()
	for c in {a..z}; do
		letter_count+=(["$c"]=0)
	done

	local buffer
	for ((i = 0; i < ${#sentence}; i++)); do
		buffer=${sentence:$i:1}
		buffer=${buffer,,}
		[[ ${letter_count["$buffer"]+_} ]] && ((letter_count[$buffer] += 1))
	done

	for c in {a..z}; do
		(("${letter_count[$c]}" < 1)) && {
			printf "false\n"
			return 0
		}
	done

	printf "true\n"
	return 0
}

main "$@"
