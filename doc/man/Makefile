#
# The e.man file has two ".so" - make sure the filenames
# point at where you install the "e.*.out" files.
#

e.man:  e.stdkey.out  e.term.out

e.stdkey.out: e.stdkey.tbl
	tbl e.stdkey.tbl > e.stdkey.out

e.term.out: e.term.tbl
	tbl e.term.tbl > e.term.out

e.1:    e.man
	soelim e.man > e.1

hardcopy:  e.1
	t2ps -man  e.1 > e.ps
