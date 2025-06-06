#!/usr/bin/env bash

roll_d6 () {
  printf "$(( $RANDOM % 6 + 1))"
}

roll_for_ability () {
  rolls=()
  rolls+=($( roll_d6 ))
  rolls+=($( roll_d6 ))
  rolls+=($( roll_d6 ))
  rolls+=($( roll_d6 ))

  declare -i total=0
  declare -i number_added=0
  local idx_of_largest=-1
  local value_of_largest=0
  
  # Get the Largest Three
  while [[ number_added -lt 3 ]]; do
    for idx in ${!rolls[@]}; do
      if [[ ${rolls[$idx]} -gt $value_of_largest ]]; then
        idx_of_largest=$idx
        value_of_largest=${rolls[$idx]}
      fi
    done
    
    total+=value_of_largest
    value_of_largest=0
    idx_of_largest=0

    rolls[$idx]=0

    number_added+=1
  done
  printf "$total"
}

calculate_modifier() {
  local constitution=$1
  echo "scale=4; (($constitution - 10) / 2)" \
  | bc \
  | awk '{print ($1<0)? int($1 - 0.5): int($1) }'
}

main () {
  case $1 in
    modifier)
      calculate_modifier $2
    ;;
    generate)
      declare -A character
      character[strength]=$(roll_for_ability)
      character[dexterity]=$(roll_for_ability)
      character[constitution]=$(roll_for_ability)
      character[intelligence]=$(roll_for_ability)
      character[wisdom]=$(roll_for_ability)
      character[charisma]=$(roll_for_ability)
      character[hitpoints]=$(( 10 + "$( calculate_modifier ${character[constitution]} )"  ))

      for attr in "${!character[@]}"; do
        echo "$attr ${character[$attr]}"
      done
    ;;
  esac

  return 0
}

main "$@"