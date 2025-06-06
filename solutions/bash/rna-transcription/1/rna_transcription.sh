#!/usr/bin/env bash

declare -Ar transcription_pairs=(
	['C']='G'
	['G']='C'
	['T']='A'
	['A']='U'
)

transcribe() {
	if (($# < 0 || $# > 1)); then
		printf "Invalid argument count. Saw %d, Expected 1.\n" "$#"
		printf "Usage: %s ACGTGGTCTTAA\n" "$0"
		return 1
	fi

	local strand=$1
	local complement=""

	local buffer
	for ((i = 0; i < ${#strand}; i++)); do
		buffer=${strand:$i:1}

		# If not a key in transcription_pairs, return error
		[[ ${transcription_pairs["$buffer"]+_} ]] || {
			printf "Invalid nucleotide detected.\n"
			return 1
		}

		complement+=${transcription_pairs["$buffer"]}
	done

	printf "%s\n" "$complement"
	return 0
}

transcribe "$@"
