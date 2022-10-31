GCC=gcc -ggdb -Wall -lm

.PHONY: clean

main.o: main.c
	$(GCC) -c $<

main: main.o
	$(GCC) -lcheck -o ./bin/main $^
	./bin/main

clean:
	rm -f *.o
