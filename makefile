all:mainIsort mainTxt

mainIsort: isort.o
	gcc -Wall isort.o -o mainIsort

mainTxt: txtfind.o
	gcc -Wall txtfind.o -o mainTxt

isort.o: isort.c
	gcc -Wall -c isort.c -o isort.o

txtfind.o: txtfind.c
	gcc -Wall -c txtfind.c -o txtfind.o
	
.PHONY: clean all

clean: 
	rm *.o -f mains
