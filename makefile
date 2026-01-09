CFLAGS ?= -Wall -Wextra -pedantic
CPPFLAGS ?= $(CLAGS) -std=c++23

CSRC := $(wildcard *.c)
CPPSRC := $(wildcard *.cpp)

CBIN := $(patsubst %.c,%.out,$(CSRC))
CPPBIN := $(patsubst %.cpp,%.out,$(CPPSRC))
BIN := $(CBIN) $(CPPBIN)

.PHONY: all clean

all: $(BIN)

%.out: %.c
	@echo "Compiling $< -> $@"
	-@cc $(CFLAGS) -o $@ $<

%.out: %.cpp
	@echo "Compiling $< -> $@"
	-@c++ $(CPPFLAGS) -o $@ $<

clean:
	@echo "Removing: $(BIN)"
	-@rm -f $(BIN)
