#!/bin/sh
secretcode=agent007
until [ "$secretcode" = "$yourguess" ]
	do
		clear
		echo "Guess the code"
		echo "Enter your guess: \c"
		read yourguess
done
echo "Wow! You are a genius"
exit 0

