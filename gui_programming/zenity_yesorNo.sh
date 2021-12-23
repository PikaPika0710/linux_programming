#bin/bash
zenity --question --text "This is a question!" --no-wrap
#0: yes, 1: true
if [[ $? = 0 ]]
then
	echo "You answered yes";
else 
	echo "You answered no";
fi
