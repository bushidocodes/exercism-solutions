#!/usr/bin/env bash

# Since bash doesn't have structs, we can only associate state
# by using consistent keys across our associative arrays. We can
# then by convention treat one of the arrays as the "cannonical"
# set of keys

declare -A matches_played
declare -A wins
declare -A draws
declare -A losses
declare -A points

add_team_if_needed() {
  local team=$1
  # matches_played is our cannonical set of keys
  if [ ! ${matches_played["$team"]+_} ]; then
    matches_played["$team"]=0
    wins["$team"]=0
    draws["$team"]=0
    losses["$team"]=0
    points["$team"]=0
  fi
}

print_table() {
  printf "%-31s| MP |  W |  D |  L |  P\n" "Team"

  mapfile -t teams_sorted < <(for key in "${!matches_played[@]}"; do
    printf "%s, %s\n" "$key" "${wins["$key"]}"
  done |
    sort -n -k2 -r -t, |
    awk 'BEGIN {FS = "," } ; {print $1}')

  for team in "${teams_sorted[@]}"; do
    printf "%-31s|  %d |  %d |  %d |  %d |  %d\n" \
      "$team" \
      "${matches_played["$team"]}" \
      "${wins["$team"]}" \
      "${draws["$team"]}" \
      "${losses["$team"]}" \
      "${points["$team"]}"
  done
}

process_match() {
  first_team=$1
  second_team=$2

  add_team_if_needed "$first_team"
  add_team_if_needed "$second_team"
  ((matches_played["$first_team"]++))
  ((matches_played["$second_team"]++))

  if [[ $outcome =~ win* ]]; then
    ((wins["$first_team"]++))
    ((losses["$second_team"]++))
    ((points["$first_team"] += 3))
  elif [[ $outcome =~ loss* ]]; then
    ((losses["$first_team"]++))
    ((wins["$second_team"]++))
    ((points["$second_team"] += 3))
  elif [[ $outcome =~ draw* ]]; then
    ((draws["$first_team"]++))
    ((draws["$second_team"]++))
    ((points["$first_team"]++))
    ((points["$second_team"]++))
  fi
}

main() {
  while IFS=\; read -t 0.1 -u 0 -r first_team second_team outcome; do
    [ -n "$first_team" ] && [ -n "$second_team" ] && process_match "$first_team" "$second_team"
  done < <(echo "$1")
  print_table
}

main "$@"
exit 0
