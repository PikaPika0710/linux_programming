#!/bin/sh
touch file_one
rm -f file_two
if [ -f file_one ] && echo “hello” && [ -f file_two ] && echo “there”
then
echo “in if”
fi
exit 0
