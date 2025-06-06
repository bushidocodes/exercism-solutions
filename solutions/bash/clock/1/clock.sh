#!/usr/bin/env bash
main() {
  declare -i hours=$1
  declare -i minutes=$2
  declare operator=$3
  declare -i delta=$4

  # Validate Input
  if { (($# != 2)) && (($# != 4)); } ||                   # Not 2 or 4 paramesters
    ! [[ $1 =~ ^[-0-9]+$ ]] || ! [[ $2 =~ ^[-0-9]+$ ]] || # 1st and 2nd parameters are non-numeric
    {
      (($# > 2)) &&
        ! { [[ $3 =~ ^[-+]+$ ]] && [[ $4 =~ ^[-0-9]+$ ]]; } # Optional 3rd param not +/- and 4th param not numeric
    }; then
    echo "invalid arguments" >&2
    exit 1
  fi

  # Optionally apply delta
  if (($# > 2)); then
    [[ "$operator" == "-" ]] && ((delta *= -1))
    ((hours += delta / 60))
    ((minutes += delta % 60))
  fi

  # Add whole hours from minutes
  ((hours += (minutes / 60)))
  ((minutes %= 60))

  # drop whole days since we aren't tracking them
  ((hours %= 24))

  # If minutes are negative, borrow an hour
  if ((minutes < 0)); then
    ((hours -= 1))
    ((minutes += 60))
  fi

  # If Hours are negative, wrap around
  ((hours < 0)) && ((hours += 24))

  printf "%.2d:%.2d\n" "$hours" "$minutes"
}

main "$@"
