#!/usr/bin/env bash

main () {
  local name=$1

  # Return RC 1 if more than one parameter
  if (( $# != 1 )); then
    printf "Usage: error_handling.sh <person>\n"
    return 1
  fi

  printf "Hello, %s\n" "$name"
  return 0
}

main "$@"
