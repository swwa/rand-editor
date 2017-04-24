#
#	Copyright abandoned, 1983, The Rand Corporation
#

#
#       MAKEFILE FOR RAND "LA" LINE-ACCESS I/O PACKAGE
#
#       Original Design by David Yost
#       Coded by David Yost and Rick Kiessig
#
#DFS     = -DUNIXV7 -DLA_DEBUG
DFS     = -DUNIXV7
LOCALINCL = ../include/
CC      = gcc
CCF     = -g -O -Wall
LDF     = -g
RANLIB  = ranlib
FFL     = ff3
DEFS    = $(DFS)
LIB     = libla.a
LIBTMP  = ../lib/libtmp.a
#
FF      = ../$(FFL)/
FFLIB   = $(FF)libff.a
INCL    = -I. -I$(FF) -I$(LOCALINCL)
CFLAGS  = $(CCF) $(DEFS) $(INCL)
LINT    = lint
LIBC    =

# laopen.o can be first because it always HAS to be loaded anyway,
# and it might speed up the linker to get it out of the way.
OFILES =\
	laopen.o \
	laalign.o \
	lablank.o \
	labsize.o \
	ladeb.o \
	laerr.o \
	lafrpl.o \
	lalcnt.o \
	lalcopy.o \
	lalflush.o \
	lalget.o \
	lalpnt.o \
	laadv.o \
	lalrpl.o \
	laldel.o \
	lalcol.o \
	lalins.o \
	labreak.o \
	laclose.o \
	lalink.o \
	lalrsize.o \
	lalseek.o \
	lalwsize.o \
	lacfile.o \
	laint.o \
	laother.o \
	laabort.o

CFILES =\
	laabort.c \
	laadv.c \
	laalign.c \
	lablank.c \
	labreak.c \
	labsize.c \
	lacfile.c \
	laclose.c \
	ladeb.c \
	laerr.c \
	lafrpl.c \
	laint.c \
	lalcnt.c \
	lalcol.c \
	lalcopy.c \
	laldel.c \
	lalflush.c \
	lalget.c \
	lalink.c \
	lalins.c \
	lalpnt.c \
	lalrpl.c \
	lalrsize.c \
	lalseek.c \
	lalwsize.c \
	laopen.c \
	laother.c


$(LIB): $(OFILES)
	ar r $(LIB) $(OFILES)
	$(RANLIB) $(LIB)

lint:
	$(LINT) -abch $(DEFS) $(INCL) $(CFILES) $(FF)llib-lff.ln

lintlib:
	$(LINT) -Cla $(DEFS) $(INCL) $(CFILES) $(FF)llib-lff.ln

Calls:  $(CFILES)
	Makecalls $(CFILES)

test:   test.o $(LIB) $(LIBTMP)
	$(CC) $(LDF) $(O)test.o $(LIB) $(LIBTMP) $(FFLIB) $(LIBC)
	-mv test ,test
	mv a.out test

$(FFLIB): $(.PRECIOUS)
	cd $(FF); make

clean:
	rm -f $(OFILES) test test1 *.o

clobber: clean
	rm -f $(LIB) ,* .??* llib*

$(OFILES) : la.local.h la.h $(LOCALINCL)/c_env.h $(FF)ff.h

test1:	test1.o $(LIB)
	$(CC) $(LDF) test1.o $(LIB) $(LIBTMP) $(FFLIB) -o test1

depend:
	makedepend $(CFLAGS) *.h *.c
# DO NOT DELETE THIS LINE -- make depend depends on it.

la.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
la.o: /usr/include/_G_config.h
la.local.o: ../include/c_env.h /usr/include/sys/types.h
la.local.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
la.local.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
la.local.o: /usr/include/_G_config.h
laabort.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laabort.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
laabort.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
laabort.o: /usr/include/_G_config.h
laadv.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laadv.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h ../ff3/ff.h
laadv.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
laalign.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laalign.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
laalign.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
laalign.o: /usr/include/_G_config.h
lablank.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lablank.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lablank.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lablank.o: /usr/include/_G_config.h
labreak.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
labreak.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
labreak.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
labreak.o: /usr/include/_G_config.h
labsize.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
labsize.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
labsize.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
labsize.o: /usr/include/_G_config.h
lacfile.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lacfile.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lacfile.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lacfile.o: /usr/include/_G_config.h
laclose.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laclose.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
laclose.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
laclose.o: /usr/include/_G_config.h
ladeb.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
ladeb.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h ../ff3/ff.h
ladeb.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
laerr.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laerr.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h ../ff3/ff.h
laerr.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
lafins.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lafins.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lafins.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lafins.o: /usr/include/_G_config.h
lafrpl.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lafrpl.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lafrpl.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lafrpl.o: /usr/include/_G_config.h
lalcnt.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalcnt.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lalcnt.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lalcnt.o: /usr/include/_G_config.h
lalcol.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalcol.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lalcol.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lalcol.o: /usr/include/_G_config.h
lalcopy.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalcopy.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lalcopy.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lalcopy.o: /usr/include/_G_config.h
laldel.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laldel.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
laldel.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
laldel.o: /usr/include/_G_config.h
lalflush.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalflush.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lalflush.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lalflush.o: /usr/include/_G_config.h /usr/include/errno.h
lalflush.o: /usr/include/features.h /usr/include/sys/cdefs.h
lalflush.o: /usr/include/linux/errno.h /usr/include/signal.h
lalflush.o: /usr/include/linux/signal.h
lalget.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalget.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lalget.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lalget.o: /usr/include/_G_config.h
lalink.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalink.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lalink.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lalink.o: /usr/include/_G_config.h
lalins.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalins.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lalins.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lalins.o: /usr/include/_G_config.h
lalpnt.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalpnt.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lalpnt.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lalpnt.o: /usr/include/_G_config.h
lalrpl.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalrpl.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lalrpl.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lalrpl.o: /usr/include/_G_config.h
lalrsize.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalrsize.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lalrsize.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lalrsize.o: /usr/include/_G_config.h
lalseek.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalseek.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lalseek.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lalseek.o: /usr/include/_G_config.h
lalwsize.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalwsize.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
lalwsize.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
lalwsize.o: /usr/include/_G_config.h
laopen.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laopen.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
laopen.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
laopen.o: /usr/include/_G_config.h /usr/include/sys/stat.h
laopen.o: /usr/include/features.h /usr/include/sys/cdefs.h
laopen.o: /usr/include/linux/stat.h
laother.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laother.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h
laother.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/libio.h
laother.o: /usr/include/_G_config.h
test.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
test.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h ../ff3/ff.h
test.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
test.o: /usr/include/signal.h /usr/include/features.h
test.o: /usr/include/sys/cdefs.h /usr/include/linux/signal.h
test1.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
test1.o: /usr/include/linux/types.h /usr/include/asm/types.h la.h ../ff3/ff.h
test1.o: /usr/include/stdio.h /usr/include/libio.h /usr/include/_G_config.h
