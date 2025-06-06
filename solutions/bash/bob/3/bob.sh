#!/usr/bin/env bash

source "lib.sh"

is_silent() {
	validate_parameter_count 1 "$@"

	local -r sentence="$1"

	[[ -z ${sentence//[[:space:]]/} ]]
}

is_shouting() {
	validate_parameter_count 1 "$@"

	local -r sentence="$1"
	local -r uppercase="${sentence^^}"
	local -r lowercase="${sentence,,}"

	# A sentence has letters if lowercase differs from uppercase
	[[ $uppercase != "$lowercase" ]] && [[ $uppercase == "$sentence" ]]
}

is_question() {
	validate_parameter_count 1 "$@"

	# Strip trailing whitespace
	local -r sentence="${1//[[:space:]]/}"

	[[ ${sentence: -1} == "?" ]]
}

main() {
	# no input is considered silence, so 0 parameters is valid
	validate_parameter_count_between 0 1 "$@"

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
