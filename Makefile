# Makefile
# Řešení IJC-DU2, příklad 1),2)
# Datum: 20.4.2020
# Autor: Václav Sysel,VUT FIT
# Přeloženo: gcc 7.5.0
#

CFLAGS = -std=c99 -pedantic -Wall -Wextra
C+FLAGS = -std=c++17 -pedantic -Wall
LIBMOD = htab_begin.o htab_bucket_count.o htab_clear.o htab_end.o htab_erase.o htab_find.o htab_free.o htab_hash_fun.o htab_init.o htab_iterator_equal.o htab_iterator_get_key.o htab_iterator_get_value.o htab_iterator_next.o htab_iterator_set_value.o htab_iterator_valid.o htab_lookup_add.o htab_size.o


#main files
#========================

all: tail wordcount wordcount-dynamic

tail: tail.o
	gcc $(CFLAGS) tail.o -o tail

wordcount: CFLAGS := $(filter-out -fPIC,$(CFLAGS))
wordcount: libhtab.a wordcount.c htab.h io.o
	gcc $(CFLAGS) -o wordcount wordcount.c io.o -static -L. -lhtab

wordcount-dynamic: htab.h wordcount.c io.o libhtab.so
	gcc $(CFLAGS) -o wordcount-dynamic wordcount.c -L. -lhtab io.o

#static library
#========================
libhtab.a: CFLAGS += -fPIC
libhtab.a: htab.h htab_structs.h $(LIBMOD)
	ar crs libhtab.a htab_begin.o htab_bucket_count.o htab_clear.o htab_end.o htab_erase.o htab_find.o htab_free.o htab_hash_fun.o htab_init.o htab_iterator_equal.o htab_iterator_get_key.o htab_iterator_get_value.o htab_iterator_next.o htab_iterator_set_value.o htab_iterator_valid.o htab_lookup_add.o htab_size.o

#dynamic library
#========================
libhtab.so: CFLAGS += -fPIC
libhtab.so: htab.h htab_structs.h $(LIBMOD)
	gcc -shared $(CFLAGS) $(LIBMOD) -o libhtab.so

#library modules
#========================

htab_begin.o: htab.h htab_structs.h htab_begin.c
	gcc $(CFLAGS) -O2 -c htab_begin.c

htab_bucket_count.o: htab.h htab_structs.h htab_bucket_count.c
	gcc $(CFLAGS) -O2 -c htab_bucket_count.c

htab_clear.o: htab.h htab_structs.h htab_clear.c
	gcc $(CFLAGS) -O2 -c htab_clear.c

htab_end.o: htab.h htab_structs.h htab_end.c
	gcc $(CFLAGS) -O2 -c htab_end.c

htab_erase.o: htab.h htab_structs.h htab_erase.c
	gcc $(CFLAGS) -O2 -c htab_erase.c

htab_find.o: htab.h htab_structs.h htab_find.c
	gcc $(CFLAGS) -O2 -c htab_find.c

htab_free.o: htab.h htab_structs.h htab_free.c
	gcc $(CFLAGS) -O2 -c htab_free.c

htab_hash_fun.o: htab.h htab_hash_fun.c
	gcc $(CFLAGS) -O2 -c htab_hash_fun.c

htab_init.o: htab.h htab_structs.h htab_init.c
	gcc $(CFLAGS) -O2 -c htab_init.c

htab_iterator_equal.o: htab.h htab_iterator_equal.c
	gcc $(CFLAGS) -O2 -c htab_iterator_equal.c

htab_iterator_valid.o: htab.h htab_iterator_valid.c
	gcc $(CFLAGS) -O2 -c htab_iterator_valid.c

htab_iterator_get_key.o: htab.h htab_structs.h htab_iterator_get_key.c
	gcc $(CFLAGS) -O2 -c htab_iterator_get_key.c

htab_iterator_get_value.o: htab.h htab_structs.h htab_iterator_get_value.c
	gcc $(CFLAGS) -O2 -c htab_iterator_get_value.c

htab_iterator_set_value.o: htab.h htab_structs.h htab_iterator_set_value.c
	gcc $(CFLAGS) -O2 -c htab_iterator_set_value.c

htab_iterator_next.o: htab.h htab_structs.h htab_iterator_next.c
	gcc $(CFLAGS) -O2 -c htab_iterator_next.c

htab_lookup_add.o: htab.h htab_structs.h htab_lookup_add.c
	gcc $(CFLAGS) -O2 -c htab_lookup_add.c

htab_size.o: htab.h htab_structs.h htab_size.c
	gcc $(CFLAGS) -O2 -c htab_size.c

#dynamic library
#========================
#libhtab.so

#binary files
#========================
tail.o: tail.c
	gcc $(CFLAGS) -c tail.c

io.o: io.c io.h
	gcc $(CFLAGS) -c -O2 io.c

#files needed for learning
#========================
original: wordcount-cc

wordcount-: wordcount-cc.cc
	g++ -std=c++11 -O2 wordcount-.cc -o wordcount-

#other commands
#========================
debug: CFLAGS += -g
debug: all

clean:
	rm *.o *.a *.so tail wordcount wordcount-dynamic
