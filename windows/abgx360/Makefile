# abgx360 CLI

CC       = gcc
OBJ      = abgx360.o fnmatch.o rijndael-alg-fst.o sha1.o mspack/lzxd.o mspack/system.o
LINKOBJ  = abgx360.o fnmatch.o rijndael-alg-fst.o sha1.o mspack/lzxd.o mspack/system.o
LIBS     = -L"lib" -L"lib/gcc" -static-libgcc libcurl-7.19.6.a libssh2.a libssl.a libcrypto.a libidn.a libz.a -lws2_32 -lwinmm -lwldap32 -lgdi32  
INCS     = -I"include" 
BIN      = abgx360.exe
CFLAGS   = $(INCS) -DCURL_STATICLIB   -std=gnu99
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before abgx360.exe all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o "abgx360.exe" $(LIBS)

abgx360.o: abgx360.c
	$(CC) -c abgx360.c -o abgx360.o $(CFLAGS)

fnmatch.o: fnmatch.c
	$(CC) -c fnmatch.c -o fnmatch.o $(CFLAGS)

rijndael-alg-fst.o: rijndael-alg-fst.c
	$(CC) -c rijndael-alg-fst.c -o rijndael-alg-fst.o $(CFLAGS)

sha1.o: sha1.c
	$(CC) -c sha1.c -o sha1.o $(CFLAGS)

mspack/lzxd.o: mspack/lzxd.c
	$(CC) -c mspack/lzxd.c -o mspack/lzxd.o $(CFLAGS)

mspack/system.o: mspack/system.c
	$(CC) -c mspack/system.c -o mspack/system.o $(CFLAGS)
