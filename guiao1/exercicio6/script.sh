#!/usr/bin/bash

for((k = 0 ; k <1000; k++))
do 
    echo `./pessoas -i "User.$k" "$k/$k/$k" `
done
