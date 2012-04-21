all: ARITH PALIN-1 PALIN-2

test: ARITH.test PALIN-2.test

ARITH: ARITH.c
	gcc ARITH.c -std=c99 -strict -o ARITH

ARITH.test: ARITH
	./ARITH < ARITH.test.input

PALIN-1: PALIN-1.c
	gcc PALIN-1.c -std=c99 -strict -o PALIN-1

PALIN-2: PALIN-2.c
	gcc PALIN-2.c -std=c99 -strict -o PALIN-2

PALIN-2.test: PALIN-2
	./PALIN-2 < PALIN.test.input | diff -y - PALIN.test.should
