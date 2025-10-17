MCU=attiny85
F_CPU=16500000
CC=avr-gcc
CFLAGS=-mmcu=$(MCU) -Wall -Os -DF_CPU=$(F_CPU) -Iusbdrv
LDFLAGS=-mmcu=$(MCU)
OBJS=main.o usbdrv/usbdrv.o usbdrv/usbdrvasm.o

all: main.hex

main.hex: main.elf
	avr-objcopy -O ihex -R .eeprom main.elf main.hex

main.elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o main.elf $(OBJS)

clean:
	rm -f *.o usbdrv/*.o *.elf *.hex

flash: main.hex
	avrdude -p t85 -c usbasp -U flash:w:main.hex