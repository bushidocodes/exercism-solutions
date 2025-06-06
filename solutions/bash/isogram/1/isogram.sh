#!/usr/bin/env bash

main() {
	(($# != 1)) && return 1
	local duplicate_letters
	# Pipeline generates a string containing duplicate letters
	duplicate_letters=$(echo "${1,,}" | grep -o . | grep -e "^[[:lower:]]$" | sort | uniq --repeated | tr -d "\n") || return 1
	if [[ ${#duplicate_letters} -gt 0 ]]; then
		printf "false\n"
		return 0
	else
		printf "true\n"
		return 0

	fi
}

main "$@"
