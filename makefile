CC = gcc

CFLAGS = -Wall -Wextra -g

TARGET = traceit

SRC = main.c search.c

OBJ = $(SRC:.c=.o)

LIBS = -lreadline

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

re: clean all

.PHONY: all run clean re