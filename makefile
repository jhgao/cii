CC = clang
CFLAGS = -g
CPPFLAGS = -Ilibinclude -Iinclude

vpath %.c libsrc src
vpath %.h libinclude include

atom_DEP = assert.o except.o mem.o

exe3%: $(atom_DEP)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: test3.6
exe3.6: testlen.o atom_lenfast.o
test3.6single: exe3.6
	#
	# fast Atom_length
	time ./exe3.6
test3.6compare: exe3.6 exe3.1b
	#
	# fast Atom_length
	time ./exe3.6
	#
	# slow Atom_length
	time ./exe3.1b

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
exe3.1a: testlen.o atom.o
exe3.1b: testlen.o atom1.o
test3.1: exe3.1a exe3.1b
	#
	# bucket[2048]
	time ./exe3.1a
	#
	# bucket[2039]
	time ./exe3.1b

teststruct: struct.o stack.o assert.o except.o mem.o
teststack: stack.o assert.o except.o mem.o

.PHONY: clean
clean:
	find . -maxdepth 1 -type f -perm /111 -exec rm {} \;
	rm -f *.o *.d

