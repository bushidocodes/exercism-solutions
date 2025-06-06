#!/usr/bin/env bash

main () {
    echo $(date --date @"$(( $(date --date="$1" +"%s") + 1000000000 ))" '+%Y-%m-%dT%H:%M:%S')
    return 0;
}

main "$@"
