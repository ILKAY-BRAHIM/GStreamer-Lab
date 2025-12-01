CC = gcc
CFLAGS = -Wall -g `pkg-config --cflags gstreamer-1.0`
LDFLAGS = `pkg-config --libs gstreamer-1.0`

TARGET = basic-tutorial-1
SRC = basic-tutorial-1.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
