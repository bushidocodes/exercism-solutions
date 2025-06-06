#!/usr/bin/env bash

# Pad the zeroth element to match base-1 indexing used by API
declare -ga ordinals=("" "first" "second" "third" "fourth" "fifth" "sixth" "seventh" "eighth" "ninth" "tenth" "eleventh" "twelfth")

declare -ga gifts=("" "a Partridge in a Pear Tree" "two Turtle Doves" "three French Hens" "four Calling Birds" "five Gold Rings" "six Geese-a-Laying" "seven Swans-a-Swimming" "eight Maids-a-Milking" "nine Ladies Dancing" "ten Lords-a-Leaping" "eleven Pipers Piping" "twelve Drummers Drumming")

error() {
	(($# == 1)) && printf "Error: %s\n" "$1"
	exit 1
}

list_gifts() {
	(($# != 1)) && error "Invalid Number of parameters. Saw $#. Expected 1"
	local -i verse="$1"
	((verse < 1 || verse > 12)) && error "Invalid Verse"
	local list=""

	for ((i = verse; i >= 1; i--)); do
		if ((i > 1)); then
			list+="${gifts[$i]}, "
		elif ((verse == 1)); then
			list+="${gifts[$i]}."
		else
			list+="and ${gifts[$i]}."
		fi
	done

	printf "%s" "$list"
	return 0
}

print_verse() {
	(($# != 1)) && error "Invalid Number of parameters. Saw $#. Expected 1"

	local -i verse="$1"

	((verse < 1 || verse > 12)) && error "Invalid Verse"

	printf "On the %s day of Christmas my true love gave to me: %s\n" "${ordinals[$verse]}" "$(list_gifts "$verse")"
}

main() {
	(($# != 2)) && error "Invalid Number of parameters. Saw $#. Expected 2"

	local -i start_verse="$1"
	local -i end_verse="$2"

	for ((i = start_verse; i <= end_verse; i++)); do
		print_verse "$i"
	done

	return 0
}

main "$@"
