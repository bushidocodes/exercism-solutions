#!/usr/bin/env bash

err_exit() {
	(($# == 1)) && printf "%s\n" "$1"
	exit 1
}

pluralize() {
	(($# != 3)) && err_exit "Expected 3 argument. Saw $#"

	local -n __result="$1"
	local -ri count="$2"
	local -r noun="$3"

	((count < 1)) && err_exit "Expected count of 1 or more. Saw $count"

	case "$count" in
		1)
			__result="$count $noun"
			;;
		*)
			__result="$count ${noun}s"
			;;
	esac

	return 0
}

verse() {
	(($# != 1)) && err_exit "Expected 1 argument. Saw $#"

	local -i verse="$1"

	case "$verse" in
		1)
			printf "1 bottle of beer on the wall, 1 bottle of beer.
Take it down and pass it around, no more bottles of beer on the wall.\n"
			;;
		0)
			printf "No more bottles of beer on the wall, no more bottles of beer.
Go to the store and buy some more, 99 bottles of beer on the wall.\n"
			;;
		*)
			local bottle_string=""
			local bottle_string_next=""
			pluralize bottle_string "$verse" "bottle"
			pluralize bottle_string_next "$((verse - 1))" "bottle"
			printf "%s of beer on the wall, %s of beer.
Take one down and pass it around, %s of beer on the wall.\n" "$bottle_string" "$bottle_string" "$bottle_string_next"
			;;
	esac

	return 1
}

main() {
	case $# in
		2)
			local -i start_verse="$1"
			local -i end_verse="$2"
			((end_verse > start_verse)) && err_exit "Start must be greater than End"

			for ((i = start_verse; i >= end_verse; i--)); do
				verse "$i"
				((i != end_verse)) && printf "\n"
			done
			;;
		1)
			verse "$1"
			;;
		*)
			err_exit "1 or 2 arguments expected"
			;;
	esac

	return 0
}

main "$@"
