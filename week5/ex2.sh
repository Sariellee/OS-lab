n=0
while [[ $n != 10 ]]; do
	# critical region start

	if ln ex2.txt ex2.txt.lock 
	then
		res=$(tail -1 ex2.txt)
		res=$((res+1))
		n=$((n+1))
		echo $res
		echo $res >> ex2.txt
		rm 'ex2.txt'.lock
 	else
 		sleep 0.1
	fi

	#critical region stop	
done