build-singly: ./src/singlylinkedlist.c
	gcc -c ./src/singlylinkedlist.c -o ./build/objects/singlylinkedlist.o
build-singly-test: ./tests/singly_tests.c ./build/objects/singlylinkedlist.o
	gcc ./tests/singly_tests.c ./build/objects/singlylinkedlist.o -o ./build/tests/singly_tests.exe
singly-test:
	./build/tests/singly_tests.exe
