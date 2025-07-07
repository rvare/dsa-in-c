build-singly: ./src/singly_linked_list.c
	gcc -c ./src/singly_linked_list.c -o ./build/objects/singly_linked_list.o
build-singly-test: ./tests/singly_tests.c ./src/singly_linked_list.c
	gcc -g ./tests/singly_tests.c ./src/singly_linked_list.c -o ./build/tests/singly_tests.exe
singly-test:
	./build/tests/singly_tests.exe
