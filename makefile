CC=gcc
CFLAGS=-Wall -Werror
DEPS=Tries.h 
SRCS=main.c Tries.c
OBJECTS=$(SRCS:.c=.o)
TARGET=td

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	if exist *.o del *.o
	if exist $(TARGET).exe del $(TARGET).exe

