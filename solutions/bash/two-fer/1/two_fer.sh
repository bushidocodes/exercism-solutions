#!/usr/bin/env bash

main () {
    local name=${1:-"you"}
    printf "One for %s, one for me.\n" "$name"
    return 0
}

main "$@"
