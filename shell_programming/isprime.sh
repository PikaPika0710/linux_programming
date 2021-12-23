#!/bin/sh
isprime(){
        i=2
        n=$1
        if [ $n -eq 0 -o  $n -eq 1 ]
        then
                return 0
        fi
        while [ $i -lt $n ] 
        do
                k=$(($n%$i))
                if [ $k -eq 0 ] 
                then
                        return 0
                fi
                i=$(($i+1))
        done
        return 1
        
}

read -p "Nhap so: " m
isprime $m
if [ $? -eq 1 ] 
then
        echo "$m la so nguyen to"
else
        echo "$m khong la so nguyen to"

fi
exit 0



