#!/bin/bash
echo -n "Nhap a: "
read a
echo -n "Nhap b: "
read b
echo -n "Nhap c: "
read c
delta=$(($b*$b - 4*$a*$c))
if [ $delta -lt 0 ]
then 
        echo "Phuong trinh vo nghiem"
elif [ $delta -eq 0 ]
then
        x=$(echo "scale=2; ( - $b / (2*$a))"|bc)
        echo "Phuong trinh co nghiem x1 = x2 = $x"
else
        x1=$(echo "scale=2; ((- $b + sqrt($delta)) / (2*$a))"|bc)
        x2=$(echo "scale=2; ((- $b  - sqrt($delta)) / (2*$a))"|bc)
        echo "Phuong trinh co nghiem x1 = $x1"
        echo "Phuong trinh co nghiem x2 = $x2"
fi
