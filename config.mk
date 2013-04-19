# based on: http://surf.suckless.org/
VERSION = 0.1

# paths
PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

GTKINC = `pkg-config --cflags gtk+-3.0 webkitgtk-3.0`
GTKLIB = `pkg-config --libs gtk+-3.0 webkitgtk-3.0`

# includes and libs
INCS = -I. -I/usr/include ${GTKINC}
LIBS = -L/usr/lib -lc ${GTKLIB}

# flags
CPPFLAGS = -DVERSION=\"${VERSION}\" -D_BSD_SOURCE
CFLAGS = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
LDFLAGS = -g ${LIBS}

# Solaris
#CFLAGS = -fast ${INCS} -DVERSION=\"${VERSION}\"
#LDFLAGS = ${LIBS}

# compiler and linker
CC = cc
