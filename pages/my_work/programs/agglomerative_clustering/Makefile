
###############################################

# The compiler to use
CC = g++

# Flags I'll pass to the compiler
CFLAGS = -std=c++0x -c

# Executable file names
EXECUTABLE = main 

###############################################

# Make executables
all: $(EXECUTABLE)

###############################################

# Make Main Executable

$(EXECUTABLE): point_class.o cluster_class.o cuddle_puddle_class.o cluster_client.o
	$(CC) point_class.o cluster_class.o cuddle_puddle_class.o cluster_client.o -o $(EXECUTABLE)

point_class.o: point_class.cpp point_class.hpp
	$(CC) $(CFLAGS) point_class.cpp

cluster_class.o: cluster_class.cpp cluster_class.hpp
	$(CC) $(CFLAGS) cluster_class.cpp

cuddle_puddle_class.o: cuddle_puddle_class.cpp cuddle_puddle_class.hpp
	$(CC) $(CFLAGS) cuddle_puddle_class.cpp

cluster_client.o: cluster_client.cpp
	$(CC) $(CFLAGS) cluster_client.cpp

###############################################

# Remove executable from the directory
clean:
	rm *.o $(EXECUTABLE) 

###############################################


