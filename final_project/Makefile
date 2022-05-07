# ALL: wordle

# # find all of the source files and header files

# SOURCES := $(wildcard *.cpp)
# HEADERS := $(wildcard *.h)

# # create a list of object files by replacing .cpp with .o

# OBJECTS := $(SOURCES:.cpp=.o)

# # a recipe for making an object file from a .cpp file
# # Note: this makes every header file a dependency of every object file,
# # which is not ideal, but it is safe.

# %.o : %.cpp ${HEADERS}
# 	g++ -c $< -std=c++17

# # explicitly write the rule for linking together the executable

# wordle: ${OBJECTS}
# 	g++ -o $@ ${OBJECTS}

all:
	g++ -std=c++11 main.cpp game.cpp -o wordle

clean:
	rm -rf *.o wordle