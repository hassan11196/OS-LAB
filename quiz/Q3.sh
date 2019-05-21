factorial(){
	temp=1
	fact=$num
	while [[ temp -lt 10 ]]
	do 
		((ans=$fact*temp))
		echo "$fact * $temp = $ans"
		((temp=$temp+1))
	done
	
}

echo "table of 5: " 
num=5
factorial $num
echo "table of 6: " 
num=6
factorial $num
echo "table of 8: " 
num=8
factorial $num

