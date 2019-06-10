CC := g++# This is the main compiler
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
BUILDDIR := build
TARGET := bin/tales_of_alester
 
SRCEXT := cpp

CFLAGS := -std=c++11 -Wall -w
LIB := -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer 
INC := -I include


compile:
	@echo " Compiling...";
	$(shell g++ $(SRCDIR)/*.$(SRCEXT) $(CFLAGS) $(LIB) -o $(TARGET))

clean:
	@echo " Cleaning..."; 
	$(shell rm -rf bin/* -y)

run:
	@echo " Running...";
	@ bin/tales_of_alester


.PHONY: clean