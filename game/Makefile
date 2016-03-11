SRC= main.c
TARGET= big_points

CC=gcc
FLAGS= -Wall -pedantic -ansi

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(FLAGS) -o $@ $<

clean:
	rm -rvf $(TARGET)
