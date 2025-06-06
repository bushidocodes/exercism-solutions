#!/usr/bin/env bash

acronym() {
	# Declare a variable with the -u uppercase character attribute
	local -u acronym=""

	IFS=" -_*"
	for word in $1; do
		acronym+="${word:0:1}"
	done
	# Unset to restore default
	unset IFS

	echo "$acronym"
}

main() {
	acronym "$@"
	return 0
}

main "$@"
