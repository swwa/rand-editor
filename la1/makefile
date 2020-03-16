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

la.o: ../ff3/ff.h /usr/include/stdio.h /usr/include/bits/libc-header-start.h
la.o: /usr/include/features.h /usr/include/stdc-predef.h
la.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
la.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
la.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
la.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
la.o: /usr/include/bits/types/__fpos_t.h
la.o: /usr/include/bits/types/__mbstate_t.h
la.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
la.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
la.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
la.local.o: ../include/c_env.h /usr/include/sys/types.h
la.local.o: /usr/include/features.h /usr/include/stdc-predef.h
la.local.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
la.local.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
la.local.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
la.local.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
la.local.o: /usr/include/bits/types/clock_t.h
la.local.o: /usr/include/bits/types/clockid_t.h
la.local.o: /usr/include/bits/types/time_t.h
la.local.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
la.local.o: /usr/include/endian.h /usr/include/bits/endian.h
la.local.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
la.local.o: /usr/include/sys/select.h /usr/include/bits/select.h
la.local.o: /usr/include/bits/types/sigset_t.h
la.local.o: /usr/include/bits/types/__sigset_t.h
la.local.o: /usr/include/bits/types/struct_timeval.h
la.local.o: /usr/include/bits/types/struct_timespec.h
la.local.o: /usr/include/bits/pthreadtypes.h
la.local.o: /usr/include/bits/thread-shared-types.h
la.local.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
la.local.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
la.local.o: /usr/include/bits/types/__fpos_t.h
la.local.o: /usr/include/bits/types/__mbstate_t.h
la.local.o: /usr/include/bits/types/__fpos64_t.h
la.local.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
la.local.o: /usr/include/bits/types/struct_FILE.h
la.local.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
laabort.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laabort.o: /usr/include/features.h /usr/include/stdc-predef.h
laabort.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
laabort.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
laabort.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
laabort.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
laabort.o: /usr/include/bits/types/clock_t.h
laabort.o: /usr/include/bits/types/clockid_t.h
laabort.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
laabort.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
laabort.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
laabort.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
laabort.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
laabort.o: /usr/include/bits/types/__sigset_t.h
laabort.o: /usr/include/bits/types/struct_timeval.h
laabort.o: /usr/include/bits/types/struct_timespec.h
laabort.o: /usr/include/bits/pthreadtypes.h
laabort.o: /usr/include/bits/thread-shared-types.h
laabort.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
laabort.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
laabort.o: /usr/include/bits/types/__fpos_t.h
laabort.o: /usr/include/bits/types/__mbstate_t.h
laabort.o: /usr/include/bits/types/__fpos64_t.h
laabort.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
laabort.o: /usr/include/bits/types/struct_FILE.h
laabort.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
laadv.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laadv.o: /usr/include/features.h /usr/include/stdc-predef.h
laadv.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
laadv.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
laadv.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
laadv.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
laadv.o: /usr/include/bits/types/clock_t.h
laadv.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
laadv.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
laadv.o: /usr/include/endian.h /usr/include/bits/endian.h
laadv.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
laadv.o: /usr/include/sys/select.h /usr/include/bits/select.h
laadv.o: /usr/include/bits/types/sigset_t.h
laadv.o: /usr/include/bits/types/__sigset_t.h
laadv.o: /usr/include/bits/types/struct_timeval.h
laadv.o: /usr/include/bits/types/struct_timespec.h
laadv.o: /usr/include/bits/pthreadtypes.h
laadv.o: /usr/include/bits/thread-shared-types.h
laadv.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
laadv.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
laadv.o: /usr/include/bits/types/__fpos_t.h
laadv.o: /usr/include/bits/types/__mbstate_t.h
laadv.o: /usr/include/bits/types/__fpos64_t.h
laadv.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
laadv.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
laadv.o: /usr/include/bits/sys_errlist.h
laalign.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laalign.o: /usr/include/features.h /usr/include/stdc-predef.h
laalign.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
laalign.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
laalign.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
laalign.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
laalign.o: /usr/include/bits/types/clock_t.h
laalign.o: /usr/include/bits/types/clockid_t.h
laalign.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
laalign.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
laalign.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
laalign.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
laalign.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
laalign.o: /usr/include/bits/types/__sigset_t.h
laalign.o: /usr/include/bits/types/struct_timeval.h
laalign.o: /usr/include/bits/types/struct_timespec.h
laalign.o: /usr/include/bits/pthreadtypes.h
laalign.o: /usr/include/bits/thread-shared-types.h
laalign.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
laalign.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
laalign.o: /usr/include/bits/types/__fpos_t.h
laalign.o: /usr/include/bits/types/__mbstate_t.h
laalign.o: /usr/include/bits/types/__fpos64_t.h
laalign.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
laalign.o: /usr/include/bits/types/struct_FILE.h
laalign.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
lablank.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lablank.o: /usr/include/features.h /usr/include/stdc-predef.h
lablank.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lablank.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lablank.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lablank.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lablank.o: /usr/include/bits/types/clock_t.h
lablank.o: /usr/include/bits/types/clockid_t.h
lablank.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
lablank.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
lablank.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
lablank.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
lablank.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
lablank.o: /usr/include/bits/types/__sigset_t.h
lablank.o: /usr/include/bits/types/struct_timeval.h
lablank.o: /usr/include/bits/types/struct_timespec.h
lablank.o: /usr/include/bits/pthreadtypes.h
lablank.o: /usr/include/bits/thread-shared-types.h
lablank.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lablank.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lablank.o: /usr/include/bits/types/__fpos_t.h
lablank.o: /usr/include/bits/types/__mbstate_t.h
lablank.o: /usr/include/bits/types/__fpos64_t.h
lablank.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lablank.o: /usr/include/bits/types/struct_FILE.h
lablank.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
labreak.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
labreak.o: /usr/include/features.h /usr/include/stdc-predef.h
labreak.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
labreak.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
labreak.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
labreak.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
labreak.o: /usr/include/bits/types/clock_t.h
labreak.o: /usr/include/bits/types/clockid_t.h
labreak.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
labreak.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
labreak.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
labreak.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
labreak.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
labreak.o: /usr/include/bits/types/__sigset_t.h
labreak.o: /usr/include/bits/types/struct_timeval.h
labreak.o: /usr/include/bits/types/struct_timespec.h
labreak.o: /usr/include/bits/pthreadtypes.h
labreak.o: /usr/include/bits/thread-shared-types.h
labreak.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
labreak.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
labreak.o: /usr/include/bits/types/__fpos_t.h
labreak.o: /usr/include/bits/types/__mbstate_t.h
labreak.o: /usr/include/bits/types/__fpos64_t.h
labreak.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
labreak.o: /usr/include/bits/types/struct_FILE.h
labreak.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
labsize.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
labsize.o: /usr/include/features.h /usr/include/stdc-predef.h
labsize.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
labsize.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
labsize.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
labsize.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
labsize.o: /usr/include/bits/types/clock_t.h
labsize.o: /usr/include/bits/types/clockid_t.h
labsize.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
labsize.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
labsize.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
labsize.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
labsize.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
labsize.o: /usr/include/bits/types/__sigset_t.h
labsize.o: /usr/include/bits/types/struct_timeval.h
labsize.o: /usr/include/bits/types/struct_timespec.h
labsize.o: /usr/include/bits/pthreadtypes.h
labsize.o: /usr/include/bits/thread-shared-types.h
labsize.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
labsize.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
labsize.o: /usr/include/bits/types/__fpos_t.h
labsize.o: /usr/include/bits/types/__mbstate_t.h
labsize.o: /usr/include/bits/types/__fpos64_t.h
labsize.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
labsize.o: /usr/include/bits/types/struct_FILE.h
labsize.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
lacfile.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lacfile.o: /usr/include/features.h /usr/include/stdc-predef.h
lacfile.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lacfile.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lacfile.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lacfile.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lacfile.o: /usr/include/bits/types/clock_t.h
lacfile.o: /usr/include/bits/types/clockid_t.h
lacfile.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
lacfile.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
lacfile.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
lacfile.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
lacfile.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
lacfile.o: /usr/include/bits/types/__sigset_t.h
lacfile.o: /usr/include/bits/types/struct_timeval.h
lacfile.o: /usr/include/bits/types/struct_timespec.h
lacfile.o: /usr/include/bits/pthreadtypes.h
lacfile.o: /usr/include/bits/thread-shared-types.h
lacfile.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lacfile.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lacfile.o: /usr/include/bits/types/__fpos_t.h
lacfile.o: /usr/include/bits/types/__mbstate_t.h
lacfile.o: /usr/include/bits/types/__fpos64_t.h
lacfile.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lacfile.o: /usr/include/bits/types/struct_FILE.h
lacfile.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
laclose.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laclose.o: /usr/include/features.h /usr/include/stdc-predef.h
laclose.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
laclose.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
laclose.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
laclose.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
laclose.o: /usr/include/bits/types/clock_t.h
laclose.o: /usr/include/bits/types/clockid_t.h
laclose.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
laclose.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
laclose.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
laclose.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
laclose.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
laclose.o: /usr/include/bits/types/__sigset_t.h
laclose.o: /usr/include/bits/types/struct_timeval.h
laclose.o: /usr/include/bits/types/struct_timespec.h
laclose.o: /usr/include/bits/pthreadtypes.h
laclose.o: /usr/include/bits/thread-shared-types.h
laclose.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
laclose.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
laclose.o: /usr/include/bits/types/__fpos_t.h
laclose.o: /usr/include/bits/types/__mbstate_t.h
laclose.o: /usr/include/bits/types/__fpos64_t.h
laclose.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
laclose.o: /usr/include/bits/types/struct_FILE.h
laclose.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
ladeb.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
ladeb.o: /usr/include/features.h /usr/include/stdc-predef.h
ladeb.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
ladeb.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
ladeb.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
ladeb.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
ladeb.o: /usr/include/bits/types/clock_t.h
ladeb.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
ladeb.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
ladeb.o: /usr/include/endian.h /usr/include/bits/endian.h
ladeb.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
ladeb.o: /usr/include/sys/select.h /usr/include/bits/select.h
ladeb.o: /usr/include/bits/types/sigset_t.h
ladeb.o: /usr/include/bits/types/__sigset_t.h
ladeb.o: /usr/include/bits/types/struct_timeval.h
ladeb.o: /usr/include/bits/types/struct_timespec.h
ladeb.o: /usr/include/bits/pthreadtypes.h
ladeb.o: /usr/include/bits/thread-shared-types.h
ladeb.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
ladeb.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
ladeb.o: /usr/include/bits/types/__fpos_t.h
ladeb.o: /usr/include/bits/types/__mbstate_t.h
ladeb.o: /usr/include/bits/types/__fpos64_t.h
ladeb.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
ladeb.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
ladeb.o: /usr/include/bits/sys_errlist.h
laerr.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laerr.o: /usr/include/features.h /usr/include/stdc-predef.h
laerr.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
laerr.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
laerr.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
laerr.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
laerr.o: /usr/include/bits/types/clock_t.h
laerr.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
laerr.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
laerr.o: /usr/include/endian.h /usr/include/bits/endian.h
laerr.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
laerr.o: /usr/include/sys/select.h /usr/include/bits/select.h
laerr.o: /usr/include/bits/types/sigset_t.h
laerr.o: /usr/include/bits/types/__sigset_t.h
laerr.o: /usr/include/bits/types/struct_timeval.h
laerr.o: /usr/include/bits/types/struct_timespec.h
laerr.o: /usr/include/bits/pthreadtypes.h
laerr.o: /usr/include/bits/thread-shared-types.h
laerr.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
laerr.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
laerr.o: /usr/include/bits/types/__fpos_t.h
laerr.o: /usr/include/bits/types/__mbstate_t.h
laerr.o: /usr/include/bits/types/__fpos64_t.h
laerr.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
laerr.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
laerr.o: /usr/include/bits/sys_errlist.h
lafins.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lafins.o: /usr/include/features.h /usr/include/stdc-predef.h
lafins.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lafins.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lafins.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lafins.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lafins.o: /usr/include/bits/types/clock_t.h
lafins.o: /usr/include/bits/types/clockid_t.h
lafins.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
lafins.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
lafins.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
lafins.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
lafins.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
lafins.o: /usr/include/bits/types/__sigset_t.h
lafins.o: /usr/include/bits/types/struct_timeval.h
lafins.o: /usr/include/bits/types/struct_timespec.h
lafins.o: /usr/include/bits/pthreadtypes.h
lafins.o: /usr/include/bits/thread-shared-types.h
lafins.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lafins.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lafins.o: /usr/include/bits/types/__fpos_t.h
lafins.o: /usr/include/bits/types/__mbstate_t.h
lafins.o: /usr/include/bits/types/__fpos64_t.h
lafins.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lafins.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
lafins.o: /usr/include/bits/sys_errlist.h
lafrpl.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lafrpl.o: /usr/include/features.h /usr/include/stdc-predef.h
lafrpl.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lafrpl.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lafrpl.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lafrpl.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lafrpl.o: /usr/include/bits/types/clock_t.h
lafrpl.o: /usr/include/bits/types/clockid_t.h
lafrpl.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
lafrpl.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
lafrpl.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
lafrpl.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
lafrpl.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
lafrpl.o: /usr/include/bits/types/__sigset_t.h
lafrpl.o: /usr/include/bits/types/struct_timeval.h
lafrpl.o: /usr/include/bits/types/struct_timespec.h
lafrpl.o: /usr/include/bits/pthreadtypes.h
lafrpl.o: /usr/include/bits/thread-shared-types.h
lafrpl.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lafrpl.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lafrpl.o: /usr/include/bits/types/__fpos_t.h
lafrpl.o: /usr/include/bits/types/__mbstate_t.h
lafrpl.o: /usr/include/bits/types/__fpos64_t.h
lafrpl.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lafrpl.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
lafrpl.o: /usr/include/bits/sys_errlist.h
lalcnt.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalcnt.o: /usr/include/features.h /usr/include/stdc-predef.h
lalcnt.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lalcnt.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lalcnt.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lalcnt.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lalcnt.o: /usr/include/bits/types/clock_t.h
lalcnt.o: /usr/include/bits/types/clockid_t.h
lalcnt.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
lalcnt.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
lalcnt.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
lalcnt.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
lalcnt.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
lalcnt.o: /usr/include/bits/types/__sigset_t.h
lalcnt.o: /usr/include/bits/types/struct_timeval.h
lalcnt.o: /usr/include/bits/types/struct_timespec.h
lalcnt.o: /usr/include/bits/pthreadtypes.h
lalcnt.o: /usr/include/bits/thread-shared-types.h
lalcnt.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lalcnt.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lalcnt.o: /usr/include/bits/types/__fpos_t.h
lalcnt.o: /usr/include/bits/types/__mbstate_t.h
lalcnt.o: /usr/include/bits/types/__fpos64_t.h
lalcnt.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lalcnt.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
lalcnt.o: /usr/include/bits/sys_errlist.h
lalcol.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalcol.o: /usr/include/features.h /usr/include/stdc-predef.h
lalcol.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lalcol.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lalcol.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lalcol.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lalcol.o: /usr/include/bits/types/clock_t.h
lalcol.o: /usr/include/bits/types/clockid_t.h
lalcol.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
lalcol.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
lalcol.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
lalcol.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
lalcol.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
lalcol.o: /usr/include/bits/types/__sigset_t.h
lalcol.o: /usr/include/bits/types/struct_timeval.h
lalcol.o: /usr/include/bits/types/struct_timespec.h
lalcol.o: /usr/include/bits/pthreadtypes.h
lalcol.o: /usr/include/bits/thread-shared-types.h
lalcol.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lalcol.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lalcol.o: /usr/include/bits/types/__fpos_t.h
lalcol.o: /usr/include/bits/types/__mbstate_t.h
lalcol.o: /usr/include/bits/types/__fpos64_t.h
lalcol.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lalcol.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
lalcol.o: /usr/include/bits/sys_errlist.h
lalcopy.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalcopy.o: /usr/include/features.h /usr/include/stdc-predef.h
lalcopy.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lalcopy.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lalcopy.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lalcopy.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lalcopy.o: /usr/include/bits/types/clock_t.h
lalcopy.o: /usr/include/bits/types/clockid_t.h
lalcopy.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
lalcopy.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
lalcopy.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
lalcopy.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
lalcopy.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
lalcopy.o: /usr/include/bits/types/__sigset_t.h
lalcopy.o: /usr/include/bits/types/struct_timeval.h
lalcopy.o: /usr/include/bits/types/struct_timespec.h
lalcopy.o: /usr/include/bits/pthreadtypes.h
lalcopy.o: /usr/include/bits/thread-shared-types.h
lalcopy.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lalcopy.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lalcopy.o: /usr/include/bits/types/__fpos_t.h
lalcopy.o: /usr/include/bits/types/__mbstate_t.h
lalcopy.o: /usr/include/bits/types/__fpos64_t.h
lalcopy.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lalcopy.o: /usr/include/bits/types/struct_FILE.h
lalcopy.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
laldel.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laldel.o: /usr/include/features.h /usr/include/stdc-predef.h
laldel.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
laldel.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
laldel.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
laldel.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
laldel.o: /usr/include/bits/types/clock_t.h
laldel.o: /usr/include/bits/types/clockid_t.h
laldel.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
laldel.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
laldel.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
laldel.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
laldel.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
laldel.o: /usr/include/bits/types/__sigset_t.h
laldel.o: /usr/include/bits/types/struct_timeval.h
laldel.o: /usr/include/bits/types/struct_timespec.h
laldel.o: /usr/include/bits/pthreadtypes.h
laldel.o: /usr/include/bits/thread-shared-types.h
laldel.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
laldel.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
laldel.o: /usr/include/bits/types/__fpos_t.h
laldel.o: /usr/include/bits/types/__mbstate_t.h
laldel.o: /usr/include/bits/types/__fpos64_t.h
laldel.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
laldel.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
laldel.o: /usr/include/bits/sys_errlist.h
lalflush.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalflush.o: /usr/include/features.h /usr/include/stdc-predef.h
lalflush.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lalflush.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lalflush.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lalflush.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lalflush.o: /usr/include/bits/types/clock_t.h
lalflush.o: /usr/include/bits/types/clockid_t.h
lalflush.o: /usr/include/bits/types/time_t.h
lalflush.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
lalflush.o: /usr/include/endian.h /usr/include/bits/endian.h
lalflush.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
lalflush.o: /usr/include/sys/select.h /usr/include/bits/select.h
lalflush.o: /usr/include/bits/types/sigset_t.h
lalflush.o: /usr/include/bits/types/__sigset_t.h
lalflush.o: /usr/include/bits/types/struct_timeval.h
lalflush.o: /usr/include/bits/types/struct_timespec.h
lalflush.o: /usr/include/bits/pthreadtypes.h
lalflush.o: /usr/include/bits/thread-shared-types.h
lalflush.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lalflush.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lalflush.o: /usr/include/bits/types/__fpos_t.h
lalflush.o: /usr/include/bits/types/__mbstate_t.h
lalflush.o: /usr/include/bits/types/__fpos64_t.h
lalflush.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lalflush.o: /usr/include/bits/types/struct_FILE.h
lalflush.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
lalflush.o: /usr/include/errno.h /usr/include/bits/errno.h
lalflush.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
lalflush.o: /usr/include/asm-generic/errno.h
lalflush.o: /usr/include/asm-generic/errno-base.h /usr/include/signal.h
lalflush.o: /usr/include/bits/signum.h /usr/include/bits/signum-generic.h
lalflush.o: /usr/include/bits/types/sig_atomic_t.h
lalflush.o: /usr/include/bits/types/siginfo_t.h
lalflush.o: /usr/include/bits/types/__sigval_t.h
lalflush.o: /usr/include/bits/siginfo-arch.h
lalflush.o: /usr/include/bits/siginfo-consts.h
lalflush.o: /usr/include/bits/types/sigval_t.h
lalflush.o: /usr/include/bits/types/sigevent_t.h
lalflush.o: /usr/include/bits/sigevent-consts.h /usr/include/bits/sigaction.h
lalflush.o: /usr/include/bits/sigcontext.h /usr/include/bits/types/stack_t.h
lalflush.o: /usr/include/sys/ucontext.h /usr/include/bits/sigstack.h
lalflush.o: /usr/include/bits/ss_flags.h
lalflush.o: /usr/include/bits/types/struct_sigstack.h
lalflush.o: /usr/include/bits/sigthread.h /usr/include/bits/signal_ext.h
lalget.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalget.o: /usr/include/features.h /usr/include/stdc-predef.h
lalget.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lalget.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lalget.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lalget.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lalget.o: /usr/include/bits/types/clock_t.h
lalget.o: /usr/include/bits/types/clockid_t.h
lalget.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
lalget.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
lalget.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
lalget.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
lalget.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
lalget.o: /usr/include/bits/types/__sigset_t.h
lalget.o: /usr/include/bits/types/struct_timeval.h
lalget.o: /usr/include/bits/types/struct_timespec.h
lalget.o: /usr/include/bits/pthreadtypes.h
lalget.o: /usr/include/bits/thread-shared-types.h
lalget.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lalget.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lalget.o: /usr/include/bits/types/__fpos_t.h
lalget.o: /usr/include/bits/types/__mbstate_t.h
lalget.o: /usr/include/bits/types/__fpos64_t.h
lalget.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lalget.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
lalget.o: /usr/include/bits/sys_errlist.h
lalink.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalink.o: /usr/include/features.h /usr/include/stdc-predef.h
lalink.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lalink.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lalink.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lalink.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lalink.o: /usr/include/bits/types/clock_t.h
lalink.o: /usr/include/bits/types/clockid_t.h
lalink.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
lalink.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
lalink.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
lalink.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
lalink.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
lalink.o: /usr/include/bits/types/__sigset_t.h
lalink.o: /usr/include/bits/types/struct_timeval.h
lalink.o: /usr/include/bits/types/struct_timespec.h
lalink.o: /usr/include/bits/pthreadtypes.h
lalink.o: /usr/include/bits/thread-shared-types.h
lalink.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lalink.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lalink.o: /usr/include/bits/types/__fpos_t.h
lalink.o: /usr/include/bits/types/__mbstate_t.h
lalink.o: /usr/include/bits/types/__fpos64_t.h
lalink.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lalink.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
lalink.o: /usr/include/bits/sys_errlist.h
lalins.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalins.o: /usr/include/features.h /usr/include/stdc-predef.h
lalins.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lalins.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lalins.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lalins.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lalins.o: /usr/include/bits/types/clock_t.h
lalins.o: /usr/include/bits/types/clockid_t.h
lalins.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
lalins.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
lalins.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
lalins.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
lalins.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
lalins.o: /usr/include/bits/types/__sigset_t.h
lalins.o: /usr/include/bits/types/struct_timeval.h
lalins.o: /usr/include/bits/types/struct_timespec.h
lalins.o: /usr/include/bits/pthreadtypes.h
lalins.o: /usr/include/bits/thread-shared-types.h
lalins.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lalins.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lalins.o: /usr/include/bits/types/__fpos_t.h
lalins.o: /usr/include/bits/types/__mbstate_t.h
lalins.o: /usr/include/bits/types/__fpos64_t.h
lalins.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lalins.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
lalins.o: /usr/include/bits/sys_errlist.h
lalpnt.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalpnt.o: /usr/include/features.h /usr/include/stdc-predef.h
lalpnt.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lalpnt.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lalpnt.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lalpnt.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lalpnt.o: /usr/include/bits/types/clock_t.h
lalpnt.o: /usr/include/bits/types/clockid_t.h
lalpnt.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
lalpnt.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
lalpnt.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
lalpnt.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
lalpnt.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
lalpnt.o: /usr/include/bits/types/__sigset_t.h
lalpnt.o: /usr/include/bits/types/struct_timeval.h
lalpnt.o: /usr/include/bits/types/struct_timespec.h
lalpnt.o: /usr/include/bits/pthreadtypes.h
lalpnt.o: /usr/include/bits/thread-shared-types.h
lalpnt.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lalpnt.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lalpnt.o: /usr/include/bits/types/__fpos_t.h
lalpnt.o: /usr/include/bits/types/__mbstate_t.h
lalpnt.o: /usr/include/bits/types/__fpos64_t.h
lalpnt.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lalpnt.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
lalpnt.o: /usr/include/bits/sys_errlist.h
lalrpl.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalrpl.o: /usr/include/features.h /usr/include/stdc-predef.h
lalrpl.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lalrpl.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lalrpl.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lalrpl.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lalrpl.o: /usr/include/bits/types/clock_t.h
lalrpl.o: /usr/include/bits/types/clockid_t.h
lalrpl.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
lalrpl.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
lalrpl.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
lalrpl.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
lalrpl.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
lalrpl.o: /usr/include/bits/types/__sigset_t.h
lalrpl.o: /usr/include/bits/types/struct_timeval.h
lalrpl.o: /usr/include/bits/types/struct_timespec.h
lalrpl.o: /usr/include/bits/pthreadtypes.h
lalrpl.o: /usr/include/bits/thread-shared-types.h
lalrpl.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lalrpl.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lalrpl.o: /usr/include/bits/types/__fpos_t.h
lalrpl.o: /usr/include/bits/types/__mbstate_t.h
lalrpl.o: /usr/include/bits/types/__fpos64_t.h
lalrpl.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lalrpl.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
lalrpl.o: /usr/include/bits/sys_errlist.h
lalrsize.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalrsize.o: /usr/include/features.h /usr/include/stdc-predef.h
lalrsize.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lalrsize.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lalrsize.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lalrsize.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lalrsize.o: /usr/include/bits/types/clock_t.h
lalrsize.o: /usr/include/bits/types/clockid_t.h
lalrsize.o: /usr/include/bits/types/time_t.h
lalrsize.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
lalrsize.o: /usr/include/endian.h /usr/include/bits/endian.h
lalrsize.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
lalrsize.o: /usr/include/sys/select.h /usr/include/bits/select.h
lalrsize.o: /usr/include/bits/types/sigset_t.h
lalrsize.o: /usr/include/bits/types/__sigset_t.h
lalrsize.o: /usr/include/bits/types/struct_timeval.h
lalrsize.o: /usr/include/bits/types/struct_timespec.h
lalrsize.o: /usr/include/bits/pthreadtypes.h
lalrsize.o: /usr/include/bits/thread-shared-types.h
lalrsize.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lalrsize.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lalrsize.o: /usr/include/bits/types/__fpos_t.h
lalrsize.o: /usr/include/bits/types/__mbstate_t.h
lalrsize.o: /usr/include/bits/types/__fpos64_t.h
lalrsize.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lalrsize.o: /usr/include/bits/types/struct_FILE.h
lalrsize.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
lalseek.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalseek.o: /usr/include/features.h /usr/include/stdc-predef.h
lalseek.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lalseek.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lalseek.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lalseek.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lalseek.o: /usr/include/bits/types/clock_t.h
lalseek.o: /usr/include/bits/types/clockid_t.h
lalseek.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
lalseek.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
lalseek.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
lalseek.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
lalseek.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
lalseek.o: /usr/include/bits/types/__sigset_t.h
lalseek.o: /usr/include/bits/types/struct_timeval.h
lalseek.o: /usr/include/bits/types/struct_timespec.h
lalseek.o: /usr/include/bits/pthreadtypes.h
lalseek.o: /usr/include/bits/thread-shared-types.h
lalseek.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lalseek.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lalseek.o: /usr/include/bits/types/__fpos_t.h
lalseek.o: /usr/include/bits/types/__mbstate_t.h
lalseek.o: /usr/include/bits/types/__fpos64_t.h
lalseek.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lalseek.o: /usr/include/bits/types/struct_FILE.h
lalseek.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
lalwsize.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
lalwsize.o: /usr/include/features.h /usr/include/stdc-predef.h
lalwsize.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
lalwsize.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
lalwsize.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
lalwsize.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
lalwsize.o: /usr/include/bits/types/clock_t.h
lalwsize.o: /usr/include/bits/types/clockid_t.h
lalwsize.o: /usr/include/bits/types/time_t.h
lalwsize.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
lalwsize.o: /usr/include/endian.h /usr/include/bits/endian.h
lalwsize.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
lalwsize.o: /usr/include/sys/select.h /usr/include/bits/select.h
lalwsize.o: /usr/include/bits/types/sigset_t.h
lalwsize.o: /usr/include/bits/types/__sigset_t.h
lalwsize.o: /usr/include/bits/types/struct_timeval.h
lalwsize.o: /usr/include/bits/types/struct_timespec.h
lalwsize.o: /usr/include/bits/pthreadtypes.h
lalwsize.o: /usr/include/bits/thread-shared-types.h
lalwsize.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
lalwsize.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
lalwsize.o: /usr/include/bits/types/__fpos_t.h
lalwsize.o: /usr/include/bits/types/__mbstate_t.h
lalwsize.o: /usr/include/bits/types/__fpos64_t.h
lalwsize.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
lalwsize.o: /usr/include/bits/types/struct_FILE.h
lalwsize.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
laopen.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laopen.o: /usr/include/features.h /usr/include/stdc-predef.h
laopen.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
laopen.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
laopen.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
laopen.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
laopen.o: /usr/include/bits/types/clock_t.h
laopen.o: /usr/include/bits/types/clockid_t.h
laopen.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
laopen.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
laopen.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
laopen.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
laopen.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
laopen.o: /usr/include/bits/types/__sigset_t.h
laopen.o: /usr/include/bits/types/struct_timeval.h
laopen.o: /usr/include/bits/types/struct_timespec.h
laopen.o: /usr/include/bits/pthreadtypes.h
laopen.o: /usr/include/bits/thread-shared-types.h
laopen.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
laopen.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
laopen.o: /usr/include/bits/types/__fpos_t.h
laopen.o: /usr/include/bits/types/__mbstate_t.h
laopen.o: /usr/include/bits/types/__fpos64_t.h
laopen.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
laopen.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
laopen.o: /usr/include/bits/sys_errlist.h /usr/include/sys/stat.h
laopen.o: /usr/include/bits/stat.h
laother.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
laother.o: /usr/include/features.h /usr/include/stdc-predef.h
laother.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
laother.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
laother.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
laother.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
laother.o: /usr/include/bits/types/clock_t.h
laother.o: /usr/include/bits/types/clockid_t.h
laother.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
laother.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
laother.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
laother.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
laother.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
laother.o: /usr/include/bits/types/__sigset_t.h
laother.o: /usr/include/bits/types/struct_timeval.h
laother.o: /usr/include/bits/types/struct_timespec.h
laother.o: /usr/include/bits/pthreadtypes.h
laother.o: /usr/include/bits/thread-shared-types.h
laother.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
laother.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
laother.o: /usr/include/bits/types/__fpos_t.h
laother.o: /usr/include/bits/types/__mbstate_t.h
laother.o: /usr/include/bits/types/__fpos64_t.h
laother.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
laother.o: /usr/include/bits/types/struct_FILE.h
laother.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
test.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
test.o: /usr/include/features.h /usr/include/stdc-predef.h
test.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
test.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
test.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
test.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
test.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
test.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
test.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
test.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
test.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
test.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
test.o: /usr/include/bits/types/__sigset_t.h
test.o: /usr/include/bits/types/struct_timeval.h
test.o: /usr/include/bits/types/struct_timespec.h
test.o: /usr/include/bits/pthreadtypes.h
test.o: /usr/include/bits/thread-shared-types.h
test.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
test.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
test.o: /usr/include/bits/types/__fpos_t.h
test.o: /usr/include/bits/types/__mbstate_t.h
test.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
test.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
test.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
test.o: /usr/include/signal.h /usr/include/bits/signum.h
test.o: /usr/include/bits/signum-generic.h
test.o: /usr/include/bits/types/sig_atomic_t.h
test.o: /usr/include/bits/types/siginfo_t.h
test.o: /usr/include/bits/types/__sigval_t.h /usr/include/bits/siginfo-arch.h
test.o: /usr/include/bits/siginfo-consts.h /usr/include/bits/types/sigval_t.h
test.o: /usr/include/bits/types/sigevent_t.h
test.o: /usr/include/bits/sigevent-consts.h /usr/include/bits/sigaction.h
test.o: /usr/include/bits/sigcontext.h /usr/include/bits/types/stack_t.h
test.o: /usr/include/sys/ucontext.h /usr/include/bits/sigstack.h
test.o: /usr/include/bits/ss_flags.h
test.o: /usr/include/bits/types/struct_sigstack.h
test.o: /usr/include/bits/sigthread.h /usr/include/bits/signal_ext.h
test1.o: la.local.h ../include/c_env.h /usr/include/sys/types.h
test1.o: /usr/include/features.h /usr/include/stdc-predef.h
test1.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
test1.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
test1.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
test1.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
test1.o: /usr/include/bits/types/clock_t.h
test1.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
test1.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
test1.o: /usr/include/endian.h /usr/include/bits/endian.h
test1.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
test1.o: /usr/include/sys/select.h /usr/include/bits/select.h
test1.o: /usr/include/bits/types/sigset_t.h
test1.o: /usr/include/bits/types/__sigset_t.h
test1.o: /usr/include/bits/types/struct_timeval.h
test1.o: /usr/include/bits/types/struct_timespec.h
test1.o: /usr/include/bits/pthreadtypes.h
test1.o: /usr/include/bits/thread-shared-types.h
test1.o: /usr/include/bits/pthreadtypes-arch.h la.h ../ff3/ff.h
test1.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
test1.o: /usr/include/bits/types/__fpos_t.h
test1.o: /usr/include/bits/types/__mbstate_t.h
test1.o: /usr/include/bits/types/__fpos64_t.h
test1.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
test1.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
test1.o: /usr/include/bits/sys_errlist.h
