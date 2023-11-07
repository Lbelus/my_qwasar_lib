./my_tar -cf small.tar dummyfile01.txt dummyfile02.txt dummyfile03.txt
./my_tar -uf small.tar dummyfile04.txt


tar -cf smallz.tar dummyfile01.txt dummyfile02.txt dummyfile03.txt
tar -uf smallz.tar dummyfile04.txt


diff -a small.tar smallz.tar