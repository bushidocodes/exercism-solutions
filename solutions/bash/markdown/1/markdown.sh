#!/usr/bin/env bash

process_em() {
  local -n __process_em_line=$1
  while [[ $__process_em_line == *_*?_* ]]; do
    one=${__process_em_line#*_}
    two=${one#*_}
    if [ ${#two} -lt ${#one} ] && [ ${#one} -lt ${#__process_em_line} ]; then
      __process_em_line="${__process_em_line%%_$one}<em>${one%%_$two}</em>$two"
    fi
  done
}

process_strong() {
  local -n __process_strong_line=$1
  local orig=""
  while [ "$__process_strong_line" != "$orig" ]; do
    orig=$line
    if [[ $line =~ ^(.+)__(.*) ]]; then
      post=${BASH_REMATCH[2]}
      pre=${BASH_REMATCH[1]}
      if [[ $pre =~ ^(.*)__(.+) ]]; then
        printf -v __process_strong_line "%s<strong>%s</strong>%s" "${BASH_REMATCH[1]}" "${BASH_REMATCH[2]}" "$post"
      fi
    fi
  done
}

process_line() {
  line=$1
  local -n __result=$2
  local -n __inside_a_list=$3

  process_strong line
  process_em line

  if [[ $line =~ ^\* ]]; then
    # Open List if needed
    if [ "$__inside_a_list" != "true" ]; then
      __result+="<ul>"
      __inside_a_list="true"
    fi

    __result+="<li>${line#??}</li>"
    return 0
  elif [ "$__inside_a_list" = "true" ]; then
    __result+="</ul>"
    __inside_a_list="false"
  fi

  # Close List if needed
  if [ "$__inside_a_list" = "true" ]; then
    __result+="</ul>"
    __inside_a_list="false"
  fi

  # If a heading
  npounds=$(expr "$line" : "#\{1,\}")
  if ((npounds > 0)); then

    # Strip Pound Signs and leading whitespace
    HEAD=${line:npounds}
    while [[ $HEAD == " "* ]]; do
      HEAD=${HEAD# }
    done
    __result+="<h$npounds>$HEAD</h$npounds>"

    return 0
  fi

  # Otherwise it's a paragraph
  grep '_..*_' <<<"$line" >/dev/null && line=$(echo "$line" | sed -E 's,_([^_]+)_,<em>\1</em>,g')
  __result+="<p>$line</p>"
}

main() {
  local inside_a_list="false"
  local orig
  local result

  while IFS= read -r line; do
    process_line "$line" result inside_a_list
  done \
    <"$1"

  [ "$inside_a_list" = "true" ] && result+="</ul>"

  echo "$result"
}

main "$@"
