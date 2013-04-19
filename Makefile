# based on: http://surf.suckless.org/
# See LICENSE file for copyright and license details.

include config.mk

SRC = surfi/surfi.c
OBJ = ${SRC:.c=.o}

all: options surfi

options:
	@echo surfi build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	@echo CC $<
	@${CC} -o bin/$(notdir $@) -c ${CFLAGS} $<

${OBJ}: config.mk

config.h:
	@echo creating $@ from config.def.h
	@cp config.def.h $@

surfi: ${OBJ}
	@echo CC -o bin/$@
	@${CC} -o bin/$@ bin/surfi.o ${LDFLAGS}

.PHONY: all options
