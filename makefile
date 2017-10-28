all: randfile.c
	gcc randfile.c

run: all
	./a.out

clean:
	rm foo
	rm *.out
	rm *~

