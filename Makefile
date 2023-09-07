all:
	gcc main.c function.c -o main

clean:
	rm -rf *.o main

tests:
	make
	echo "\nExec test 1\n"
	./main test1.txt
	echo "\nExec test 2\n"
	./main test2.txt
	echo "\nExec test 3\n"
	./main test3.txt
	echo "\nExec test 4\n"
	./main test4.txt
	make clean