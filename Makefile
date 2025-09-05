# Compiler and flags
CXX := g++
CXXFLAGS := -g -Wall -Wextra -std=c++17

# Directories and files
SRC_DIR := src
EXEC := image_generator
IMAGE := image.ppm

# locating source code and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:.cpp=.o)

################ actions ################

all: build run

run: $(EXEC)
	./$(EXEC) > $(IMAGE)

build: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(EXEC) $(IMAGE) $(OBJS)

.PHONY: all build run clean