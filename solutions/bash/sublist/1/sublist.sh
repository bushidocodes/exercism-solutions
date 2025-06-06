#!/usr/bin/env bash

# Encodes a list as comma separted elements with a trailing comma
stringify() {
	local -r raw_list="$1"
	local -n __string="$2"
	IFS="[], "
	for element in $raw_list; do
		[[ -n "$element" ]] && __string+="$element,"
	done
	return 0
}

# Once strinified, glob to check for sublists
main() {
	local first_list=""
	stringify "$1" first_list || exit 1
	stringify "$2" second_list || exit 1

	if [[ "$first_list" == "$second_list" ]]; then
		printf "equal\n"
	elif [[ "$first_list" == *$second_list* ]]; then
		printf "superlist\n"
	elif [[ "$second_list" == *$first_list* ]]; then
		printf "sublist\n"
	else
		printf "unequal\n"
	fi

	return 0
}

main "$@"
