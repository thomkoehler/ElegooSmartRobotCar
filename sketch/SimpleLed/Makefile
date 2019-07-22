all:	SimpleLed.hex

clean:
	rm *.elf
	rm *.hex
	rm *.o

upload: 
	avrdude -C//etc/avrdude.conf -v -patmega328p -carduino -P/dev/ttyACM0 -b115200 -D -Uflash:w:SimpleLed.hex:i
    

SimpleLed.hex: SimpleLed.elf
	avr-objcopy -O ihex -R .eeprom $< $@

SimpleLed.elf: SimpleLed.o
	avr-ld -o $@ $^

SimpleLed.o: SimpleLed.asm
	avr-as -g -mmcu=atmega328p -o $@ $^
