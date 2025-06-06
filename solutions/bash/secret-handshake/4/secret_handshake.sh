#!/usr/bin/env bash

generate_handshake(){
  local source=$1
  local result=""
  local buffer=()
  local steps=("wink" "double blink" "close your eyes" "jump" "reverse")
  local should_reverse=false
  local -i position=0

  # Going digit by digit, handle flipped bits at position
  # The "jump" bit sets the flag to reverse
  # All others get appended as appropriate
  for ((i=source; i>=1; i=i>>1)); do
    if (( i & 1 == 1 )); then
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
  if [ "$should_reverse" == true ]; then
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
  local -i input_integer=$1
  (( input_integer == 0 || input_integer > 31 )) && return 0

  result=$(generate_handshake "$input_integer")
  printf "%s\n" "${result[@]}"
  return 0
}

main "$@"
