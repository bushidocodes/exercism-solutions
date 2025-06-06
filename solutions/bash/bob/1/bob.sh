#!/usr/bin/env bash

is_silent() {
	if (($# != 1)); then
		printf "Unexpected number of arguments. Saw %d. Expected 1." $#
		exit 1
	fi

	local -r sentence="$1"

	[[ -z ${sentence//[[:space:]]/} ]]
}

is_shouting() {
	if (($# != 1)); then
		printf "Unexpected number of arguments. Saw %d. Expected 1." $#
		exit 1
	fi

	local -r sentence="$1"
	local -r uppercase="${sentence^^}"
	local -r lowercase="${sentence,,}"

	# A sentence has letters if lowercase differs from uppercase
	[[ $uppercase != "$lowercase" ]] && [[ $uppercase == "$sentence" ]]
}

is_question() {
	if (($# != 1)); then
		printf "Unexpected number of arguments. Saw %d. Expected 1." $#
		exit 1
	fi

	# Strip trailing whitespace
	local -r sentence="${1//[[:space:]]/}"

	[[ ${sentence: -1} == "?" ]]
}

main() {
	local -r sentence="$1"

	if is_silent "$sentence"; then
		printf "Fine. Be that way!\n"
	elif is_shouting "$sentence"; then
		if is_question "$sentence"; then
			printf "Calm down, I know what I'm doing!\n"
		else
			printf "Whoa, chill out!\n"
		fi
	elif is_question "$sentence"; then
		printf "Sure.\n"
	else
		printf "Whatever.\n"
	fi

	exit 0
}

main "$@"
