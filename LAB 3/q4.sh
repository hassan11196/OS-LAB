
prime(){
num=$1
start=2
flag=0
((check=$num/2))
((check=$check+1))
echo $start
echo $check

while [[ $start < $check ]]
do
	echo $start
	if [[ $num%$start -eq 0 ]]
	then
		echo "Not Prime"
		flag=1
		break
	fi
	((start=$start+1))

done
if [[ $flag -eq 0 ]]
then
	echo "$num is Prime"
else
	echo "$num is NOT Prime"
fi
echo $start
}
read -p "Enter Any Positive Number  :" n
prime $n

