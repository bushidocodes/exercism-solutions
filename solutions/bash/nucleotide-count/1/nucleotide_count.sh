#!/usr/bin/env bash

main() {
  string=$1

  declare -i a_count=0
  declare -i c_count=0
  declare -i g_count=0
  declare -i t_count=0

  for ((i = 0; i < ${#string}; i++)); do
    case "${string:$i:1}" in
      A) ((a_count++)) ;;
      C) ((c_count++)) ;;
      G) ((g_count++)) ;;
      T) ((t_count++)) ;;
      *) echo "Invalid nucleotide in strand" && return 1 ;;
    esac
  done

  printf "A: %d\nC: %d\nG: %d\nT: %d" $a_count $c_count $g_count $t_count
}

main "$@"
