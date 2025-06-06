#!/usr/bin/env bash

main () {
  declare name=$1

  # Return RC 1 if more than one parameter
  if [[ $# -ne 1 ]]; then
    printf "Usage: ./error_handling <greetee>"
    return 1
  fi

  printf "Hello, $name\n"
  return 0
}

main "$@"
