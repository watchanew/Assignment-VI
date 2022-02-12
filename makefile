compile: main.c
	 gcc  main.c -o a.out


run: a.out
	 ./a.out


clean: a.out
	 rm a.out