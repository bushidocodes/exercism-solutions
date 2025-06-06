#!/usr/bin/env bash

function join_by() {
  local IFS="$1"
  shift
  echo "$*"
}

main() {
  declare -i up_to=$1
  declare -a primes=()

  for ((i = 2; i <= up_to; i++)); do
    # Am I the first prime.. ie 2?
    if ((${#primes} == 0)); then
      primes+=("$i")
      continue
    fi

    # Am I divisible by an existing prime, continue the outer loop
    for prime in "${primes[@]}"; do
      ((i % prime == 0)) && continue 2
    done

    # Otherwise, I'm a prime
    primes+=("$i")
  done

  join_by " " "${primes[@]}"
}

main "$@"
