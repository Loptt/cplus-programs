#!/bin/bash

if [ "$#" -ne 3 ]; then
    echo "Illegal number of parameters"
    exit 1
fi

paste -d'\0' <(awk -f separate_commas.awk < $1) <(awk -f separate_commas.awk < $2 | sed s'/..$//') > $3