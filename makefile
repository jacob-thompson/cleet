CFLAGS ?= -Wall -Wextra -pedantic

SRC := $(wildcard *.c)
BIN := $(patsubst %.c,%.out,$(SRC))

.PHONY: all clean

all: $(BIN)

%.out: %.c
	@echo "Compiling $< -> $@"
	-@cc $(CFLAGS) -o $@ $<

clean:
	@echo "Removing: $(BIN)"
	-@rm -f $(BIN)
