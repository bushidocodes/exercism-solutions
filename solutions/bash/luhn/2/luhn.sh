#!/usr/bin/env bash

exit_success() {
	(($# == 1)) && printf "%s\n" "$1"
	exit 0
}

main() {
	(($# != 1)) && exit 1

	# Strip spaces
	local -r candidate=${1// /}
	local -i candidate_length="${#candidate}"

	# Length of one is always invalid
	((candidate_length == 1)) && exit_success "false"

	local -i sum=0
	local char
	for ((i = candidate_length - 1; i >= 0; i--)); do
		char="${candidate:i:1}"
		# Non digits are always invalid
		[[ ! $char =~ [[:digit:]] ]] && exit_success "false"

		if (((candidate_length - i) % 2 == 0)); then
			((char *= 2))
			((char > 9)) && ((char -= 9))
		fi
		((sum += char))
	done

	if ((sum % 10 == 0)); then exit_success "true"; else exit_success "false"; fi
}

main "$@"
