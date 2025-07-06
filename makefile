build-singly: ./src/singlylinkedlist.c
	gcc -c ./src/singlylinkedlist.c -o ./build/objects/singlylinkedlist.o
build-singly-test: ./tests/singly_tests.c ./src/singlylinkedlist.c
	gcc -g ./tests/singly_tests.c ./src/singlylinkedlist.c -o ./build/tests/singly_tests.exe
singly-test:
	./build/tests/singly_tests.exe
