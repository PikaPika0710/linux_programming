#!/bin/bash
declare -a arr
echo -n "Nhap n: "
read n
for ((i=0;i<n;i++))
do
        echo -n "arr[$i] = "
        read m
        arr[$i]=$m
done
echo "Mang chua sap xep:"
echo ${arr[*]}

for ((j=0;j<n-1;j++))
do
        for ((k=j+1; k<n; k++))
        do
                if [ ${arr[$k]} -lt ${arr[$j]} ]
                then 
                temp=${arr[$k]}
                arr[$k]=${arr[$j]}
                arr[$j]=$temp
                fi
        done
done
echo "Mang sau khi duoc sap xep: "
echo ${arr[*]}
exit 0
