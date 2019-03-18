factorial(){
	temp=$1
	fact=1
	while [[ temp -gt 0 ]]
	do 
		((fact=$fact*temp))
		((temp=$temp-1))
	done
	echo "Factorial of $1 is $fact"
}

read -p "Enter Num For Factorial: " num
factorial $num
