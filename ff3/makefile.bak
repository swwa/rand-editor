#
#	Copyright abandoned, 1983, The Rand Corporation
#

DFS     = -DUNIXV7
LOCALINCL = ../include/
CCF     = -g
LDF     = -g
RANLIB  = ranlib
DEFS    = $(DFS)
INCL    = -I. -I$(LOCALINCL)
CFLAGS  = $(CCF) $(DEFS) $(INCL)
LIB     = libff.a

# open.o can be first because it always HAS to be loaded anyway,
# and it might speed up the linker to get it out of the way.
OFILES = \
	open.o \
	close.o \
	fd.o \
	free.o \
	getc.o \
	grow.o \
	pos.o \
	putc.o \
	read.o \
	seek.o \
	size.o \
	sync.o \
	flush.o \
	sort.o \
	write.o \
	point.o \
	move.o \
	fill.o

CFILES = \
	close.c \
	fd.c \
	flush.c \
	fill.c \
	free.c \
	getc.c \
	grow.c \
	move.c \
	open.c \
	pos.c \
	putc.c \
	read.c \
	seek.c \
	size.c \
	sort.c \
	sync.c \
	write.c \
	point.c \
	move.c \
	fill.c

$(LIB): $(OFILES)
	ar r $(LIB) $(OFILES)
	$(RANLIB) $(LIB)

lint:
	lint -abch $(DEFS) $(INCL) $(CFILES)

lintlib:
	lint -Cff $(DEFS) $(INCL) $(CFILES) -lc

# Be sure the defs in "Ifdefs" agree with $(DEFS)
Calls:  $(CFILES)
	Makecalls $(CFILES)

clean : 
	rm -f $(OFILES) test

clobber:  clean
	rm -f $(LIB) ,* .??* llib*

test: test.c $(LIB)
	$(CC) $(CFLAGS) -o test test.c $(LIB)

$(OFILES) : ff.local.h ff.h $(LOCALINCL)/c_env.h

depend:
	makedepend $(CFLAGS) *.h *.c

# DO NOT DELETE THIS LINE -- make depend depends on it.

ff.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
ff.local.o: ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
ff.local.o: /usr/include/linux/types.h /usr/include/asm/types.h ff.h
ff.local.o: /usr/include/stdio.h /usr/include/libio.h
ff.local.o: /usr/include/_G_config.h
close.o: ff.local.h ../include/c_env.h ../include/localenv.h
close.o: /usr/include/sys/types.h /usr/include/linux/types.h
close.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h
close.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/errno.h
close.o: /usr/include/features.h /usr/include/sys/cdefs.h
close.o: /usr/include/linux/errno.h
fd.o: ff.local.h ../include/c_env.h ../include/localenv.h
fd.o: /usr/include/sys/types.h /usr/include/linux/types.h
fd.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h /usr/include/libio.h
fd.o: /usr/include/_G_config.h /usr/include/errno.h /usr/include/features.h
fd.o: /usr/include/sys/cdefs.h /usr/include/linux/errno.h
flush.o: ff.local.h ../include/c_env.h ../include/localenv.h
flush.o: /usr/include/sys/types.h /usr/include/linux/types.h
flush.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h
flush.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/errno.h
flush.o: /usr/include/features.h /usr/include/sys/cdefs.h
flush.o: /usr/include/linux/errno.h
free.o: ff.local.h ../include/c_env.h ../include/localenv.h
free.o: /usr/include/sys/types.h /usr/include/linux/types.h
free.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h
free.o: /usr/include/libio.h /usr/include/_G_config.h
getc.o: ff.local.h ../include/c_env.h ../include/localenv.h
getc.o: /usr/include/sys/types.h /usr/include/linux/types.h
getc.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h
getc.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/errno.h
getc.o: /usr/include/features.h /usr/include/sys/cdefs.h
getc.o: /usr/include/linux/errno.h
grow.o: ff.local.h ../include/c_env.h ../include/localenv.h
grow.o: /usr/include/sys/types.h /usr/include/linux/types.h
grow.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h
grow.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/errno.h
grow.o: /usr/include/features.h /usr/include/sys/cdefs.h
grow.o: /usr/include/linux/errno.h
move.o: ../include/c_env.h
open.o: ff.local.h ../include/c_env.h ../include/localenv.h
open.o: /usr/include/sys/types.h /usr/include/linux/types.h
open.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h
open.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/errno.h
open.o: /usr/include/features.h /usr/include/sys/cdefs.h
open.o: /usr/include/linux/errno.h /usr/include/sys/stat.h
open.o: /usr/include/linux/stat.h
point.o: ff.local.h ../include/c_env.h ../include/localenv.h
point.o: /usr/include/sys/types.h /usr/include/linux/types.h
point.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h
point.o: /usr/include/libio.h /usr/include/_G_config.h
pos.o: ff.local.h ../include/c_env.h ../include/localenv.h
pos.o: /usr/include/sys/types.h /usr/include/linux/types.h
pos.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h
pos.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/errno.h
pos.o: /usr/include/features.h /usr/include/sys/cdefs.h
pos.o: /usr/include/linux/errno.h
putc.o: ff.local.h ../include/c_env.h ../include/localenv.h
putc.o: /usr/include/sys/types.h /usr/include/linux/types.h
putc.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h
putc.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/errno.h
putc.o: /usr/include/features.h /usr/include/sys/cdefs.h
putc.o: /usr/include/linux/errno.h
read.o: ff.local.h ../include/c_env.h ../include/localenv.h
read.o: /usr/include/sys/types.h /usr/include/linux/types.h
read.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h
read.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/errno.h
read.o: /usr/include/features.h /usr/include/sys/cdefs.h
read.o: /usr/include/linux/errno.h
seek.o: ff.local.h ../include/c_env.h ../include/localenv.h
seek.o: /usr/include/sys/types.h /usr/include/linux/types.h
seek.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h
seek.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/errno.h
seek.o: /usr/include/features.h /usr/include/sys/cdefs.h
seek.o: /usr/include/linux/errno.h
size.o: ff.local.h ../include/c_env.h ../include/localenv.h
size.o: /usr/include/sys/types.h /usr/include/linux/types.h
size.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h
size.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/errno.h
size.o: /usr/include/features.h /usr/include/sys/cdefs.h
size.o: /usr/include/linux/errno.h
sort.o: ff.local.h ../include/c_env.h ../include/localenv.h
sort.o: /usr/include/sys/types.h /usr/include/linux/types.h
sort.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h
sort.o: /usr/include/libio.h /usr/include/_G_config.h
sync.o: ff.local.h ../include/c_env.h ../include/localenv.h
sync.o: /usr/include/sys/types.h /usr/include/linux/types.h
sync.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h
sync.o: /usr/include/libio.h /usr/include/_G_config.h
test.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
test.o: ff.local.h ../include/c_env.h ../include/localenv.h
test.o: /usr/include/sys/types.h /usr/include/linux/types.h
test.o: /usr/include/asm/types.h ff.h
write.o: ff.local.h ../include/c_env.h ../include/localenv.h
write.o: /usr/include/sys/types.h /usr/include/linux/types.h
write.o: /usr/include/asm/types.h ff.h /usr/include/stdio.h
write.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/errno.h
write.o: /usr/include/features.h /usr/include/sys/cdefs.h
write.o: /usr/include/linux/errno.h
