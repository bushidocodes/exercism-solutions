#!/usr/bin/env bash

compare() {
  local line=$1
  local pattern=$2
  local -n _options=$3
  does_match=false

  if ${_options["case_insensitive"]}; then
    line="${line,,}"
    pattern="${pattern,,}"
  fi

  if ${_options["entire_lines"]} && [[ "$line" = "$pattern" ]]; then
    does_match=true
  elif ! ${_options["entire_lines"]} && [[ "$line" = *"$pattern"* ]]; then
    does_match=true
  else
    does_match=false
  fi

  if $does_match; then
    ${options["invert"]} && return 1
    return 0
  else
    ${options["invert"]} && return 0
    return 1
  fi
}

main() {
  declare -A options=(
    ["line_numbers"]=false
    ["file_names"]=false
    ["case_insensitive"]=false
    ["invert"]=false
    ["entire_lines"]=false
  )

  while true; do
    case $1 in
      -n)
        options["line_numbers"]=true
        ;;
      -l)
        options["file_names"]=true
        ;;
      -i)
        options["case_insensitive"]=true
        ;;
      -v)
        options["invert"]=true
        ;;
      -x)
        options["entire_lines"]=true
        ;;
      *)
        break
        ;;
    esac
    shift
  done

  local pattern=$1
  shift
  declare -a files=("$@")

  for file in "${files[@]}"; do
    local -i line_no=1
    while read -r line; do
      if compare "$line" "$pattern" options; then
        if ${options["file_names"]}; then
          echo "$file"
          break
        else
          ((${#files[@]} > 1)) && printf "%s:" "$file"
          ${options["line_numbers"]} && printf "%d:" "$line_no"
          echo "$line"
        fi
      fi
      ((line_no += 1))
    done <"$file"
  done

}

main "$@"
