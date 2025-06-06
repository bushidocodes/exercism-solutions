#!/usr/bin/env bash

main () {
  local -i number=$1
  local result=""

  ((number % 3 == 0)) && result+="Pling"
  ((number % 5 == 0)) && result+="Plang"
  ((number % 7 == 0)) && result+="Plong"

  if [[ -z "$result" ]]; then
    result="$number"
  fi

  echo "$result"
}

main "$@"
