./my_tar -cf small.tar dummyfile01.txt dummyfile02.txt dummyfile03.txt
rm dummyfile01.txt dummyfile02.txt dummyfile03.txt
#./my_tar -xf small.tar
tar -xf small.tar

tar -cf smallz.tar dummyfile01.txt dummyfile02.txt dummyfile03.txt
rm dummyfile01.txt dummyfile02.txt dummyfile03.txt
./my_tar -xf smallz.tar