#!/usr/bin/env bash

declare -a thing=(
	""
	"house that Jack built"
	"malt"
	"rat"
	"cat"
	"dog"
	"cow with the crumpled horn"
	"maiden all forlorn"
	"man all tattered and torn"
	"priest all shaven and shorn"
	"rooster that crowed in the morn"
	"farmer sowing his corn"
	"horse and the hound and the horn"
)

declare -a actioned=(
	""
	"lay in"
	"ate"
	"killed"
	"worried"
	"tossed"
	"milked"
	"kissed"
	"married"
	"woke"
	"kept"
	"belonged to"
	""
)

verse() {
	local -i verse=$1
	printf "This is the %s" "${thing[verse]}"
	if ((verse > 1)); then
		for i in $(seq "$((verse - 1))" -1 1); do
			printf "\nthat %s the %s" "${actioned[i]}" "${thing[i]}"
		done
	fi
	printf ".\n"
}

main()    {
	local -i start_verse=$1
	local -i end_verse=$2

	# Validate parameters
	if ((start_verse < 1 || start_verse > 12 || end_verse < 1 || end_verse > 12)); then
		echo "invalid"
		return 1
	fi

	# Generate verses separated by an empty line
	for i in $(seq "$start_verse" "$end_verse"); do
		verse "$i"
		((i < end_verse)) && printf "\n"
	done

	return 0
}

main   "$@"
