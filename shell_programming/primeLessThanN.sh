#Khong the dat ten bien trung nhau trong shell script
#Hoac co the su dung local variables
#!/bin/sh
isPrime(){
      n=$1
      i=2
      if [ $n -eq 0 -o $n -eq 1 ]
      then return 0
      fi
      while [ $i -lt $n ]
      do
                k=$(($n%$i))
                if [ $k -eq 0 ] 
                        then return 0
                fi
                i=$(($i+1))               
        done 
        return 1
      
}
listAllPrime(){
        m=$1
        e=0
        while [ $e -lt $m ]
        do
                isPrime $e
                if [ $? -eq 1 ]  
                then 
                        echo "$e "
                fi
                e=$(($e+1))
         done      
}

read -p "Nhap so: " m
listAllPrime $m  
exit 0
