
#/bin/bash/
for dir in */ ; 
do
	echo "erasing directory $dir"
	rm -rf $dir
done

