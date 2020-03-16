CC      = gcc -traditional
LIB     = /usr/local/etc
BIN     = /usr/local/bin
OWNER   = bin
EXECS   = fill just center run
SHELLSC = rb

all:    $(EXECS)

install:
	cp $(EXECS) $(LIB)
	cp $(SHELLSC) $(BIN)
	cd $(LIB); chmod 755 $(EXECS); chown $(OWNER) $(EXECS)
clean:
	rm -f $(EXECS)
clobber: clean
	rm -f .es* *%

just:   fill
	ln fill just

depend:
	makedepend $(CFLAGS) *.c
# DO NOT DELETE THIS LINE -- make depend depends on it.

center.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
center.o: /usr/include/features.h /usr/include/stdc-predef.h
center.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
center.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
center.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
center.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
center.o: /usr/include/bits/types/__fpos_t.h
center.o: /usr/include/bits/types/__mbstate_t.h
center.o: /usr/include/bits/types/__fpos64_t.h
center.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
center.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
center.o: /usr/include/bits/sys_errlist.h /usr/include/ctype.h
center.o: /usr/include/endian.h /usr/include/bits/endian.h
center.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
center.o: /usr/include/bits/types/locale_t.h
center.o: /usr/include/bits/types/__locale_t.h /usr/include/sys/types.h
center.o: /usr/include/bits/types/clock_t.h
center.o: /usr/include/bits/types/clockid_t.h
center.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
center.o: /usr/include/bits/stdint-intn.h /usr/include/sys/select.h
center.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
center.o: /usr/include/bits/types/__sigset_t.h
center.o: /usr/include/bits/types/struct_timeval.h
center.o: /usr/include/bits/types/struct_timespec.h
center.o: /usr/include/bits/pthreadtypes.h
center.o: /usr/include/bits/thread-shared-types.h
center.o: /usr/include/bits/pthreadtypes-arch.h /usr/include/sys/ioctl.h
center.o: /usr/include/bits/ioctls.h /usr/include/asm/ioctls.h
center.o: /usr/include/asm-generic/ioctls.h /usr/include/linux/ioctl.h
center.o: /usr/include/asm/ioctl.h /usr/include/asm-generic/ioctl.h
center.o: /usr/include/bits/ioctl-types.h /usr/include/sys/ttydefaults.h
center.o: /usr/include/sys/stat.h /usr/include/bits/stat.h
fill.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
fill.o: /usr/include/features.h /usr/include/stdc-predef.h
fill.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
fill.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
fill.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
fill.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
fill.o: /usr/include/bits/types/__fpos_t.h
fill.o: /usr/include/bits/types/__mbstate_t.h
fill.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
fill.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
fill.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
fill.o: /usr/include/ctype.h /usr/include/endian.h /usr/include/bits/endian.h
fill.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
fill.o: /usr/include/bits/types/locale_t.h
fill.o: /usr/include/bits/types/__locale_t.h /usr/include/sys/types.h
fill.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
fill.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
fill.o: /usr/include/bits/stdint-intn.h /usr/include/sys/select.h
fill.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
fill.o: /usr/include/bits/types/__sigset_t.h
fill.o: /usr/include/bits/types/struct_timeval.h
fill.o: /usr/include/bits/types/struct_timespec.h
fill.o: /usr/include/bits/pthreadtypes.h
fill.o: /usr/include/bits/thread-shared-types.h
fill.o: /usr/include/bits/pthreadtypes-arch.h /usr/include/sys/ioctl.h
fill.o: /usr/include/bits/ioctls.h /usr/include/asm/ioctls.h
fill.o: /usr/include/asm-generic/ioctls.h /usr/include/linux/ioctl.h
fill.o: /usr/include/asm/ioctl.h /usr/include/asm-generic/ioctl.h
fill.o: /usr/include/bits/ioctl-types.h /usr/include/sys/ttydefaults.h
fill.o: /usr/include/sys/stat.h /usr/include/bits/stat.h
run.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
run.o: /usr/include/features.h /usr/include/stdc-predef.h
run.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
run.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
run.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
run.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
run.o: /usr/include/bits/types/__fpos_t.h
run.o: /usr/include/bits/types/__mbstate_t.h
run.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
run.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
run.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
