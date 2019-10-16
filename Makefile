LDSCRIPT = lib/linker_scripts/samd10c14a_flash.ld
BOOTUP = lib/startup_samd10.o
MCUTYPE=__SAMD10C14A__

OBJS=$(BOOTUP) main.o

# Tools
CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld
AS=arm-none-eabi-as
OBJCOPY=arm-none-eabi-objcopy

ELF=main.elf
HEX=main.hex

LDFLAGS+= --script=$(LDSCRIPT) --architecture=cortex-m0 --gc-sections
CFLAGS+= -mcpu=cortex-m0 -g
CFLAGS+= -Ilib/ -I.
CFLAGS+= -D$(MCUTYPE)

$(HEX):	$(ELF)
	$(OBJCOPY) -O ihex $(ELF) $(HEX)

$(ELF):		$(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

# compile
%.o:	%.c
	$(CC) -c $(CFLAGS) $< -o $@

%.o:	%.s
	$(AS) $< -o $@

clean:
	rm -f $(OBJS) $(OBJS:.o=.d) $(ELF)

# Upload the new code to the chip
flash: $(HEX)
	./upload_firmware.sh
