#!/usr/bin/env bash

# shellcheck disable=SC1091
source "./array.sh"

roll_d6 () {
  local -i result=$(( RANDOM % 6 + 1))
  echo $result
}

pop_largest () {
  local -n __arr__=$1
  local -n __largest__=$2
  local -i value_of_largest=0 idx_of_largest=0

  for idx in "${!__arr__[@]}"; do
    if (( ${__arr__[$idx]} > value_of_largest )); then
      value_of_largest=${__arr__[$idx]}
      idx_of_largest=$idx
    fi
  done

  # shellcheck disable=SC2034
  remove_nth __arr__ "$idx_of_largest" && __largest__="$value_of_largest" || return 1
}

roll_for_ability () {
  local -n result=$1
  local -i total=0 number_added=0 largest=0 rc=1
  local rolls=()

  # Roll Four Die
  rolls+=("$( roll_d6 )")
  rolls+=("$( roll_d6 )")
  rolls+=("$( roll_d6 )")
  rolls+=("$( roll_d6 )")
  
  # Add the Largest Three
  while (( number_added < 3 )); do
    pop_largest rolls largest
    rc=$?; if (( rc > 0 )); then printf "error: failed to pop_largest\n" >&2; exit $rc; fi
    total+=$largest
    number_added+=1
  done
  
  result="$total"
}

calculate_modifier() {
  local constitution=$1
  local modifier
  local -i rc

  modifier=$(echo "scale=4; (($constitution - 10) / 2)" \
  | bc \
  | awk '{print ($1<0)? int($1 - 0.5): int($1) }')
  
  (( rc=$? )) && return "$rc" || printf "%d\n" "$modifier"
}

generate_character() {
  local -n __character__=$1
  local -i roll 

  local -a attributes=(strength dexterity intelligence wisdom charisma constitution)
  for attr in "${attributes[@]}"; do
    roll_for_ability roll
    # shellcheck disable=SC2034
    __character__["$attr"]=$roll
  done
  # shellcheck disable=SC2034
  __character__["hitpoints"]=$(( 10 + "$( calculate_modifier "${character[constitution]}" )" ))
}

main () {
  local command=$1
  local -i constitution=$2

  case $command in
    modifier)
     calculate_modifier "$constitution"
    ;;
    generate)
      declare -A character
      generate_character character
      for attr in "${!character[@]}"; do
        echo "$attr ${character[$attr]}"
      done
    ;;
  esac
}

main "$@"