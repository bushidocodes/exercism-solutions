#!/usr/bin/env bash

# Since bash doesn't have structs, we can only associate state
# by using consistent keys across our associative arrays. We can
# then by convention treat one of the arrays as the "cannonical"
# set of keys

declare -A wins
declare -A draws
declare -A losses

add_team_if_needed() {
	local team=$1
	# wins is our cannonical set of keys
	if [ ! ${wins["$team"]+_} ]; then
		wins["$team"]=0
		draws["$team"]=0
		losses["$team"]=0
	fi
}

print_table() {
	# Derive points from wins and draws
	local -A points
	for team in "${!wins[@]}"; do
		points["$team"]=$((3 * wins["$team"] + draws["$team"]))
	done

	# Sort teams by points, then by name
	# mapfile captured a line terminated stream into indexed array teams_sorted
	mapfile -t teams_sorted < <(for key in "${!points[@]}"; do
		printf "%s, %s\n" "$key" "${points["$key"]}"
	done \
		| sort -t, -k2,2nr -k1,1d \
		| awk 'BEGIN {FS = "," } ; {print $1}')

	# Print header
	printf "%-31s| MP |  W |  D |  L |  P\n" "Team"

	# Print rows in sorted team order
	for team in "${teams_sorted[@]}"; do
		local -i matches_played=$((wins["$team"] + draws["$team"] + losses["$team"]))
		printf "%-31s| %2s | %2s | %2s | %2s | %2s\n" \
			"$team" \
			"$matches_played" \
			"${wins["$team"]}" \
			"${draws["$team"]}" \
			"${losses["$team"]}" \
			"${points["$team"]}"
	done
}

process_match() {
	local first_team=$1
	local second_team=$2
	local outcome=$3

	add_team_if_needed "$first_team"
	add_team_if_needed "$second_team"

	case $outcome in
		win)
			((wins["$first_team"]++))
			((losses["$second_team"]++))
			;;
		loss)
			((losses["$first_team"]++))
			((wins["$second_team"]++))
			;;
		draw)
			((draws["$first_team"]++))
			((draws["$second_team"]++))
			;;
	esac
}

main() {
	if ! [[ -t 0 ]]; then
		while IFS=\; read -r first_team second_team outcome; do
			[[ -n $first_team ]] && [[ -n $second_team ]] && process_match "$first_team" "$second_team" "$outcome"
		done
	else
		while IFS=\; read -r first_team second_team outcome; do
			[[ -n $first_team ]] && [[ -n $second_team ]] && process_match "$first_team" "$second_team" "$outcome"
		done < "$1"
	fi
	print_table

	return 0
}

main "$@"
