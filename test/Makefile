#  SPDX-Creator-Person: Remo Dentato (rdentato@gmail.com)
#  SPDX-License-Identifier: MIT

_EXE=.exe
STATIC=-static

ifeq "$(COMSPEC)" ""
_EXE=
STATIC=
endif

CFLAGS=-O2 -Wall -I../src -fopenmp $(STATIC) -DDEBUG
LIBS=-lm

TESTS_SRC=$(wildcard t_*.c)
TESTS=$(TESTS_SRC:.c=)

# implicit rules
MAKEFLAGS += --no-builtin-rules

# targets

all: $(TESTS)

runtest: all
	@echo > test.out
	@for f in $(TESTS); do echo "TEST: $$f" >> test.out ; ./$$f 2>> test.out; done 
	@grep 'FAIL:' test.out

../src/tns.o: ../src/tns.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%: %.o ../src/tns.o 
	$(CC) $(CFLAGS) $< ../src/tns.o -o $* $(LIBS)

.PRECIOUS: %.o

clean:
	rm -f $(TESTS) $(TESTS:=.exe) $(TESTS:=.o) ../src/tns.o test.out
