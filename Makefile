PROGRAM = lua
CC = g++
CFLAGS = -Wall -pedantic -ansi -std=c++11 -Wextra -Wno-sign-compare
YACC = bison
LEX = flex
YFLAGS = -d -v

$(PROGRAM) : parser.tab.o lex.yy.o naredba.o izraz.o
	$(CC) $(CFLAGS) -o $@ $^
parser.tab.o: parser.tab.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
parser.tab.cpp parser.tab.h : parser.ypp
	$(YACC) $(YFLAGS) $<
lex.yy.o: lex.yy.c parser.tab.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
lex.yy.c: lexer.lex
	$(LEX) $<
naredba.o: naredba.cpp naredba.hpp izraz.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
izraz.o: izraz.cpp izraz.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f *.o *.c *~ lua parser.tab.* parser.output

