#!/usr/bin/env bash

# Given a nameref to an array and an index, remove that value, shifting indices to close holes
remove_nth () {
  local -n __remove_nth_arr__=$1
  local -i idx_to_remove=$2
  temp=()

  for idx in "${!__remove_nth_arr__[@]}"; do
    if (( idx != idx_to_remove )); then
      temp+=("${__remove_nth_arr__[$idx]}")
    fi
  done

  __remove_nth_arr__=( "${temp[@]}" )
}