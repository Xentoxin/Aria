test: aria.o parser.o aria_sh.o exec.o
	gcc -g -o test aria.o parser.o aria_sh.o exec.o

aria.o: aria.c aria.h
	gcc -c aria.c

parser.o: ./parser/parser.c ./parser/parser.h
	gcc -c ./parser/parser.c

aria_sh.o: ./aria_sh/aria_sh.c ./aria_sh/aria_sh.h
	gcc -c ./aria_sh/aria_sh.c

exec.o: ./exec/exec.c ./exec/exec.h
	gcc -c ./exec/exec.c

run: test
	./test

clean:
	rm *.o
