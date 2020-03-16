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

ff.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
ff.o: /usr/include/features.h /usr/include/stdc-predef.h
ff.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
ff.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
ff.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
ff.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
ff.o: /usr/include/bits/types/__fpos_t.h
ff.o: /usr/include/bits/types/__mbstate_t.h
ff.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
ff.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
ff.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
ff.local.o: ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
ff.local.o: /usr/include/features.h /usr/include/stdc-predef.h
ff.local.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
ff.local.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
ff.local.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
ff.local.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
ff.local.o: /usr/include/bits/types/clock_t.h
ff.local.o: /usr/include/bits/types/clockid_t.h
ff.local.o: /usr/include/bits/types/time_t.h
ff.local.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
ff.local.o: /usr/include/endian.h /usr/include/bits/endian.h
ff.local.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
ff.local.o: /usr/include/sys/select.h /usr/include/bits/select.h
ff.local.o: /usr/include/bits/types/sigset_t.h
ff.local.o: /usr/include/bits/types/__sigset_t.h
ff.local.o: /usr/include/bits/types/struct_timeval.h
ff.local.o: /usr/include/bits/types/struct_timespec.h
ff.local.o: /usr/include/bits/pthreadtypes.h
ff.local.o: /usr/include/bits/thread-shared-types.h
ff.local.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
ff.local.o: /usr/include/bits/libc-header-start.h
ff.local.o: /usr/include/bits/types/__fpos_t.h
ff.local.o: /usr/include/bits/types/__mbstate_t.h
ff.local.o: /usr/include/bits/types/__fpos64_t.h
ff.local.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
ff.local.o: /usr/include/bits/types/struct_FILE.h
ff.local.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
close.o: ff.local.h ../include/c_env.h ../include/localenv.h
close.o: /usr/include/sys/types.h /usr/include/features.h
close.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
close.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
close.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
close.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
close.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
close.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
close.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
close.o: /usr/include/endian.h /usr/include/bits/endian.h
close.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
close.o: /usr/include/sys/select.h /usr/include/bits/select.h
close.o: /usr/include/bits/types/sigset_t.h
close.o: /usr/include/bits/types/__sigset_t.h
close.o: /usr/include/bits/types/struct_timeval.h
close.o: /usr/include/bits/types/struct_timespec.h
close.o: /usr/include/bits/pthreadtypes.h
close.o: /usr/include/bits/thread-shared-types.h
close.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
close.o: /usr/include/bits/libc-header-start.h
close.o: /usr/include/bits/types/__fpos_t.h
close.o: /usr/include/bits/types/__mbstate_t.h
close.o: /usr/include/bits/types/__fpos64_t.h
close.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
close.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
close.o: /usr/include/bits/sys_errlist.h /usr/include/errno.h
close.o: /usr/include/bits/errno.h /usr/include/linux/errno.h
close.o: /usr/include/asm/errno.h /usr/include/asm-generic/errno.h
close.o: /usr/include/asm-generic/errno-base.h
fd.o: ff.local.h ../include/c_env.h ../include/localenv.h
fd.o: /usr/include/sys/types.h /usr/include/features.h
fd.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
fd.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
fd.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
fd.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
fd.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
fd.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
fd.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
fd.o: /usr/include/endian.h /usr/include/bits/endian.h
fd.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
fd.o: /usr/include/sys/select.h /usr/include/bits/select.h
fd.o: /usr/include/bits/types/sigset_t.h /usr/include/bits/types/__sigset_t.h
fd.o: /usr/include/bits/types/struct_timeval.h
fd.o: /usr/include/bits/types/struct_timespec.h
fd.o: /usr/include/bits/pthreadtypes.h
fd.o: /usr/include/bits/thread-shared-types.h
fd.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
fd.o: /usr/include/bits/libc-header-start.h
fd.o: /usr/include/bits/types/__fpos_t.h
fd.o: /usr/include/bits/types/__mbstate_t.h
fd.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
fd.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
fd.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
fd.o: /usr/include/errno.h /usr/include/bits/errno.h
fd.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
fd.o: /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h
flush.o: ff.local.h ../include/c_env.h ../include/localenv.h
flush.o: /usr/include/sys/types.h /usr/include/features.h
flush.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
flush.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
flush.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
flush.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
flush.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
flush.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
flush.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
flush.o: /usr/include/endian.h /usr/include/bits/endian.h
flush.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
flush.o: /usr/include/sys/select.h /usr/include/bits/select.h
flush.o: /usr/include/bits/types/sigset_t.h
flush.o: /usr/include/bits/types/__sigset_t.h
flush.o: /usr/include/bits/types/struct_timeval.h
flush.o: /usr/include/bits/types/struct_timespec.h
flush.o: /usr/include/bits/pthreadtypes.h
flush.o: /usr/include/bits/thread-shared-types.h
flush.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
flush.o: /usr/include/bits/libc-header-start.h
flush.o: /usr/include/bits/types/__fpos_t.h
flush.o: /usr/include/bits/types/__mbstate_t.h
flush.o: /usr/include/bits/types/__fpos64_t.h
flush.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
flush.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
flush.o: /usr/include/bits/sys_errlist.h /usr/include/errno.h
flush.o: /usr/include/bits/errno.h /usr/include/linux/errno.h
flush.o: /usr/include/asm/errno.h /usr/include/asm-generic/errno.h
flush.o: /usr/include/asm-generic/errno-base.h
free.o: ff.local.h ../include/c_env.h ../include/localenv.h
free.o: /usr/include/sys/types.h /usr/include/features.h
free.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
free.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
free.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
free.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
free.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
free.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
free.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
free.o: /usr/include/endian.h /usr/include/bits/endian.h
free.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
free.o: /usr/include/sys/select.h /usr/include/bits/select.h
free.o: /usr/include/bits/types/sigset_t.h
free.o: /usr/include/bits/types/__sigset_t.h
free.o: /usr/include/bits/types/struct_timeval.h
free.o: /usr/include/bits/types/struct_timespec.h
free.o: /usr/include/bits/pthreadtypes.h
free.o: /usr/include/bits/thread-shared-types.h
free.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
free.o: /usr/include/bits/libc-header-start.h
free.o: /usr/include/bits/types/__fpos_t.h
free.o: /usr/include/bits/types/__mbstate_t.h
free.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
free.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
free.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
getc.o: ff.local.h ../include/c_env.h ../include/localenv.h
getc.o: /usr/include/sys/types.h /usr/include/features.h
getc.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
getc.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
getc.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
getc.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
getc.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
getc.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
getc.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
getc.o: /usr/include/endian.h /usr/include/bits/endian.h
getc.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
getc.o: /usr/include/sys/select.h /usr/include/bits/select.h
getc.o: /usr/include/bits/types/sigset_t.h
getc.o: /usr/include/bits/types/__sigset_t.h
getc.o: /usr/include/bits/types/struct_timeval.h
getc.o: /usr/include/bits/types/struct_timespec.h
getc.o: /usr/include/bits/pthreadtypes.h
getc.o: /usr/include/bits/thread-shared-types.h
getc.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
getc.o: /usr/include/bits/libc-header-start.h
getc.o: /usr/include/bits/types/__fpos_t.h
getc.o: /usr/include/bits/types/__mbstate_t.h
getc.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
getc.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
getc.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
getc.o: /usr/include/errno.h /usr/include/bits/errno.h
getc.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
getc.o: /usr/include/asm-generic/errno.h
getc.o: /usr/include/asm-generic/errno-base.h
grow.o: ff.local.h ../include/c_env.h ../include/localenv.h
grow.o: /usr/include/sys/types.h /usr/include/features.h
grow.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
grow.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
grow.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
grow.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
grow.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
grow.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
grow.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
grow.o: /usr/include/endian.h /usr/include/bits/endian.h
grow.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
grow.o: /usr/include/sys/select.h /usr/include/bits/select.h
grow.o: /usr/include/bits/types/sigset_t.h
grow.o: /usr/include/bits/types/__sigset_t.h
grow.o: /usr/include/bits/types/struct_timeval.h
grow.o: /usr/include/bits/types/struct_timespec.h
grow.o: /usr/include/bits/pthreadtypes.h
grow.o: /usr/include/bits/thread-shared-types.h
grow.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
grow.o: /usr/include/bits/libc-header-start.h
grow.o: /usr/include/bits/types/__fpos_t.h
grow.o: /usr/include/bits/types/__mbstate_t.h
grow.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
grow.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
grow.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
grow.o: /usr/include/errno.h /usr/include/bits/errno.h
grow.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
grow.o: /usr/include/asm-generic/errno.h
grow.o: /usr/include/asm-generic/errno-base.h
move.o: ../include/c_env.h
open.o: ff.local.h ../include/c_env.h ../include/localenv.h
open.o: /usr/include/sys/types.h /usr/include/features.h
open.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
open.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
open.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
open.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
open.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
open.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
open.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
open.o: /usr/include/endian.h /usr/include/bits/endian.h
open.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
open.o: /usr/include/sys/select.h /usr/include/bits/select.h
open.o: /usr/include/bits/types/sigset_t.h
open.o: /usr/include/bits/types/__sigset_t.h
open.o: /usr/include/bits/types/struct_timeval.h
open.o: /usr/include/bits/types/struct_timespec.h
open.o: /usr/include/bits/pthreadtypes.h
open.o: /usr/include/bits/thread-shared-types.h
open.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
open.o: /usr/include/bits/libc-header-start.h
open.o: /usr/include/bits/types/__fpos_t.h
open.o: /usr/include/bits/types/__mbstate_t.h
open.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
open.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
open.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
open.o: /usr/include/errno.h /usr/include/bits/errno.h
open.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
open.o: /usr/include/asm-generic/errno.h
open.o: /usr/include/asm-generic/errno-base.h /usr/include/sys/stat.h
open.o: /usr/include/bits/stat.h
point.o: ff.local.h ../include/c_env.h ../include/localenv.h
point.o: /usr/include/sys/types.h /usr/include/features.h
point.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
point.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
point.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
point.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
point.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
point.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
point.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
point.o: /usr/include/endian.h /usr/include/bits/endian.h
point.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
point.o: /usr/include/sys/select.h /usr/include/bits/select.h
point.o: /usr/include/bits/types/sigset_t.h
point.o: /usr/include/bits/types/__sigset_t.h
point.o: /usr/include/bits/types/struct_timeval.h
point.o: /usr/include/bits/types/struct_timespec.h
point.o: /usr/include/bits/pthreadtypes.h
point.o: /usr/include/bits/thread-shared-types.h
point.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
point.o: /usr/include/bits/libc-header-start.h
point.o: /usr/include/bits/types/__fpos_t.h
point.o: /usr/include/bits/types/__mbstate_t.h
point.o: /usr/include/bits/types/__fpos64_t.h
point.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
point.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
point.o: /usr/include/bits/sys_errlist.h
pos.o: ff.local.h ../include/c_env.h ../include/localenv.h
pos.o: /usr/include/sys/types.h /usr/include/features.h
pos.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
pos.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
pos.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
pos.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
pos.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
pos.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
pos.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
pos.o: /usr/include/endian.h /usr/include/bits/endian.h
pos.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
pos.o: /usr/include/sys/select.h /usr/include/bits/select.h
pos.o: /usr/include/bits/types/sigset_t.h
pos.o: /usr/include/bits/types/__sigset_t.h
pos.o: /usr/include/bits/types/struct_timeval.h
pos.o: /usr/include/bits/types/struct_timespec.h
pos.o: /usr/include/bits/pthreadtypes.h
pos.o: /usr/include/bits/thread-shared-types.h
pos.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
pos.o: /usr/include/bits/libc-header-start.h
pos.o: /usr/include/bits/types/__fpos_t.h
pos.o: /usr/include/bits/types/__mbstate_t.h
pos.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
pos.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
pos.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
pos.o: /usr/include/errno.h /usr/include/bits/errno.h
pos.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
pos.o: /usr/include/asm-generic/errno.h /usr/include/asm-generic/errno-base.h
putc.o: ff.local.h ../include/c_env.h ../include/localenv.h
putc.o: /usr/include/sys/types.h /usr/include/features.h
putc.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
putc.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
putc.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
putc.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
putc.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
putc.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
putc.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
putc.o: /usr/include/endian.h /usr/include/bits/endian.h
putc.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
putc.o: /usr/include/sys/select.h /usr/include/bits/select.h
putc.o: /usr/include/bits/types/sigset_t.h
putc.o: /usr/include/bits/types/__sigset_t.h
putc.o: /usr/include/bits/types/struct_timeval.h
putc.o: /usr/include/bits/types/struct_timespec.h
putc.o: /usr/include/bits/pthreadtypes.h
putc.o: /usr/include/bits/thread-shared-types.h
putc.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
putc.o: /usr/include/bits/libc-header-start.h
putc.o: /usr/include/bits/types/__fpos_t.h
putc.o: /usr/include/bits/types/__mbstate_t.h
putc.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
putc.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
putc.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
putc.o: /usr/include/errno.h /usr/include/bits/errno.h
putc.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
putc.o: /usr/include/asm-generic/errno.h
putc.o: /usr/include/asm-generic/errno-base.h
read.o: ff.local.h ../include/c_env.h ../include/localenv.h
read.o: /usr/include/sys/types.h /usr/include/features.h
read.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
read.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
read.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
read.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
read.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
read.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
read.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
read.o: /usr/include/endian.h /usr/include/bits/endian.h
read.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
read.o: /usr/include/sys/select.h /usr/include/bits/select.h
read.o: /usr/include/bits/types/sigset_t.h
read.o: /usr/include/bits/types/__sigset_t.h
read.o: /usr/include/bits/types/struct_timeval.h
read.o: /usr/include/bits/types/struct_timespec.h
read.o: /usr/include/bits/pthreadtypes.h
read.o: /usr/include/bits/thread-shared-types.h
read.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
read.o: /usr/include/bits/libc-header-start.h
read.o: /usr/include/bits/types/__fpos_t.h
read.o: /usr/include/bits/types/__mbstate_t.h
read.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
read.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
read.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
read.o: /usr/include/errno.h /usr/include/bits/errno.h
read.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
read.o: /usr/include/asm-generic/errno.h
read.o: /usr/include/asm-generic/errno-base.h
seek.o: ff.local.h ../include/c_env.h ../include/localenv.h
seek.o: /usr/include/sys/types.h /usr/include/features.h
seek.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
seek.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
seek.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
seek.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
seek.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
seek.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
seek.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
seek.o: /usr/include/endian.h /usr/include/bits/endian.h
seek.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
seek.o: /usr/include/sys/select.h /usr/include/bits/select.h
seek.o: /usr/include/bits/types/sigset_t.h
seek.o: /usr/include/bits/types/__sigset_t.h
seek.o: /usr/include/bits/types/struct_timeval.h
seek.o: /usr/include/bits/types/struct_timespec.h
seek.o: /usr/include/bits/pthreadtypes.h
seek.o: /usr/include/bits/thread-shared-types.h
seek.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
seek.o: /usr/include/bits/libc-header-start.h
seek.o: /usr/include/bits/types/__fpos_t.h
seek.o: /usr/include/bits/types/__mbstate_t.h
seek.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
seek.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
seek.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
seek.o: /usr/include/errno.h /usr/include/bits/errno.h
seek.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
seek.o: /usr/include/asm-generic/errno.h
seek.o: /usr/include/asm-generic/errno-base.h
size.o: ff.local.h ../include/c_env.h ../include/localenv.h
size.o: /usr/include/sys/types.h /usr/include/features.h
size.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
size.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
size.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
size.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
size.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
size.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
size.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
size.o: /usr/include/endian.h /usr/include/bits/endian.h
size.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
size.o: /usr/include/sys/select.h /usr/include/bits/select.h
size.o: /usr/include/bits/types/sigset_t.h
size.o: /usr/include/bits/types/__sigset_t.h
size.o: /usr/include/bits/types/struct_timeval.h
size.o: /usr/include/bits/types/struct_timespec.h
size.o: /usr/include/bits/pthreadtypes.h
size.o: /usr/include/bits/thread-shared-types.h
size.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
size.o: /usr/include/bits/libc-header-start.h
size.o: /usr/include/bits/types/__fpos_t.h
size.o: /usr/include/bits/types/__mbstate_t.h
size.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
size.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
size.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
size.o: /usr/include/errno.h /usr/include/bits/errno.h
size.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
size.o: /usr/include/asm-generic/errno.h
size.o: /usr/include/asm-generic/errno-base.h
sort.o: ff.local.h ../include/c_env.h ../include/localenv.h
sort.o: /usr/include/sys/types.h /usr/include/features.h
sort.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
sort.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
sort.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
sort.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
sort.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
sort.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
sort.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
sort.o: /usr/include/endian.h /usr/include/bits/endian.h
sort.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
sort.o: /usr/include/sys/select.h /usr/include/bits/select.h
sort.o: /usr/include/bits/types/sigset_t.h
sort.o: /usr/include/bits/types/__sigset_t.h
sort.o: /usr/include/bits/types/struct_timeval.h
sort.o: /usr/include/bits/types/struct_timespec.h
sort.o: /usr/include/bits/pthreadtypes.h
sort.o: /usr/include/bits/thread-shared-types.h
sort.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
sort.o: /usr/include/bits/libc-header-start.h
sort.o: /usr/include/bits/types/__fpos_t.h
sort.o: /usr/include/bits/types/__mbstate_t.h
sort.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
sort.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
sort.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
sync.o: ff.local.h ../include/c_env.h ../include/localenv.h
sync.o: /usr/include/sys/types.h /usr/include/features.h
sync.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
sync.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
sync.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
sync.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
sync.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
sync.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
sync.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
sync.o: /usr/include/endian.h /usr/include/bits/endian.h
sync.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
sync.o: /usr/include/sys/select.h /usr/include/bits/select.h
sync.o: /usr/include/bits/types/sigset_t.h
sync.o: /usr/include/bits/types/__sigset_t.h
sync.o: /usr/include/bits/types/struct_timeval.h
sync.o: /usr/include/bits/types/struct_timespec.h
sync.o: /usr/include/bits/pthreadtypes.h
sync.o: /usr/include/bits/thread-shared-types.h
sync.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
sync.o: /usr/include/bits/libc-header-start.h
sync.o: /usr/include/bits/types/__fpos_t.h
sync.o: /usr/include/bits/types/__mbstate_t.h
sync.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
sync.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
sync.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
test.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
test.o: /usr/include/features.h /usr/include/stdc-predef.h
test.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
test.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
test.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
test.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
test.o: /usr/include/bits/types/__fpos_t.h
test.o: /usr/include/bits/types/__mbstate_t.h
test.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
test.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
test.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
test.o: ff.local.h ../include/c_env.h ../include/localenv.h
test.o: /usr/include/sys/types.h /usr/include/bits/types/clock_t.h
test.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
test.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
test.o: /usr/include/endian.h /usr/include/bits/endian.h
test.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
test.o: /usr/include/sys/select.h /usr/include/bits/select.h
test.o: /usr/include/bits/types/sigset_t.h
test.o: /usr/include/bits/types/__sigset_t.h
test.o: /usr/include/bits/types/struct_timeval.h
test.o: /usr/include/bits/types/struct_timespec.h
test.o: /usr/include/bits/pthreadtypes.h
test.o: /usr/include/bits/thread-shared-types.h
test.o: /usr/include/bits/pthreadtypes-arch.h ff.h
write.o: ff.local.h ../include/c_env.h ../include/localenv.h
write.o: /usr/include/sys/types.h /usr/include/features.h
write.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
write.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
write.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
write.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
write.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
write.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
write.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
write.o: /usr/include/endian.h /usr/include/bits/endian.h
write.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
write.o: /usr/include/sys/select.h /usr/include/bits/select.h
write.o: /usr/include/bits/types/sigset_t.h
write.o: /usr/include/bits/types/__sigset_t.h
write.o: /usr/include/bits/types/struct_timeval.h
write.o: /usr/include/bits/types/struct_timespec.h
write.o: /usr/include/bits/pthreadtypes.h
write.o: /usr/include/bits/thread-shared-types.h
write.o: /usr/include/bits/pthreadtypes-arch.h ff.h /usr/include/stdio.h
write.o: /usr/include/bits/libc-header-start.h
write.o: /usr/include/bits/types/__fpos_t.h
write.o: /usr/include/bits/types/__mbstate_t.h
write.o: /usr/include/bits/types/__fpos64_t.h
write.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
write.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
write.o: /usr/include/bits/sys_errlist.h /usr/include/errno.h
write.o: /usr/include/bits/errno.h /usr/include/linux/errno.h
write.o: /usr/include/asm/errno.h /usr/include/asm-generic/errno.h
write.o: /usr/include/asm-generic/errno-base.h
