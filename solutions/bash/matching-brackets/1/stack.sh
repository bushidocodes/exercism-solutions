#!/usr/bin/env bash
stack=()

push() {
  local value=$1
  stack+=("$value")
}

pop() {
  local result=$1
  if ! is_empty; then 
    eval "$result='${stack[-1]}'"
    unset "stack[-1]"
  else 
    eval "$result='-1'"
  fi
}

print() {
  printf "Stack: \n"
  for elem in "${stack[@]}"; do 
    printf "%s\n" "$elem"
  done
}

is_empty() {
  return ${#stack[@]}
}