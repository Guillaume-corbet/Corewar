#!/bin/bash

SUCCESS=0
FAILS=0
RETFAIL=0

if [[ $(test -f ref ; echo $?) = 1 || $(test -f asm ; echo $?) = 1 ]]
then
    printf "You must have your asm and the ref asm (named \"ref\") in the directory\n"
    exit 84
fi

$(rm -rf ./*.cor)

for file in "./champ"/*.s
do
    $(./asm "$file")
    if [ $? -ne 0 ]
    then
        ((RETFAIL+=1))
	printf "Bad return at: $file\n"
    fi
done

for file in "."/*.cor
do
    hexdump -C "$file" > "my_"$(echo "$file" | cut -d '/' -f 2 | cut -d '.' -f 1)
    $(rm -rf "$file")
done

for file in "./champ"/*.s
do
    $(./ref "$file")
done

for file in "."/*.cor
do
    hexdump -C "$file" > "ref_"$(echo "$file" | cut -d '/' -f 2 | cut -d '.' -f 1)
    $(rm -rf "$file")
done

for file in "."/ref_*
do
    $(diff "$file" "./my_"$(echo "$file" | cut -b7-) > /dev/null)
    if [ $? -eq 0 ]
    then
        ((SUCCESS+=1))
    else
        ((FAILS+=1))
	printf "Failed on: $file\n"
    fi
done

$(rm -rf my_* ref_*)

echo -e "SUCCESS: $SUCCESS"
echo -e "FAILS  : $FAILS"
echo -e "RETFAIL: $RETFAIL"
