
SRCDIR=.

INCLUDE=-I/opt/homebrew/include/

# Compilation Flags
CFLAGS=-std=c++11 $(INCLUDE)
# Linking Flags
LFLAGS=-L/opt/homebrew/lib -lsfml-graphics -lsfml-system -lsfml-window

CC=g++

.PHONY : all
all : game

OBJS=main.o rainbow.o ghost.o funcs.o gameover.o test.o

main.o : $(SRCDIR)/main.cpp
	$(CC) $(CFLAGS) -c $<

rainbow.o : $(SRCDIR)/rainbow.cpp
	$(CC) $(CFLAGS) -c $<

ghost.o : $(SRCDIR)/ghost.cpp
	$(CC) $(CFLAGS) -c $<

funcs.o : $(SRCDIR)/funcs.cpp
	$(CC) $(CFLAGS) -c $<

gameover.o : $(SRCDIR)/gameover.cpp
	$(CC) $(CFLAGS) -c $<

test.o : $(SRCDIR)/test.cpp
	$(CC) $(CFLAGS) -c $<

game : $(OBJS)
	$(CC) $(LFLAGS) -o game $(OBJS)
