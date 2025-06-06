#!/usr/bin/env bash

get_resistance_value () {
  local color=$1
  local value

  case $color in
    black | Black)
      value="0"
      ;;
    brown | Brown)
      value="1"
      ;;
    red | Red)
      value="2"
      ;;
    orange | Orange)
      value="3"
      ;;
    yellow | Yellow)
      value="4"
      ;;
    green | Green)
      value="5"
      ;;
    blue | Blue)
      value="6"
      ;;
    violet | Violet)
      value="7"
      ;;
    grey | Grey | gray | Gray)
      value="8"
      ;;
    white | White)
      value="9"
      ;;
    *)
      value="err"
      ;;
  esac

  printf "$value"
}

main () {
  first_color=$1
  second_color=$2

  first_value=$(get_resistance_value $first_color)
  second_value=$(get_resistance_value $second_color)

  if [[ "$first_value" = "err" ]] || [[ "$second_value" = "err" ]]; then
    printf "invalid color\n"
    return 1

  fi

  result="$(($first_value * 10 + $second_value))"

  printf "%d\n" $result
  
  return 0
}


main "$@"
