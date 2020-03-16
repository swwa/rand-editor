#
#	Copyright abandoned, 1983, The Rand Corporation
#

# Rand Editor with LA package
# The following groups go together
#   CFLAGS=-g and LIBC=-lg for debugging on the VAX
#   DEFS=-DTERMCAP and TERMCAP=-ltermcap
#   DEFS=-DPROFILE and PROFILE=-p
#

DFS     = -DUNIXV7 -DTERMCAP -DSYSIII -DNOSOBUF
CCF     = -g -traditional
LDF     = -g
LD      = gcc
CC      = gcc

LOCALINCL = ../include
LA      = ../la1/
LALIB   = ../la1/libla.a
FF      = ../ff3/
FFLIB   = ../ff3/libff.a
MISC    = ../lib
MISCLIB = ../lib/libtmp.a
DEFS    = $(DFS)
# NEWVERSION creates e.r.c
NEWVERSION = newversion
INCL    = -I. -I$(LA) -I$(FF) -I$(LOCALINCL)
SIG_INCL =signal.h
SGTT_INCL =ioctl.h
CFLAGS  = $(CCF) $(DEFS) $(INCL) $(PROFILE)
LDFLAGS = $(LDF)
RM      = rm -f
LIBS    = $(LALIB) $(FFLIB) -ltermcap

HFILES  = \
	e.cm.h \
	e.e.h \
	e.fn.h \
	e.func.h \
	e.h \
	e.inf.h \
	e.m.h \
	e.ru.h \
	e.se.h \
	e.sg.h \
	e.t.h \
	e.tt.h \
	e.wi.h

OFILES  = \
	e.o \
	e.cm.o \
	e.d.o \
	e.e.o \
	e.f.o \
	e.h.o \
	e.iit.o \
	e.it.o \
	e.la.o \
	e.m.o \
	e.main.o \
	e.mk.o \
	e.nm.o \
	e.p.o \
	e.pa.o \
	e.profile.o \
	e.put.o \
	e.q.o \
	e.ra.o \
	e.re.o \
	e.ru.o \
	e.sb.o \
	e.se.o \
	e.sv.o \
	e.t.o \
	e.tb.o \
	e.tt.o \
	e.u.o \
	e.wi.o \
	e.wk.o \
	e.x.o \
	getshort.o \
	getlong.o  \
	putshort.o \
	putlong.o

CFILES  = \
	e.c \
	e.cm.c \
	e.d.c \
	e.e.c \
	e.f.c \
	e.h.c \
	e.iit.c \
	e.it.c \
	e.la.c \
	e.m.c \
	e.main.c \
	e.mk.c \
	e.nm.c \
	e.p.c \
	e.pa.c \
	e.profile.c \
	e.put.c \
	e.q.c \
	e.r.c \
	e.ra.c \
	e.re.c \
	e.ru.c \
	e.sb.c \
	e.se.c \
	e.sv.c \
	e.t.c \
	e.tb.c \
	e.tt.c \
	e.u.c \
	e.wi.c \
	e.wk.c \
	e.x.c \
	getshort.c \
	getlong.c  \
	putshort.c \
	putlong.c

nle:     $(OFILES)
	/bin/sh $(NEWVERSION)
	$(CC) $(CFLAGS) -c e.r.c
	$(LD) -o nle $(LDFLAGS) $(OFILES) e.r.o $(LIBS)

ofiles: $(OFILES)

newrev:
	/bin/sh $(NEWVERSION)
	$(CC) $(CFLAGS) -c e.r.c

$(LALIB):

$(FFLIB):

$(MISCLIB):

# Be sure the defs in "Ifdefs" agree with $(DEFS)
depend:
	makedepend $(CFLAGS) $(HFILES) $(CFILES)

# Be sure the defs in "Ifdefs" agree with $(DEFS)
Comments: $(CFILES)
	Makedoc $(CFILES)

# Be sure the defs in "Ifdefs" agree with $(DEFS)
Calls:  $(CFILES)
	Makecalls $(CFILES)

lint:
	lint $(DEFS) $(INCL) $(CFILES) \
        $(FF)llib-lff.ln \
        $(LA)llib-lla.ln \
	-lc

pres: pres.o $(MISCLIB)
	$(CC)        \
	pres.o \
	$(MISCLIB)
	-mv pres pres.old
	mv a.out pres

clobber:      clean
	$(RM) nle pres pres.old ,* .??*
clean:
	$(RM) $(OFILES) pres.o

# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
# DO NOT DELETE THIS LINE -- make depend depends on it.

e.o: ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.o: /usr/include/features.h /usr/include/stdc-predef.h
e.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.o: /usr/include/bits/types/__sigset_t.h
e.o: /usr/include/bits/types/struct_timeval.h
e.o: /usr/include/bits/types/struct_timespec.h
e.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/thread-shared-types.h
e.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.o: /usr/include/bits/types/__fpos_t.h /usr/include/bits/types/__mbstate_t.h
e.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.sg.o: /usr/include/sys/ioctl.h /usr/include/features.h
e.sg.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
e.sg.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
e.sg.o: /usr/include/gnu/stubs.h /usr/include/bits/ioctls.h
e.sg.o: /usr/include/asm/ioctls.h /usr/include/asm-generic/ioctls.h
e.sg.o: /usr/include/linux/ioctl.h /usr/include/asm/ioctl.h
e.sg.o: /usr/include/asm-generic/ioctl.h /usr/include/bits/ioctl-types.h
e.sg.o: /usr/include/sys/ttydefaults.h /usr/include/termio.h
e.sg.o: /usr/include/termios.h /usr/include/bits/types.h
e.sg.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
e.sg.o: /usr/include/bits/time64.h /usr/include/bits/termios.h
e.sg.o: /usr/include/bits/termios-struct.h /usr/include/bits/termios-c_cc.h
e.sg.o: /usr/include/bits/termios-c_iflag.h
e.sg.o: /usr/include/bits/termios-c_oflag.h /usr/include/bits/termios-baud.h
e.sg.o: /usr/include/bits/termios-c_cflag.h
e.sg.o: /usr/include/bits/termios-c_lflag.h
e.sg.o: /usr/include/bits/termios-tcflow.h /usr/include/bits/termios-misc.h
e.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.o: /usr/include/features.h /usr/include/stdc-predef.h
e.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.o: /usr/include/bits/types/__sigset_t.h
e.o: /usr/include/bits/types/struct_timeval.h
e.o: /usr/include/bits/types/struct_timespec.h
e.o: /usr/include/bits/pthreadtypes.h /usr/include/bits/thread-shared-types.h
e.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.o: /usr/include/bits/types/__fpos_t.h /usr/include/bits/types/__mbstate_t.h
e.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.o: e.e.h e.tt.h e.wi.h e.fn.h e.sg.h /usr/include/sys/ioctl.h
e.o: /usr/include/bits/ioctls.h /usr/include/asm/ioctls.h
e.o: /usr/include/asm-generic/ioctls.h /usr/include/linux/ioctl.h
e.o: /usr/include/asm/ioctl.h /usr/include/asm-generic/ioctl.h
e.o: /usr/include/bits/ioctl-types.h /usr/include/sys/ttydefaults.h
e.o: /usr/include/termio.h /usr/include/termios.h /usr/include/bits/termios.h
e.o: /usr/include/bits/termios-struct.h /usr/include/bits/termios-c_cc.h
e.o: /usr/include/bits/termios-c_iflag.h /usr/include/bits/termios-c_oflag.h
e.o: /usr/include/bits/termios-baud.h /usr/include/bits/termios-c_cflag.h
e.o: /usr/include/bits/termios-c_lflag.h /usr/include/bits/termios-tcflow.h
e.o: /usr/include/bits/termios-misc.h e.inf.h /usr/include/sys/stat.h
e.o: /usr/include/bits/stat.h /usr/include/fcntl.h /usr/include/bits/fcntl.h
e.o: /usr/include/bits/fcntl-linux.h
e.cm.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.cm.o: /usr/include/features.h /usr/include/stdc-predef.h
e.cm.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.cm.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.cm.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.cm.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.cm.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.cm.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.cm.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.cm.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.cm.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.cm.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.cm.o: /usr/include/bits/types/__sigset_t.h
e.cm.o: /usr/include/bits/types/struct_timeval.h
e.cm.o: /usr/include/bits/types/struct_timespec.h
e.cm.o: /usr/include/bits/pthreadtypes.h
e.cm.o: /usr/include/bits/thread-shared-types.h
e.cm.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.cm.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.cm.o: /usr/include/bits/types/__fpos_t.h
e.cm.o: /usr/include/bits/types/__mbstate_t.h
e.cm.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.cm.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.cm.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.cm.o: e.e.h e.m.h e.ru.h e.cm.h e.wi.h e.tt.h
e.d.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.d.o: /usr/include/features.h /usr/include/stdc-predef.h
e.d.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.d.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.d.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.d.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.d.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.d.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.d.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.d.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.d.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.d.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.d.o: /usr/include/bits/types/__sigset_t.h
e.d.o: /usr/include/bits/types/struct_timeval.h
e.d.o: /usr/include/bits/types/struct_timespec.h
e.d.o: /usr/include/bits/pthreadtypes.h
e.d.o: /usr/include/bits/thread-shared-types.h
e.d.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.d.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.d.o: /usr/include/bits/types/__fpos_t.h
e.d.o: /usr/include/bits/types/__mbstate_t.h
e.d.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.d.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.d.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.d.o: e.tt.h
e.e.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.e.o: /usr/include/features.h /usr/include/stdc-predef.h
e.e.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.e.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.e.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.e.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.e.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.e.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.e.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.e.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.e.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.e.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.e.o: /usr/include/bits/types/__sigset_t.h
e.e.o: /usr/include/bits/types/struct_timeval.h
e.e.o: /usr/include/bits/types/struct_timespec.h
e.e.o: /usr/include/bits/pthreadtypes.h
e.e.o: /usr/include/bits/thread-shared-types.h
e.e.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.e.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.e.o: /usr/include/bits/types/__fpos_t.h
e.e.o: /usr/include/bits/types/__mbstate_t.h
e.e.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.e.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.e.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.e.o: e.m.h e.cm.h e.e.h
e.f.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.f.o: /usr/include/features.h /usr/include/stdc-predef.h
e.f.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.f.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.f.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.f.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.f.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.f.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.f.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.f.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.f.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.f.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.f.o: /usr/include/bits/types/__sigset_t.h
e.f.o: /usr/include/bits/types/struct_timeval.h
e.f.o: /usr/include/bits/types/struct_timespec.h
e.f.o: /usr/include/bits/pthreadtypes.h
e.f.o: /usr/include/bits/thread-shared-types.h
e.f.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.f.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.f.o: /usr/include/bits/types/__fpos_t.h
e.f.o: /usr/include/bits/types/__mbstate_t.h
e.f.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.f.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.f.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.f.o: /usr/include/sys/stat.h /usr/include/bits/stat.h
e.h.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.h.o: /usr/include/features.h /usr/include/stdc-predef.h
e.h.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.h.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.h.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.h.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.h.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.h.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.h.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.h.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.h.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.h.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.h.o: /usr/include/bits/types/__sigset_t.h
e.h.o: /usr/include/bits/types/struct_timeval.h
e.h.o: /usr/include/bits/types/struct_timespec.h
e.h.o: /usr/include/bits/pthreadtypes.h
e.h.o: /usr/include/bits/thread-shared-types.h
e.h.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.h.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.h.o: /usr/include/bits/types/__fpos_t.h
e.h.o: /usr/include/bits/types/__mbstate_t.h
e.h.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.h.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.h.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.h.o: e.cm.h e.m.h e.tt.h e.h.h
e.iit.o: e.h ../include/c_env.h ../include/localenv.h
e.iit.o: /usr/include/sys/types.h /usr/include/features.h
e.iit.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
e.iit.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
e.iit.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
e.iit.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
e.iit.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
e.iit.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
e.iit.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
e.iit.o: /usr/include/endian.h /usr/include/bits/endian.h
e.iit.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
e.iit.o: /usr/include/sys/select.h /usr/include/bits/select.h
e.iit.o: /usr/include/bits/types/sigset_t.h
e.iit.o: /usr/include/bits/types/__sigset_t.h
e.iit.o: /usr/include/bits/types/struct_timeval.h
e.iit.o: /usr/include/bits/types/struct_timespec.h
e.iit.o: /usr/include/bits/pthreadtypes.h
e.iit.o: /usr/include/bits/thread-shared-types.h
e.iit.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.iit.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.iit.o: /usr/include/bits/types/__fpos_t.h
e.iit.o: /usr/include/bits/types/__mbstate_t.h
e.iit.o: /usr/include/bits/types/__fpos64_t.h
e.iit.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
e.iit.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
e.iit.o: /usr/include/bits/sys_errlist.h e.t.h
e.it.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.it.o: /usr/include/features.h /usr/include/stdc-predef.h
e.it.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.it.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.it.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.it.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.it.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.it.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.it.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.it.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.it.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.it.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.it.o: /usr/include/bits/types/__sigset_t.h
e.it.o: /usr/include/bits/types/struct_timeval.h
e.it.o: /usr/include/bits/types/struct_timespec.h
e.it.o: /usr/include/bits/pthreadtypes.h
e.it.o: /usr/include/bits/thread-shared-types.h
e.it.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.it.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.it.o: /usr/include/bits/types/__fpos_t.h
e.it.o: /usr/include/bits/types/__mbstate_t.h
e.it.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.it.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.it.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.la.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.la.o: /usr/include/features.h /usr/include/stdc-predef.h
e.la.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.la.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.la.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.la.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.la.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.la.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.la.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.la.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.la.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.la.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.la.o: /usr/include/bits/types/__sigset_t.h
e.la.o: /usr/include/bits/types/struct_timeval.h
e.la.o: /usr/include/bits/types/struct_timespec.h
e.la.o: /usr/include/bits/pthreadtypes.h
e.la.o: /usr/include/bits/thread-shared-types.h
e.la.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.la.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.la.o: /usr/include/bits/types/__fpos_t.h
e.la.o: /usr/include/bits/types/__mbstate_t.h
e.la.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.la.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.la.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.la.o: e.m.h
e.m.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.m.o: /usr/include/features.h /usr/include/stdc-predef.h
e.m.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.m.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.m.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.m.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.m.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.m.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.m.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.m.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.m.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.m.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.m.o: /usr/include/bits/types/__sigset_t.h
e.m.o: /usr/include/bits/types/struct_timeval.h
e.m.o: /usr/include/bits/types/struct_timespec.h
e.m.o: /usr/include/bits/pthreadtypes.h
e.m.o: /usr/include/bits/thread-shared-types.h
e.m.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.m.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.m.o: /usr/include/bits/types/__fpos_t.h
e.m.o: /usr/include/bits/types/__mbstate_t.h
e.m.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.m.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.m.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.m.o: e.cm.h e.inf.h e.m.h e.tt.h e.e.h
e.main.o: e.h ../include/c_env.h ../include/localenv.h
e.main.o: /usr/include/sys/types.h /usr/include/features.h
e.main.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
e.main.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
e.main.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
e.main.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
e.main.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
e.main.o: /usr/include/bits/types/clockid_t.h
e.main.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.main.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.main.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.main.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.main.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.main.o: /usr/include/bits/types/__sigset_t.h
e.main.o: /usr/include/bits/types/struct_timeval.h
e.main.o: /usr/include/bits/types/struct_timespec.h
e.main.o: /usr/include/bits/pthreadtypes.h
e.main.o: /usr/include/bits/thread-shared-types.h
e.main.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.main.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.main.o: /usr/include/bits/types/__fpos_t.h
e.main.o: /usr/include/bits/types/__mbstate_t.h
e.main.o: /usr/include/bits/types/__fpos64_t.h
e.main.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
e.main.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
e.main.o: /usr/include/bits/sys_errlist.h e.t.h
e.mk.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.mk.o: /usr/include/features.h /usr/include/stdc-predef.h
e.mk.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.mk.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.mk.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.mk.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.mk.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.mk.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.mk.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.mk.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.mk.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.mk.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.mk.o: /usr/include/bits/types/__sigset_t.h
e.mk.o: /usr/include/bits/types/struct_timeval.h
e.mk.o: /usr/include/bits/types/struct_timespec.h
e.mk.o: /usr/include/bits/pthreadtypes.h
e.mk.o: /usr/include/bits/thread-shared-types.h
e.mk.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.mk.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.mk.o: /usr/include/bits/types/__fpos_t.h
e.mk.o: /usr/include/bits/types/__mbstate_t.h
e.mk.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.mk.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.mk.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.mk.o: e.inf.h e.m.h
e.nm.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.nm.o: /usr/include/features.h /usr/include/stdc-predef.h
e.nm.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.nm.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.nm.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.nm.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.nm.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.nm.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.nm.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.nm.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.nm.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.nm.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.nm.o: /usr/include/bits/types/__sigset_t.h
e.nm.o: /usr/include/bits/types/struct_timeval.h
e.nm.o: /usr/include/bits/types/struct_timespec.h
e.nm.o: /usr/include/bits/pthreadtypes.h
e.nm.o: /usr/include/bits/thread-shared-types.h
e.nm.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.nm.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.nm.o: /usr/include/bits/types/__fpos_t.h
e.nm.o: /usr/include/bits/types/__mbstate_t.h
e.nm.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.nm.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.nm.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.nm.o: e.inf.h e.m.h e.cm.h /usr/include/sys/stat.h /usr/include/bits/stat.h
e.p.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.p.o: /usr/include/features.h /usr/include/stdc-predef.h
e.p.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.p.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.p.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.p.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.p.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.p.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.p.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.p.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.p.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.p.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.p.o: /usr/include/bits/types/__sigset_t.h
e.p.o: /usr/include/bits/types/struct_timeval.h
e.p.o: /usr/include/bits/types/struct_timespec.h
e.p.o: /usr/include/bits/pthreadtypes.h
e.p.o: /usr/include/bits/thread-shared-types.h
e.p.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.p.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.p.o: /usr/include/bits/types/__fpos_t.h
e.p.o: /usr/include/bits/types/__mbstate_t.h
e.p.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.p.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.p.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.p.o: e.cm.h e.inf.h e.m.h /usr/include/ctype.h
e.p.o: /usr/include/bits/types/locale_t.h
e.p.o: /usr/include/bits/types/__locale_t.h
e.pa.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.pa.o: /usr/include/features.h /usr/include/stdc-predef.h
e.pa.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.pa.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.pa.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.pa.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.pa.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.pa.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.pa.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.pa.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.pa.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.pa.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.pa.o: /usr/include/bits/types/__sigset_t.h
e.pa.o: /usr/include/bits/types/struct_timeval.h
e.pa.o: /usr/include/bits/types/struct_timespec.h
e.pa.o: /usr/include/bits/pthreadtypes.h
e.pa.o: /usr/include/bits/thread-shared-types.h
e.pa.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.pa.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.pa.o: /usr/include/bits/types/__fpos_t.h
e.pa.o: /usr/include/bits/types/__mbstate_t.h
e.pa.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.pa.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.pa.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.pa.o: /usr/include/ctype.h /usr/include/bits/types/locale_t.h
e.pa.o: /usr/include/bits/types/__locale_t.h e.m.h e.cm.h
e.profile.o: e.h ../include/c_env.h ../include/localenv.h
e.profile.o: /usr/include/sys/types.h /usr/include/features.h
e.profile.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
e.profile.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
e.profile.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
e.profile.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
e.profile.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
e.profile.o: /usr/include/bits/types/clockid_t.h
e.profile.o: /usr/include/bits/types/time_t.h
e.profile.o: /usr/include/bits/types/timer_t.h
e.profile.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.profile.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.profile.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.profile.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.profile.o: /usr/include/bits/types/__sigset_t.h
e.profile.o: /usr/include/bits/types/struct_timeval.h
e.profile.o: /usr/include/bits/types/struct_timespec.h
e.profile.o: /usr/include/bits/pthreadtypes.h
e.profile.o: /usr/include/bits/thread-shared-types.h
e.profile.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.profile.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.profile.o: /usr/include/bits/types/__fpos_t.h
e.profile.o: /usr/include/bits/types/__mbstate_t.h
e.profile.o: /usr/include/bits/types/__fpos64_t.h
e.profile.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
e.profile.o: /usr/include/bits/types/struct_FILE.h
e.profile.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
e.profile.o: e.t.h e.m.h /usr/include/sys/stat.h /usr/include/bits/stat.h
e.profile.o: e.tt.h
e.put.o: e.h ../include/c_env.h ../include/localenv.h
e.put.o: /usr/include/sys/types.h /usr/include/features.h
e.put.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
e.put.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
e.put.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
e.put.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
e.put.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
e.put.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
e.put.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
e.put.o: /usr/include/endian.h /usr/include/bits/endian.h
e.put.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
e.put.o: /usr/include/sys/select.h /usr/include/bits/select.h
e.put.o: /usr/include/bits/types/sigset_t.h
e.put.o: /usr/include/bits/types/__sigset_t.h
e.put.o: /usr/include/bits/types/struct_timeval.h
e.put.o: /usr/include/bits/types/struct_timespec.h
e.put.o: /usr/include/bits/pthreadtypes.h
e.put.o: /usr/include/bits/thread-shared-types.h
e.put.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.put.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.put.o: /usr/include/bits/types/__fpos_t.h
e.put.o: /usr/include/bits/types/__mbstate_t.h
e.put.o: /usr/include/bits/types/__fpos64_t.h
e.put.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
e.put.o: /usr/include/bits/types/struct_FILE.h /usr/include/bits/stdio_lim.h
e.put.o: /usr/include/bits/sys_errlist.h e.t.h e.m.h e.cm.h e.e.h
e.q.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.q.o: /usr/include/features.h /usr/include/stdc-predef.h
e.q.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.q.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.q.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.q.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.q.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.q.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.q.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.q.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.q.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.q.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.q.o: /usr/include/bits/types/__sigset_t.h
e.q.o: /usr/include/bits/types/struct_timeval.h
e.q.o: /usr/include/bits/types/struct_timespec.h
e.q.o: /usr/include/bits/pthreadtypes.h
e.q.o: /usr/include/bits/thread-shared-types.h
e.q.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.q.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.q.o: /usr/include/bits/types/__fpos_t.h
e.q.o: /usr/include/bits/types/__mbstate_t.h
e.q.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.q.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.q.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.q.o: e.m.h e.cm.h e.fn.h e.tt.h
e.ra.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.ra.o: /usr/include/features.h /usr/include/stdc-predef.h
e.ra.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.ra.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.ra.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.ra.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.ra.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.ra.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.ra.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.ra.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.ra.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.ra.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.ra.o: /usr/include/bits/types/__sigset_t.h
e.ra.o: /usr/include/bits/types/struct_timeval.h
e.ra.o: /usr/include/bits/types/struct_timespec.h
e.ra.o: /usr/include/bits/pthreadtypes.h
e.ra.o: /usr/include/bits/thread-shared-types.h
e.ra.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.ra.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.ra.o: /usr/include/bits/types/__fpos_t.h
e.ra.o: /usr/include/bits/types/__mbstate_t.h
e.ra.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.ra.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.ra.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.ra.o: e.m.h e.cm.h
e.re.o: /usr/include/ctype.h /usr/include/features.h
e.re.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
e.re.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
e.re.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
e.re.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
e.re.o: /usr/include/bits/time64.h /usr/include/endian.h
e.re.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.re.o: /usr/include/bits/uintn-identity.h /usr/include/bits/types/locale_t.h
e.re.o: /usr/include/bits/types/__locale_t.h e.h ../include/c_env.h
e.re.o: ../include/localenv.h /usr/include/sys/types.h
e.re.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.re.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.re.o: /usr/include/bits/stdint-intn.h /usr/include/sys/select.h
e.re.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.re.o: /usr/include/bits/types/__sigset_t.h
e.re.o: /usr/include/bits/types/struct_timeval.h
e.re.o: /usr/include/bits/types/struct_timespec.h
e.re.o: /usr/include/bits/pthreadtypes.h
e.re.o: /usr/include/bits/thread-shared-types.h
e.re.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.re.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.re.o: /usr/include/bits/types/__fpos_t.h
e.re.o: /usr/include/bits/types/__mbstate_t.h
e.re.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.re.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.re.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.re.o: e.m.h e.cm.h e.se.h
e.ru.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.ru.o: /usr/include/features.h /usr/include/stdc-predef.h
e.ru.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.ru.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.ru.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.ru.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.ru.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.ru.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.ru.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.ru.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.ru.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.ru.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.ru.o: /usr/include/bits/types/__sigset_t.h
e.ru.o: /usr/include/bits/types/struct_timeval.h
e.ru.o: /usr/include/bits/types/struct_timespec.h
e.ru.o: /usr/include/bits/pthreadtypes.h
e.ru.o: /usr/include/bits/thread-shared-types.h
e.ru.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.ru.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.ru.o: /usr/include/bits/types/__fpos_t.h
e.ru.o: /usr/include/bits/types/__mbstate_t.h
e.ru.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.ru.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.ru.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.ru.o: e.e.h e.m.h e.cm.h e.ru.h
e.sb.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.sb.o: /usr/include/features.h /usr/include/stdc-predef.h
e.sb.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.sb.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.sb.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.sb.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.sb.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.sb.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.sb.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.sb.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.sb.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.sb.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.sb.o: /usr/include/bits/types/__sigset_t.h
e.sb.o: /usr/include/bits/types/struct_timeval.h
e.sb.o: /usr/include/bits/types/struct_timespec.h
e.sb.o: /usr/include/bits/pthreadtypes.h
e.sb.o: /usr/include/bits/thread-shared-types.h
e.sb.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.sb.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.sb.o: /usr/include/bits/types/__fpos_t.h
e.sb.o: /usr/include/bits/types/__mbstate_t.h
e.sb.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.sb.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.sb.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.sb.o: e.fn.h e.sg.h /usr/include/sys/ioctl.h /usr/include/bits/ioctls.h
e.sb.o: /usr/include/asm/ioctls.h /usr/include/asm-generic/ioctls.h
e.sb.o: /usr/include/linux/ioctl.h /usr/include/asm/ioctl.h
e.sb.o: /usr/include/asm-generic/ioctl.h /usr/include/bits/ioctl-types.h
e.sb.o: /usr/include/sys/ttydefaults.h /usr/include/termio.h
e.sb.o: /usr/include/termios.h /usr/include/bits/termios.h
e.sb.o: /usr/include/bits/termios-struct.h /usr/include/bits/termios-c_cc.h
e.sb.o: /usr/include/bits/termios-c_iflag.h
e.sb.o: /usr/include/bits/termios-c_oflag.h /usr/include/bits/termios-baud.h
e.sb.o: /usr/include/bits/termios-c_cflag.h
e.sb.o: /usr/include/bits/termios-c_lflag.h
e.sb.o: /usr/include/bits/termios-tcflow.h /usr/include/bits/termios-misc.h
e.sb.o: /usr/include/pwd.h /usr/include/sys/stat.h /usr/include/bits/stat.h
e.sb.o: /usr/include/fcntl.h /usr/include/bits/fcntl.h
e.sb.o: /usr/include/bits/fcntl-linux.h
e.se.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.se.o: /usr/include/features.h /usr/include/stdc-predef.h
e.se.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.se.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.se.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.se.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.se.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.se.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.se.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.se.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.se.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.se.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.se.o: /usr/include/bits/types/__sigset_t.h
e.se.o: /usr/include/bits/types/struct_timeval.h
e.se.o: /usr/include/bits/types/struct_timespec.h
e.se.o: /usr/include/bits/pthreadtypes.h
e.se.o: /usr/include/bits/thread-shared-types.h
e.se.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.se.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.se.o: /usr/include/bits/types/__fpos_t.h
e.se.o: /usr/include/bits/types/__mbstate_t.h
e.se.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.se.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.se.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.se.o: /usr/include/ctype.h /usr/include/bits/types/locale_t.h
e.se.o: /usr/include/bits/types/__locale_t.h e.m.h e.cm.h e.se.h
e.sv.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.sv.o: /usr/include/features.h /usr/include/stdc-predef.h
e.sv.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.sv.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.sv.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.sv.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.sv.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.sv.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.sv.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.sv.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.sv.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.sv.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.sv.o: /usr/include/bits/types/__sigset_t.h
e.sv.o: /usr/include/bits/types/struct_timeval.h
e.sv.o: /usr/include/bits/types/struct_timespec.h
e.sv.o: /usr/include/bits/pthreadtypes.h
e.sv.o: /usr/include/bits/thread-shared-types.h
e.sv.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.sv.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.sv.o: /usr/include/bits/types/__fpos_t.h
e.sv.o: /usr/include/bits/types/__mbstate_t.h
e.sv.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.sv.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.sv.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.sv.o: e.m.h e.cm.h /usr/include/sys/stat.h /usr/include/bits/stat.h
e.t.o: ../include/varargs.h e.h ../include/c_env.h ../include/localenv.h
e.t.o: /usr/include/sys/types.h /usr/include/features.h
e.t.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
e.t.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
e.t.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
e.t.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
e.t.o: /usr/include/bits/time64.h /usr/include/bits/types/clock_t.h
e.t.o: /usr/include/bits/types/clockid_t.h /usr/include/bits/types/time_t.h
e.t.o: /usr/include/bits/types/timer_t.h /usr/include/bits/stdint-intn.h
e.t.o: /usr/include/endian.h /usr/include/bits/endian.h
e.t.o: /usr/include/bits/byteswap.h /usr/include/bits/uintn-identity.h
e.t.o: /usr/include/sys/select.h /usr/include/bits/select.h
e.t.o: /usr/include/bits/types/sigset_t.h
e.t.o: /usr/include/bits/types/__sigset_t.h
e.t.o: /usr/include/bits/types/struct_timeval.h
e.t.o: /usr/include/bits/types/struct_timespec.h
e.t.o: /usr/include/bits/pthreadtypes.h
e.t.o: /usr/include/bits/thread-shared-types.h
e.t.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.t.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.t.o: /usr/include/bits/types/__fpos_t.h
e.t.o: /usr/include/bits/types/__mbstate_t.h
e.t.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.t.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.t.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.t.o: e.inf.h e.m.h e.tt.h e.wi.h
e.tb.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.tb.o: /usr/include/features.h /usr/include/stdc-predef.h
e.tb.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.tb.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.tb.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.tb.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.tb.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.tb.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.tb.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.tb.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.tb.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.tb.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.tb.o: /usr/include/bits/types/__sigset_t.h
e.tb.o: /usr/include/bits/types/struct_timeval.h
e.tb.o: /usr/include/bits/types/struct_timespec.h
e.tb.o: /usr/include/bits/pthreadtypes.h
e.tb.o: /usr/include/bits/thread-shared-types.h
e.tb.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.tb.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.tb.o: /usr/include/bits/types/__fpos_t.h
e.tb.o: /usr/include/bits/types/__mbstate_t.h
e.tb.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.tb.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.tb.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.tb.o: e.m.h e.cm.h
e.tt.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.tt.o: /usr/include/features.h /usr/include/stdc-predef.h
e.tt.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.tt.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.tt.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.tt.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.tt.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.tt.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.tt.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.tt.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.tt.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.tt.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.tt.o: /usr/include/bits/types/__sigset_t.h
e.tt.o: /usr/include/bits/types/struct_timeval.h
e.tt.o: /usr/include/bits/types/struct_timespec.h
e.tt.o: /usr/include/bits/pthreadtypes.h
e.tt.o: /usr/include/bits/thread-shared-types.h
e.tt.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.tt.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.tt.o: /usr/include/bits/types/__fpos_t.h
e.tt.o: /usr/include/bits/types/__mbstate_t.h
e.tt.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.tt.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.tt.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.tt.o: e.tt.h e.sg.h /usr/include/sys/ioctl.h /usr/include/bits/ioctls.h
e.tt.o: /usr/include/asm/ioctls.h /usr/include/asm-generic/ioctls.h
e.tt.o: /usr/include/linux/ioctl.h /usr/include/asm/ioctl.h
e.tt.o: /usr/include/asm-generic/ioctl.h /usr/include/bits/ioctl-types.h
e.tt.o: /usr/include/sys/ttydefaults.h /usr/include/termio.h
e.tt.o: /usr/include/termios.h /usr/include/bits/termios.h
e.tt.o: /usr/include/bits/termios-struct.h /usr/include/bits/termios-c_cc.h
e.tt.o: /usr/include/bits/termios-c_iflag.h
e.tt.o: /usr/include/bits/termios-c_oflag.h /usr/include/bits/termios-baud.h
e.tt.o: /usr/include/bits/termios-c_cflag.h
e.tt.o: /usr/include/bits/termios-c_lflag.h
e.tt.o: /usr/include/bits/termios-tcflow.h /usr/include/bits/termios-misc.h
e.tt.o: term/standard.c term/tcap.c term/vt100.c term/vt52.c term/sun.c
e.tt.o: term/xterm.c
e.u.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.u.o: /usr/include/features.h /usr/include/stdc-predef.h
e.u.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.u.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.u.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.u.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.u.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.u.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.u.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.u.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.u.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.u.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.u.o: /usr/include/bits/types/__sigset_t.h
e.u.o: /usr/include/bits/types/struct_timeval.h
e.u.o: /usr/include/bits/types/struct_timespec.h
e.u.o: /usr/include/bits/pthreadtypes.h
e.u.o: /usr/include/bits/thread-shared-types.h
e.u.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.u.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.u.o: /usr/include/bits/types/__fpos_t.h
e.u.o: /usr/include/bits/types/__mbstate_t.h
e.u.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.u.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.u.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.u.o: e.m.h e.cm.h /usr/include/sys/stat.h /usr/include/bits/stat.h
e.u.o: /usr/include/pwd.h
e.wi.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.wi.o: /usr/include/features.h /usr/include/stdc-predef.h
e.wi.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.wi.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.wi.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.wi.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.wi.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.wi.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.wi.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.wi.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.wi.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.wi.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.wi.o: /usr/include/bits/types/__sigset_t.h
e.wi.o: /usr/include/bits/types/struct_timeval.h
e.wi.o: /usr/include/bits/types/struct_timespec.h
e.wi.o: /usr/include/bits/pthreadtypes.h
e.wi.o: /usr/include/bits/thread-shared-types.h
e.wi.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.wi.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.wi.o: /usr/include/bits/types/__fpos_t.h
e.wi.o: /usr/include/bits/types/__mbstate_t.h
e.wi.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.wi.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.wi.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.wi.o: e.cm.h e.inf.h e.tt.h e.wi.h
e.wk.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.wk.o: /usr/include/features.h /usr/include/stdc-predef.h
e.wk.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.wk.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.wk.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.wk.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.wk.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.wk.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.wk.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.wk.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.wk.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.wk.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.wk.o: /usr/include/bits/types/__sigset_t.h
e.wk.o: /usr/include/bits/types/struct_timeval.h
e.wk.o: /usr/include/bits/types/struct_timespec.h
e.wk.o: /usr/include/bits/pthreadtypes.h
e.wk.o: /usr/include/bits/thread-shared-types.h
e.wk.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.wk.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.wk.o: /usr/include/bits/types/__fpos_t.h
e.wk.o: /usr/include/bits/types/__mbstate_t.h
e.wk.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.wk.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.wk.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.wk.o: e.inf.h
e.x.o: e.h ../include/c_env.h ../include/localenv.h /usr/include/sys/types.h
e.x.o: /usr/include/features.h /usr/include/stdc-predef.h
e.x.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
e.x.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
e.x.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
e.x.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
e.x.o: /usr/include/bits/types/clock_t.h /usr/include/bits/types/clockid_t.h
e.x.o: /usr/include/bits/types/time_t.h /usr/include/bits/types/timer_t.h
e.x.o: /usr/include/bits/stdint-intn.h /usr/include/endian.h
e.x.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
e.x.o: /usr/include/bits/uintn-identity.h /usr/include/sys/select.h
e.x.o: /usr/include/bits/select.h /usr/include/bits/types/sigset_t.h
e.x.o: /usr/include/bits/types/__sigset_t.h
e.x.o: /usr/include/bits/types/struct_timeval.h
e.x.o: /usr/include/bits/types/struct_timespec.h
e.x.o: /usr/include/bits/pthreadtypes.h
e.x.o: /usr/include/bits/thread-shared-types.h
e.x.o: /usr/include/bits/pthreadtypes-arch.h ../la1/la.h ../ff3/ff.h
e.x.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
e.x.o: /usr/include/bits/types/__fpos_t.h
e.x.o: /usr/include/bits/types/__mbstate_t.h
e.x.o: /usr/include/bits/types/__fpos64_t.h /usr/include/bits/types/__FILE.h
e.x.o: /usr/include/bits/types/FILE.h /usr/include/bits/types/struct_FILE.h
e.x.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h e.t.h
e.x.o: e.e.h e.inf.h e.m.h e.sg.h /usr/include/sys/ioctl.h
e.x.o: /usr/include/bits/ioctls.h /usr/include/asm/ioctls.h
e.x.o: /usr/include/asm-generic/ioctls.h /usr/include/linux/ioctl.h
e.x.o: /usr/include/asm/ioctl.h /usr/include/asm-generic/ioctl.h
e.x.o: /usr/include/bits/ioctl-types.h /usr/include/sys/ttydefaults.h
e.x.o: /usr/include/termio.h /usr/include/termios.h
e.x.o: /usr/include/bits/termios.h /usr/include/bits/termios-struct.h
e.x.o: /usr/include/bits/termios-c_cc.h /usr/include/bits/termios-c_iflag.h
e.x.o: /usr/include/bits/termios-c_oflag.h /usr/include/bits/termios-baud.h
e.x.o: /usr/include/bits/termios-c_cflag.h
e.x.o: /usr/include/bits/termios-c_lflag.h /usr/include/bits/termios-tcflow.h
e.x.o: /usr/include/bits/termios-misc.h
getshort.o: ../include/localenv.h /usr/include/stdio.h
getshort.o: /usr/include/bits/libc-header-start.h /usr/include/features.h
getshort.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
getshort.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
getshort.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
getshort.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
getshort.o: /usr/include/bits/time64.h /usr/include/bits/types/__fpos_t.h
getshort.o: /usr/include/bits/types/__mbstate_t.h
getshort.o: /usr/include/bits/types/__fpos64_t.h
getshort.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
getshort.o: /usr/include/bits/types/struct_FILE.h
getshort.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
getlong.o: ../include/localenv.h /usr/include/stdio.h
getlong.o: /usr/include/bits/libc-header-start.h /usr/include/features.h
getlong.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
getlong.o: /usr/include/bits/wordsize.h /usr/include/bits/long-double.h
getlong.o: /usr/include/gnu/stubs.h /usr/include/bits/types.h
getlong.o: /usr/include/bits/timesize.h /usr/include/bits/typesizes.h
getlong.o: /usr/include/bits/time64.h /usr/include/bits/types/__fpos_t.h
getlong.o: /usr/include/bits/types/__mbstate_t.h
getlong.o: /usr/include/bits/types/__fpos64_t.h
getlong.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
getlong.o: /usr/include/bits/types/struct_FILE.h
getlong.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
putshort.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
putshort.o: /usr/include/features.h /usr/include/stdc-predef.h
putshort.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
putshort.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
putshort.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
putshort.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
putshort.o: /usr/include/bits/types/__fpos_t.h
putshort.o: /usr/include/bits/types/__mbstate_t.h
putshort.o: /usr/include/bits/types/__fpos64_t.h
putshort.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
putshort.o: /usr/include/bits/types/struct_FILE.h
putshort.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
putlong.o: /usr/include/stdio.h /usr/include/bits/libc-header-start.h
putlong.o: /usr/include/features.h /usr/include/stdc-predef.h
putlong.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
putlong.o: /usr/include/bits/long-double.h /usr/include/gnu/stubs.h
putlong.o: /usr/include/bits/types.h /usr/include/bits/timesize.h
putlong.o: /usr/include/bits/typesizes.h /usr/include/bits/time64.h
putlong.o: /usr/include/bits/types/__fpos_t.h
putlong.o: /usr/include/bits/types/__mbstate_t.h
putlong.o: /usr/include/bits/types/__fpos64_t.h
putlong.o: /usr/include/bits/types/__FILE.h /usr/include/bits/types/FILE.h
putlong.o: /usr/include/bits/types/struct_FILE.h
putlong.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
