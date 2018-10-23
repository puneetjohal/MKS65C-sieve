all: driver.o sieve.o
	gcc driver.o

run:
	./primetest $(args)

driver.o: driver.c
	gcc -c driver.c

sieve.o: sieve.c sieve.h
	gcc -c sieve.c

clean:
	rm *.o

debug: driver.c sieve.c sieve.h
	gcc -g -c driver.c sieve.h sieve.c
	gcc -g driver.o
