read -p "Enter Num : " num
max=$num
min=$num


for i in {2..5}
do
read -p "Enter $i th number : " num
if [[ $max -lt $num ]]
then
	max=$num
fi
if [[ $min -gt $num ]] 
then 
	min=$num
fi

done
echo "MAX : $max"
echo "MIN : $min"
