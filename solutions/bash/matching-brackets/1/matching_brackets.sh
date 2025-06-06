#!/usr/bin/env bash

# shellcheck disable=SC1091
source stack.sh

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
      push "$bracket"
      return 0
      ;;
    "]" | "}" | ")" )
      pop last_bracket
      if [[ $last_bracket != "[" && $last_bracket != "{" && $last_bracket != "(" ]]; then
        return 1
      elif [[ $last_bracket != "${matching_brackets[$bracket]}" ]]; then
        return 1
      else
        return 0
      fi
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
    if [[ $char != "[" && $char != "]" && $char != "{" && $char != "}" && $char != "(" && $char != ")" ]]; then
      continue
    fi

    if ! process_bracket "$char"; then
      printf "false\n"
      return 0
    fi
  done

  if is_empty; then
    printf "true\n"
    return 0
  else
    printf "false\n"
    return 0
  fi

}

main "$@"

