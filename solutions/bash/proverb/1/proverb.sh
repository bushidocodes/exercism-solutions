#!/usr/bin/env bash

main () {
  if [[ $# -gt 0 ]]; then
    local first=$1
    while [[ $# -gt 1 ]]; do
      printf "For want of a $1 the $2 was lost.\n"
      shift 1
    done
    printf "And all for the want of a $first.\n"
  fi
  return 0
}

main "$@"
