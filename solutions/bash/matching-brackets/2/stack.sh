#!/usr/bin/env bash

push() {
  local -n __push_stack__=$1
  local value=$2
  __push_stack__+=("$value")
}

pop() {
  local -n __pop_stack__=$1
  local -n __pop_value__=$2
  is_empty __pop_stack__ && return 1
  # shellcheck disable=SC2034
  __pop_value__=${__pop_stack__[-1]}
  unset "__pop_stack__[-1]"
}

print() {
  local -n __print_stack__=$1
  printf "Stack: \n"
  for elem in "${__print_stack__[@]}"; do 
    printf "%s\n" "$elem"
  done
}

is_empty() {
  local -n __is_empty_stack__=$1
  return ${#__is_empty_stack__[@]}
}