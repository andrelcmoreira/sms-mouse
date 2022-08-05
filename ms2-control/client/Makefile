TARGET = ms2_control_client
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)

CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -Wall -Werror -Wextra -O2
MCU = atmega32u4

ifndef MCU_PORT
MCU_PORT = /dev/ttyACM0
endif

.PHONY: all app clean install

all: app install

app: $(OBJECTS)
	@echo "\ngenerating app ..."
	@mkdir -p build
	$(CC) $(CFLAGS) -mmcu=$(MCU) $^ -o build/$(TARGET).elf
	$(OBJCOPY) -j .text -j .data -O ihex build/$(TARGET).elf build/$(TARGET).hex

install:
	@echo "\nflashing app into microcontroller using the port $(MCU_PORT) ..."
	avrdude -p $(MCU) -c avr109 -P $(MCU_PORT) -U flash:w:build/$(TARGET).hex

src/%.o: src/%.c
	@echo "compiling $< ..."
	$(CC) $(CFLAGS) -mmcu=$(MCU) -c $< -o $@

clean:
	@rm -rf build/ src/*.o
