#!/bin/bash
FILES=*
for f in $FILES
do
  echo $f
  g++ $f
done
