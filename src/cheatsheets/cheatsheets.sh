#!/bin/bash

echo "-- cheat --"

read -p "Language: " language
read -p "Query: " query

curl cht.sh/$language/`echo $query | tr ' ' '+'`

echo "-- cheat --"
