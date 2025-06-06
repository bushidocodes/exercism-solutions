#!/usr/bin/env bash

usage() {
	printf "Invalid number.  [1]NXX-NXX-XXXX N=2-9, X=0-9\n"
}

parse_number() {
	(("$#" != 3)) && exit 1
	local number="$1"
	local -n __area_code="$2"
	local -n __exchange_code="$3"
	case "${#number}" in
		7)
			__area_code=""
			__exchange_code="${number:0:3}"
			;;
		10)
			__area_code="${number:0:3}"
			__exchange_code="${number:3:3}"
			;;
		*)
			return 1
			;;
	esac

	return 0
}

validate_code() {
	(("$#" != 1)) && exit 1
	local code="$1"
	case "${code:0:1}" in
		0 | 1)
			return 1
			;;
		*)
			return 0
			;;
	esac
}

err() {
	usage
	exit 1
}

normalize_phone_number() {
	# Strip non numerics
	local number="${1//[![:digit:]]/}"

	# Strip Country Code
	number="${number/#1/}"

	# Parse area and exchange codes
	local area_code
	local exchange_code
	parse_number "$number" area_code exchange_code || err

	# Error if area code or exchange code starts with 0 or 1
	validate_code "$area_code" || err
	validate_code "$exchange_code" || err

	printf "%s\n" "$number"
	return 0
}

normalize_phone_number "$*"
