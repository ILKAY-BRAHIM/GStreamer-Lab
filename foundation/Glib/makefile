TARGET = my_object

SOURCES = my_object.c

CFLAGS := $(shell pkg-config --cflags gobject-2.0)

LIBS := $(shell pkg-config --libs gobject-2.0)

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(SOURCES) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)

.PHONY: all clean