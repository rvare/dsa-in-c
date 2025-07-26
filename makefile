SRCDIR=./src
OBJDIR=./build/objects
TESTSDIR=./tests
TESTSOBJDIR=./build/tests

CFLAGS=-c -Wall
CDEBUG=-g -Wall

build-singly: $(SRCDIR)/singly_linked_list.c
	gcc $(CFLAGS) $(SRCDIR)/singly_linked_list.c -o $(OBJDIR)/singly_linked_list.o

build-singly-test: $(TESTSDIR)/singly_tests.c $(SRCDIR)/singly_linked_list.c
	gcc $(CDEBUG) $(TESTSDIR)/singly_tests.c $(SRCDIR)/singly_linked_list.c -o $(TESTSOBJDIR)/singly_tests.exe

singly-test: $(TESTSOBJDIR)/singly_tests.exe
	$(TESTSOBJDIR)/singly_tests.exe

build-doubly: $(SRCDIR)/doubly_linked_list.c
	gcc $(CFLAGS) $(SRCDIR)/doubly_linked_list.c -o $(OBJDIR)/doubly_linked_list.o

build-doubly-test: $(TESTSDIR)/doubly_tests.c $(SRCDIR)/doubly_linked_list.c
	gcc $(CDEBUG) $(TESTSDIR)/doubly_tests.c $(SRCDIR)/doubly_linked_list.c -o $(TESTSOBJDIR)/doubly_tests.exe

doubly-test: $(TESTSOBJDIR)/doubly_tests.exe
	$(TESTSOBJDIR)/doubly_tests.exe

build-stack: $(SRCDIR)/stack.c
	gcc $(CFLAGS) $(SRCDIR)/stack.c -o $(OBJDIR)/stack.o

build-stack-test: $(TESTSDIR)/stack_tests.c $(SRCDIR)/stack.c
	gcc $(CDEBUG) $(TESTSDIR)/stack_tests.c $(SRCDIR)/stack.c -o $(TESTSOBJDIR)/stack_tests.exe

stack-test:
	$(TESTSOBJDIR)/stack_tests.exe

build-queue: $(SRCDIR)/queue.c
	gcc $(CFLAGS) $(SRCDIR)/queue.c -o $(OBJDIR)/queue.o

build-queue-test: $(TESTSDIR)/queue_tests.c $(SRCDIR)/queue.c
	gcc $(CDEBUG) $(TESTSDIR)/queue_tests.c $(SRCDIR)/queue.c -o $(TESTSOBJDIR)/queue_tests.exe

queue-test: $(TESTSOBJDIR)/queue_tests.exe
	$(TESTSOBJDIR)/queue_tests.exe

build-arraylist: $(SRCDIR)/array_list.c
	gcc $(CFLAGS) $(SRCDIR)/array_list.c -o $(OBJDIR)/array_list.o

build-arraylist-test: $(TESTSDIR)/array_list_tests.c $(SRCDIR)/array_list.c
	gcc $(CDEBUG) $(TESTSDIR)/array_list_tests.c $(SRCDIR)/array_list.c -o $(TESTSOBJDIR)/array_list_tests.exe

arraylist-test: $(TESTSOBJDIR)/array_list_tests.exe
	$(TESTSOBJDIR)/array_list_tests.exe

build-arraystack: $(SRCDIR)/arr_stack.c
	gcc $(CFLAGS) $(SRCDIR)/arr_stack.c -o $(OBJDIR)/arr_stack.o

build-arraystack-test: $(TESTSDIR)/array_stack_tests.c $(SRCDIR)/arr_stack.c
	gcc $(CDEBUG) $(TESTSDIR)/array_stack_tests.c $(SRCDIR)/arr_stack.c -o $(TESTSOBJDIR)/array_stack_tests.exe

arraystack-test: $(TESTSOBJDIR)/array_stack_tests.exe
	$(TESTSOBJDIR)/array_stack_tests.exe

clean:
	rm $(OBJDIR)/*.o
	rm $(TESTSOBJDIR)/*.exe

clean-objs:
	rm $(OBJDIR)/*.o

clean-tests:
	rm $(TESTSOBJDIR)/*.exe
