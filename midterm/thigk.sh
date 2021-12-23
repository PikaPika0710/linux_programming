#!/bin/sh
echo "**************************************************************************************"
echo "* Bai thi giua ky mon: Lap trinh tren Linux                                                                                   "
echo "* Ho va ten: Tran Cong Viet                                                                                                              "
echo "* Nhom:  19Nh10                                                                                                                                "
echo "* Masv:  102190298                                                                                                                            "
echo "* De so: 01                                                                                                                                            "
echo "**************************************************************************************"

if [ $# -eq 0 ]
	then 
		echo "Khong co tham so dong lenh"

elif [ $# -eq 1 ]
	then
		if [ -f  "$1" ]
			then
			        echo "$1 is a file"
			        echo "=======MAIN MENU========"
                                        echo "Chon cac phuong an sau: "
                                        echo "s or S: Sap xep file actor_movies.txt" 
                                        echo "t or T: Tim dien vien"
                                        echo "q or Q: Thoat!!"
                                        while [ true ]
                                                do
                                                        echo "Moi ban chon: \c"
                                                        read option
                                                        
                                                        case "$option" in
                                                                s|S)  #sap xep theo thu tu tang dan cua ten dien vien, dan xuat ra actor.txt
                                                                sort $1 > actor.txt;;         
                                                                t|T)  #nhap ten dien vien, in ra tat ca phim dien vien do dong movies.txt
                                                                echo -n "Nhap ten dien vien: "
                                                                read name
                                                                grep "$name" $1  > movies.txt ;;
                                                                q|Q) echo "Goodbye"
                                                                         exit 0 ;;
                                                                *)   echo "Khong hop le!"
                                                                        exit 1;;     
                                                        esac
                                        done
		elif [ -d "$1" ]
			then
				echo "$1 is a directory"
		else
			echo "$1: file not found"
		fi
fi


