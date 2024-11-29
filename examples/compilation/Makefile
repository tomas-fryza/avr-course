app.out: main.o compute.o
	gcc main.o compute.o -o app.out

main.o:
	gcc -c -Wall main.c

compute.o:
	gcc -c -Wall compute.c

clean:
	rm -f main.o compute.o app.out *.s
