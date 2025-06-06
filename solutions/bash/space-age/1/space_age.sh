#!/usr/bin/env bash

declare -ri seconds_in_earth_year=31557600

declare -rA orbital_period=(
	[mercury]=0.2408467
	[venus]=0.61519726
	[earth]=1
	[mars]=1.8808158
	[jupiter]=11.862615
	[saturn]=29.447498
	[uranus]=84.016846
	[neptune]=164.79132
)

main() {
	(($# != 2)) && panic "Invalid Arg Count. Saw $#. Expected 2"
	local -rl planet="$1"
	local -ri age_in_sec="$2"

	[ ${orbital_period[$planet]+_} ] || {
		echo "not a planet"
		return 1
	}

	local period="${orbital_period[$planet]}"
	printf "%.2f\n" "$(bc <<< "scale=6; $age_in_sec / $seconds_in_earth_year / $period")"
	return 0
}

main "$@"
