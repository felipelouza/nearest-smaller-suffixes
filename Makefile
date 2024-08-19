CC = g++
CFLAGS += -Wall -std=c++17 
#CFLAGS += -g -O0
CFLAGS += -D_FILE_OFFSET_BITS=64 -m64 -O3 -fomit-frame-pointer -Wno-char-subscripts 

LFLAGS = -lm -lrt -ldl


LIBOBJ = \
	benchmark/external/malloc_count/malloc_count.o
	
all: main.cpp ${LIBOBJ} 
	$(CC) -o la-plain main.cpp ${LIBOBJ} $(CFLAGS) $(LFLAGS) 

clean:
	\rm -f *.o benchmark/external/malloc_count/malloc_count.o la-plain 


