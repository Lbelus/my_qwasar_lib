./my_tar -cf small.tar dummyfile01.txt dummyfile02.txt dummyfile03.txt
./my_tar -rf small.tar dummyfile01.txt dummyfile02.txt

tar -cf smallz.tar dummyfile01.txt dummyfile02.txt dummyfile03.txt
tar -rf smallz.tar dummyfile01.txt dummyfile02.txt

diff -a small.tar smallz.tar

tar -tf smallz.tar >> checkoutput_tar.txt
./my_tar -tf small.tar >> checkoutput_mytar.txt

diff -a checkoutput_tar.txt checkoutput_mytar.txt
rm checkoutput_tar.txt checkoutput_mytar.txt