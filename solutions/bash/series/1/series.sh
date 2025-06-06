#!/usr/bin/env bash

panic() {
	(($# == 1)) && printf "%s\n" "$1"
	exit 1
}

# Breaks the series of ASCII characters $1 into slices of length $2 delimited by a space
series_slice() {
	(($# != 2)) && panic "Invalid Arg Count. Saw $#. Expected 2"

	local -r series="$1"
	local -r series_len="${#series}"
	local -ri slice_len="$2"

	((series_len == 0)) && panic "series cannot be empty"
	((slice_len > series_len)) && panic "slice length cannot be greater than series length"
	((slice_len == 0)) && panic "slice length cannot be zero"
	((slice_len < 0)) && panic "slice length cannot be negative"

	local results=""

	for ((i = 0; i + slice_len <= series_len; i++)); do
		results+="${series:i:slice_len}"
		((series_len > i + slice_len)) && results+=" "
	done

	printf "%s\n" "$results"

	return 0
}

series_slice "$@"
