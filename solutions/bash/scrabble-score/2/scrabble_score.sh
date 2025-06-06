#!/usr/bin/env bash

source lib.sh

declare -A letter_score=(
	[A]=1 [E]=1 [I]=1 [O]=1 [U]=1 [L]=1 [N]=1 [R]=1 [S]=1 [T]=1
	[D]=2 [G]=2
	[B]=3 [C]=3 [M]=3 [P]=3
	[F]=4 [H]=4 [V]=4 [W]=4 [Y]=4
	[K]=5
	[J]=8 [X]=8
	[Q]=10 [Z]=10
)

main() {
	validate_parameter_count 1 "$@"

	local -r string="$1"
	local -u char
	local -i total_score=0

	for ((i = 0; i < ${#string}; i++)); do
		char="${string:$i:1}"
		((total_score += letter_score[${char}]))
	done

	printf "%d\n" "$total_score"
	exit 0
}

main "$@"
