CC = clang
CFLAGS = -g
CPPFLAGS = -Iinclude

vpath %.c src
vpath %.h include

atom_DEP = assert.o except.o mem.o

exe3%: $(atom_DEP)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: test3.6
exe3.6: testlen.o atom_lenfast.o
test3.6: exe3.6
	time ./$<

.PHONY: test3.5
exe3.5hash: testlen.o atom2hash.o
test3.5: exe3.5hash exe3.4a 
	#
	# ----- str hash saved: if ( hash == p->hash && len == p->len )
	time ./$<
	#
	# ----- str hash not saved: if (len == p->len)
	time ./exe3.4a

.PHONY: exe3.4 test3.4
exe3.4: exe3.4a exe3.4b
exe3.4a: testlen.o atom.o
exe3.4b: testlen.o atom2.o
test3.4: exe3.4
	time ./exe3.4a
	#
	# violate C str[0]
	time ./exe3.4b

.PHONY:test3.1
exe3.1: testlen.o atom.o 
test3.1: exe3.1
	time ./$<

teststruct: struct.o stack.o assert.o except.o mem.o
teststack: stack.o assert.o except.o mem.o

.PHONY: clean
clean:
	rm -f *.o *.d exe3.*

