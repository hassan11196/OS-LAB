
fibo(){
	temp=$1
	a=0
	b=1
	c=0
	while [[ temp -gt 0 ]]
	do 
	echo "$a"
	((c=$a+$b))
	((a=$b))
	((b=$c))
		((temp=$temp-1))
	done
	
}

read -p "Enter Num For Fibonacci: " num
fibo $num
