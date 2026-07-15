#!/bin/bash

clear

read -p "Language: " language

clear

read -p "Query: " query

curl cht.sh/$language/`echo $query | tr ' ' '+'`
