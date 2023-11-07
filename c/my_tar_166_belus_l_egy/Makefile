
# set default compiler
CC = gcc

# CFLAGS variable 
# -g
# -Wall give verbose compiler warnings
# -o0 do not optimize generated code
# -g3 -fsanitize=address -Wall -Wextra -Werror 
# -std=c99 use the c99 standard language defintion
# -Wextra enables extra warnings flag
# -Werror make all warning into error
CFLAGS =  #-g3 -fsanitize=address -Wall -Wextra -Werror 
# this is a test

# LDFLAGS sets flags for linker
#-1m says to link in libm
# LDFLAGS = -1m

# list files that are parts of the project 

SOURCES = *.c src/*/*.c

OBJECTS = $(SOURCES:.c)
TARGET = my_tar

# first target defined in Makefile is the one
# used when makefile file is invoked with no argument. given the defintions.
# above, this Makefile will build the one named TARGET and 
# assume that it depend on all the named objects files. 
#-g before $(SOURCES) for core dump inspection
#$(CC) -g $(SOURCES) -o $@ -IC $^ $(CFLAGS) 
$(TARGET) :
	$(CC) $(SOURCES) -o $@ $^ $(CFLAGS)  

#phony means not a real target, it doesn't build anything
#the phony target clean is used to remove all compiled object files.

.PHONY: fclean

fclean:
	rm -f $(TARGET) $(OBJECTS) core 

.PHONY: run

run:
	./$(TARGET) 