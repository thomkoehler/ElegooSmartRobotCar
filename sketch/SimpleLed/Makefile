all:	SimpleLed.hex

clean:
	rm *.elf
	rm *.hex
	rm *.o

SimpleLed.hex: SimpleLed.elf
	avr-objcopy -O ihex -R .eeprom $< $@

SimpleLed.elf: SimpleLed.o
	avr-ld -o $@ $^

SimpleLed.o: SimpleLed.asm
	avr-as -g -mmcu=atmega328p -o $@ $^
