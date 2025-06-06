#!/usr/bin/env bash

source lib.sh

score_letter() {
	validate_parameter_count 2 "$@"
	local -r letter="$1"
	local -n __score="$2"

	case "$letter" in
		A | E | I | O | U | L | N | R | S | T)
			__score=1
			;;
		D | G)
			__score=2
			;;
		B | C | M | P)
			__score=3
			;;
		F | H | V | W | Y)
			__score=4
			;;
		K)
			__score=5
			;;
		J | X)
			__score=8
			;;
		Q | Z)
			__score=10
			;;
		*)
			return 1
			;;
	esac

	return 0
}

main() {
	validate_parameter_count 1 "$@"

	local -r string="$1"
	local -i char_score=0
	local -u char
	local -i total_score=0

	for ((i = 0; i < ${#string}; i++)); do
		char="${string:$i:1}"
		score_letter "$char" char_score || {
			printf "Unscorable character: %s\n" "$char"
			exit 1
		}
		((total_score += char_score))
	done

	printf "%d\n" "$total_score"
	exit 0
}

main "$@"
