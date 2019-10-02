#!/bin/bash

cat $1 | ./secret_cypher -e $(cat key.txt) > cyphertexts.txt
