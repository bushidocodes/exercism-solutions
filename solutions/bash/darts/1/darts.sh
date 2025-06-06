#!/usr/bin/env bash
set -o pipefail

main () {
  local x_coordinate=$1
  local y_coordinate=$2

  # Validate that the coordinates are signed ints or floats
  re='^[+-]?[0-9]+([.][0-9]+)?$'
  if ! [[ $x_coordinate =~ $re ]] || ! [[ $y_coordinate =~ $re ]]; then
    printf "error: Not a number\n" >&2
    exit 1
  fi

  local distance
  if ! distance=$(echo "scale=8; sqrt ($x_coordinate^2 + $y_coordinate^2)" | bc); then
    printf "Error executing math expressiong on bc\n" >&2
    exit 1
  fi

  local -i score
  if (( $(echo "$distance > 10" | bc) == 1 )); then
    score=0
  elif (( $(echo "$distance > 5" | bc) == 1 )); then
    score=1
  elif (( $(echo "$distance > 1" | bc) == 1 )); then
    score=5
  elif (( $(echo "$distance >= 0" | bc) == 1 )); then
    score=10
  else
    printf "Unexpectedly calculated a negative number\n"
    exit 1
  fi

  printf "%d\n" $score
  exit 0
}

main "$@"
