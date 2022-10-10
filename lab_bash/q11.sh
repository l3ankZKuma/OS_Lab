fn="progA.c progB.c progC.c"
for f in $fn
do
	    fname=$(echo $i | cut -d'.' -f1)
	    gcc -o $fname $i |& grep -i 'warning' $i 2>/dev/nul
	    if [ -f progA]
	    then
		    ans=10
		    rm $fname
	    elif [-f progB]
	    then
		    ans=7
		    rm $fname
	    else
		    ans=5
            fi
	    printf "%s\t%s\n" $f $ans
done
