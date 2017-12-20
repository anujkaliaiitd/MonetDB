#sudo rm -rf /usr/local/var/monetdb5/
make clean
./bootstrap
#./configure --enable-strict=no --enable-debug=yes
./configure --enable-strict=no --enable-debug=no --enable-assert=no  --enable-optimize=yes
make -j
sudo make install
