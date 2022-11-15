# Macros ========================================

CC=g++
CFLAGS=-Wall -Wextra -Werror -ansi -pedantic -O -Wconversion
DIR=gnu/

OBJECTS=$(DIR)driver.o $(DIR)Point.o

EXE=gnu.exe

# Targets ========================================

$(DIR)$(EXE) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(DIR)$(EXE)
	tablen *.cpp
	$(DIR)$(EXE) > myoutput.txt
	diff myoutput.txt output-sample.txt --strip-trailing-cr

$(DIR)driver.o : driver-sample.cpp $(DIR)Point.o
	$(CC) $(CFLAGS) -c driver-sample.cpp -o $(DIR)driver.o

$(DIR)Point.o : Point.cpp 
	$(CC) $(CFLAGS) -c Point.cpp -o $(DIR)Point.o

clean :
	rm $(DIR)$(EXE) $(OBJECTS)

rebuild : 
	$(MAKE) clean
	$(MAKE)
