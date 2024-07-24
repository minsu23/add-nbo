CC = gcc
CFLAGS = -Wall -O2
TARGET = add-nbo

all: $(TARGET)

$(TARGET): add_nbo.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)