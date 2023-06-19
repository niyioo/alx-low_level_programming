#!/bin/bash
c_files=$(ls *.c)
for file in $c_files; do
    gcc -c -fPIC "$file" -o "${file%.c}.o"
done
gcc -shared -o liball.so *.o
rm *.o
