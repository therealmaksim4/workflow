#!/bin/bash

clear

languages=`echo "c cpp python" | tr ' ' '\n'`

selected=`printf "$languages" | fzf`
read -p "Query: " query

curl cht.sh/$selected/`echo $query | tr ' ' '+'`
