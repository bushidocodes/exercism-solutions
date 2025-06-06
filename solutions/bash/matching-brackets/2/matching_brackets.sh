#!/usr/bin/env bash

# shellcheck disable=SC1091
source stack.sh

# shellcheck disable=SC2034
stack=()

declare last_bracket
declare -A matching_brackets=( 
  ["]"]="[" 
  ["}"]="{"
  [")"]="("
)

process_bracket() {
  local bracket=$1
  case $bracket in
    "[" | "{" | "(" )
      push stack "$bracket"
      ;;
    "]" | "}" | ")" )
      pop stack last_bracket
      [ "$?" -eq 1 ] && return 1
      [[ $last_bracket == "${matching_brackets[$bracket]}" ]]
      ;;
  esac
}

main() {
  local brackets=$1
  local -a char_arr

  for (( i=0; i < ${#brackets}; i++ )); do 
    char_arr[i]=${brackets:i:1}; 
  done

  for char in "${char_arr[@]}"; do
    if ! process_bracket "$char"; then
      printf "false\n"
      return 0
    fi
  done
  
  is_empty stack && echo true || echo false
}

main "$@"

