#!/usr/bin/env bash

roll_d6() {
  local -i result=$((RANDOM % 6 + 1))
  echo $result
}

remove_smallest() {
  local -n __arr__=$1
  local -i value_of_smallest=7 idx_of_smallest=0

  for idx in "${!__arr__[@]}"; do
    if ((${__arr__[$idx]} < value_of_smallest)); then
      value_of_smallest=${__arr__[$idx]}
      # shellcheck disable=SC2034
      idx_of_smallest=$idx
    fi
  done

  unset "__arr__[idx_of_smallest]" || return 1
}

sum() {
  local -n __arr__=$1
  local -i sum=0
  for num in "${__arr__[@]}"; do
    sum+=$num
  done
  printf "%d" "$sum"
}

roll_for_ability() {
  local -i total=0 rc=1
  local rolls=()

  # Roll Four Die
  rolls+=("$(roll_d6)")
  rolls+=("$(roll_d6)")
  rolls+=("$(roll_d6)")
  rolls+=("$(roll_d6)")

  # Remove the smallest
  remove_smallest rolls

  # Add the remaining
  total=$(sum rolls)

  printf "%d" "$total"
}

calculate_modifier() {
  local constitution=$1
  local modifier
  local -i rc

  modifier=$(echo "scale=4; (($constitution - 10) / 2)" |
    bc |
    awk '{print ($1<0)? int($1 - 0.5): int($1) }')

  ((rc = $?)) && return "$rc" || printf "%d\n" "$modifier"
}

generate_character() {
  local -n __character__=$1
  local -i roll

  local -a attributes=(strength dexterity intelligence wisdom charisma constitution)
  for attr in "${attributes[@]}"; do
    roll=$(roll_for_ability)
    # shellcheck disable=SC2034
    __character__["$attr"]=$roll
  done
  # shellcheck disable=SC2034
  __character__["hitpoints"]=$((10 + "$(calculate_modifier "${character[constitution]}")"))
}

main() {
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
