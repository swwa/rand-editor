#
#       Top level installation makefile for the Rand Editor (e).
#
#       The settings for various of the definitions below depend on the
#       environment:
#
CC      = gcc
DFS     = -DUNIXV7 -DTERMCAP -DSYSIII -DNOSOBUF
#CCF     = -g -O -traditional-cpp
CCF     = -g -O2
LDF     = -g
LIBC    = -lc -lbsd
RANLIB  = ranlib
OWNER   = bin
GROUP   = bin

LOCALINCL = ../include/
BIN = /usr/local/bin
LIB = /usr/local/etc
TMP = /tmp
MAN = /usr/local/man/man1
DOC = $(MAN)/le.1
NAME = le
LALIB = la1/libla.a
FFLIB = ff3/libff.a

all:
	cd ff3; make "LOCALINCL=$(LOCALINCL)" \
		"CC=$(CC)" \
		"DFS=$(DFS)" \
		"CCF=$(CCF)" \
		"LDF=$(LDF)" \
		"RANLIB=$(RANLIB)"
	cd la1; make "LOCALINCL=$(LOCALINCL)" \
		"CC=$(CC)" \
		"DFS=$(DFS)" \
		"CCF=$(CCF)" \
		"LDF=$(LDF)" \
		"RANLIB=$(RANLIB)" \
		"FFL=ff3"
	cd fill; make "LOCALINCL=$(LOCALINCL)" \
		"CC=$(CC)" \
		"DFS=$(DFS)" \
		"CCF=$(CCF)" \
		"LDF=$(LDF)" \
		"RANLIB=$(RANLIB)"
	cd src; make "LOCALINCL=$(LOCALINCL)" \
		"CC=$(CC)" \
		"DFS=$(DFS)" \
		"CCF=$(CCF)" \
		"LDF=$(LDF)" \
		"RANLIB=$(RANLIB)" \
		nle

install: help $(DOC)
	cd fill; make "OWNER=$(OWNER)" "GROUP=$(GROUP)" \
		"LIB=$(LIB)" install
	cp src/nle $(BIN)/$(NAME)
	strip $(BIN)/$(NAME)
	chmod 755 $(BIN)/$(NAME)
	chown $(OWNER) $(BIN)/$(NAME)
	chgrp $(GROUP) $(BIN)/$(NAME)

etc:
	-mkdir $(LIB)
	chown $(OWNER) $(LIB)
	chmod 755 $(LIB)
	cp help/Crashdoc help/errmsg help/recovermsg $(LIB)
	chmod 444 $(LIB)/*
	chown $(OWNER) $(LIB)/*

help:   etc
	cp help/helpkey $(LIB)
	chown $(OWNER) $(LIB)/*

$(DOC):
	cp doc/man/e.1 $(DOC)

clean:
	cd src; make clean
	cd fill; make clean
	cd la1; make clean
	cd ff3; make clean
	rm -f ,* #* a.out core .e?1

clobber:
	cd src; make clobber
	cd fill; make clobber
	cd la1; make clobber
	cd ff3; make clobber
	rm -f ,* #* a.out core .e?1

depend:
	cd src; make depend
	cd fill; make depend
	cd la1; make depend
	cd ff3; make depend
