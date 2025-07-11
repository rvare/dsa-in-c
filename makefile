build-singly: ./src/singly_linked_list.c
	gcc -c ./src/singly_linked_list.c -o ./build/objects/singly_linked_list.o
build-singly-test: ./tests/singly_tests.c ./src/singly_linked_list.c
	gcc -g ./tests/singly_tests.c ./src/singly_linked_list.c -o ./build/tests/singly_tests.exe
singly-test:
	./build/tests/singly_tests.exe
build-doubly: ./src/doubly_linked_list.c
	gcc -c ./src/doubly_linked_list.c -o ./build/objects/doubly_linked_list.o
build-doubly-test: ./tests/doubly_tests.c ./src/doubly_linked_list.c
	gcc -g ./tests/doubly_tests.c ./src/doubly_linked_list.c -o ./build/tests/doubly_tests.exe
doubly-test:
	./build/tests/doubly_tests.exe
build-stack: ./src/stack.c
	gcc -c ./src/stack.c -o ./build/objects/stack.o
build-stack-test: ./tests/stack_tests.c ./src/stack.c
	gcc -g ./tests/stack_tests.c ./src/stack.c -o ./build/tests/stack_tests.exe
stack-test:
	./build/tests/stack_tests.exe
