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

clean:
	rm $(OBJDIR)/*.o
	rm $(TESTSOBJDIR)/*.exe

clean-objs:
	rm $(OBJDIR)/*.o

clean-tests:
	rm $(TESTSOBJDIR)/*.exe
