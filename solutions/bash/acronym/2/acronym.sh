#!/usr/bin/env bash

# Disable filename expansion
set -o noglob

acronym() {
	# Declare a variable with the -u uppercase character attribute
	local -u acronym=""

	IFS=" -_*"
	for word in $1; do
		acronym+="${word:0:1}"
	done

	echo "$acronym"
	return 0
}

acronym "$@"
