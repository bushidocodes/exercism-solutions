#!/usr/bin/env bash

dtob () {
  local source=$1
  local -a stack=()
  local result=""

  for ((i=$source; i>=1; i=i/2)); do
    if (( $i >= 1)); then
      if (( $i % 2 == 1 )); then
        stack+=(1)
      else
        stack+=(0)
      fi
    fi
  done

  for ((i=${#stack[@]}-1; i>=0; i--)); do
    result+="${stack[$i]}"
  done
    printf "%s\n" $result
}

generate_handshake(){
  local -i source=$1
  local steps=("wink" "double blink" "close your eyes" "jump" "reverse")
  local position=0
  local buffer=()
  local result=""
  local should_reverse=false

  # Going digit by digit, handle flipped bits at position
  # The "jump" bit sets the flag to reverse
  # All others get appended as appropriate
  for ((i=$source; i >= 1; i=$i/10)); do
    if (( $i % 2 == 1 )); then
      case "${steps[$position]}" in
        "reverse")
          should_reverse=true
          break
          ;;
        *)
          buffer+=("${steps[$position]}")
          ;;
      esac
    fi
    ((position++))
  done

  # Build result string, reversing if needed
  if [ "$should_reverse" = true ] ; then
    if (( ${#buffer[@]} > 0 )); then
      result+="${buffer[-1]}"
    fi
    for ((i=${#buffer[@]}-2; i>=0; i--)); do
      result+=",${buffer[$i]}"
    done
  else 
    if (( ${#buffer[@]} > 0 )); then
      result+="${buffer[0]}"
    fi
    for ((i=1; i<${#buffer[@]}; i++)); do
      result+=",${buffer[$i]}"
    done
  fi

  printf "%s\n" "$result"
}

main () {
  if (( $1 == 0 || $1 > 31 )); then 
    return 0
  fi

  binary=$(dtob $1)
  result=$(generate_handshake $binary)
  printf "%s\n" "${result[@]}"
  return 0
}

main "$@"
