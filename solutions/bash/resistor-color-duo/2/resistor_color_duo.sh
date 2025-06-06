#!/usr/bin/env bash

declare -A resistance_values=( 
  ["black"]=0 
  ["brown"]=1
  ["red"]=2
  ["orange"]=3
  ["yellow"]=4
  ["green"]=5
  ["blue"]=6
  ["violet"]=7
  ["grey"]=8
  ["white"]=9
)

get_resistance_value () {
  local color=$1
  # Test for key based on https://stackoverflow.com/questions/13219634/easiest-way-to-check-for-an-index-or-a-key-in-an-array
  # The +1 value resolves to status code 1 if the key is not found
  [ ${resistance_values[$color]+1} ] && printf "%s" "${resistance_values[$color]}"
}

main () {
  local first_color=$1
  local second_color=$2

  if ! first_value=$(get_resistance_value "$first_color") || ! second_value=$(get_resistance_value "$second_color"); then
    printf "invalid color\n"
    return 1
  fi

  printf "%d\n" "$((first_value * 10 + second_value))"
  return 0
}

main "$@"
