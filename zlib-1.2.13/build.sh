rm -rf /workspace/zlib/zlib-1.2.13/out
mkdir /workspace/zlib/zlib-1.2.13/out
make clean
./configure --prefix=/workspace/zlib/zlib-1.2.13/out --shared  CFLAGS=-fPIC
make -j
cd ./contrib/minizip
rm -rf out
mkdir out
make clean
make
# make -f Makefile.gcc SHARED=1 PREFIX=./out CFLAGS="-I../zlib-1.2.13" LIBS="-L. -lminizip -L../zlib-1.2.13 -lz"
