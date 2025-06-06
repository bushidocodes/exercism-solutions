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
  local first_color=$1 second_color=$2 third_color=$3
  local -i first_value second_value third_value result
  
  if ! first_value=$(get_resistance_value "$first_color") ||
  ! second_value=$(get_resistance_value "$second_color") ||
  ! third_value=$(get_resistance_value "$third_color"); then
    printf "invalid color\n"
    return 1
  fi
  
  result="$(( (first_value * 10 + second_value) * (10 ** third_value) ))"

  if (( result == 0 )); then
    printf "%d ohms\n" $result
  elif (( result % 1000000000 == 0 )); then
    (( result /= 1000000000 ))
    printf "%d gigaohms\n" $result
  elif (( result % 1000000 == 0 )); then
    (( result /= 1000000 ))
    printf "%d megaohms\n" $result
  elif (( result % 1000 == 0 )); then
    (( result /= 1000 ))
    printf "%d kiloohms\n" $result
  else
    printf "%d ohms\n" $result
  fi
  return 0;
}

main "$@"