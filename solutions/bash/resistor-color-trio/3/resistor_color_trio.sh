#!/usr/bin/env bash

get_resistance_value () {
  declare color=$1
  local value=""

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
  declare first_color=$1 second_color=$2 third_color=$3

  local first_value=$(get_resistance_value $first_color)
  local second_value=$(get_resistance_value $second_color)
  local third_value=$(get_resistance_value $third_color)

  if [[ "$first_value" = "err" ]] || [[ "$second_value" = "err" ]] || [[ "$third_value" = "err" ]]; then
    printf "invalid color\n"
    return 1
  fi

  local result="$(( ($first_value * 10 + $second_value) * (10 ** $third_value) ))"

  if [[ $result -eq 0 ]]; then
    printf "$result ohms\n"
  elif [[ $(("$result" % 1000000000)) -eq 0 ]]; then
    (( result /= 1000000000 ))
    printf "%d gigaohms\n" "$(( $result ))"
  elif [[ $(("$result" % 1000000)) -eq 0 ]]; then
    (( result /= 1000000 ))
    printf "%d megaohms\n" "$(( $result ))"
  elif [[ $(("$result" % 1000)) -eq 0 ]]; then
    (( result /= 1000 ))
    printf "%d kiloohms\n" "$(( $result ))"
  else
    printf "$result ohms\n"
  fi
  return 0;
}

main "$@"