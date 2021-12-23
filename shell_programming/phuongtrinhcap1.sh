#!/bin/bash
echo -n "Nhap a: "
read a
echo -n "Nhap b: "
read b
if [ $a -eq 0 -a $b -eq 0 ] 
then 
        echo "Phuong trinh vo so nghiem"
elif [ $a -eq 0 -a $b != 0 ]
then
        echo "Phuong trinh khong co nghiem"
else     
        k=$(echo "scale=2; (- $b / $a)"|bc)
        echo "Nghiem cua phuong trinh la: $k"
fi
exit 0
