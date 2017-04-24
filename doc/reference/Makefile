#
# editor.eR is the source to the draft E reference manual.  it
# needs to be compiled with nroff and troff using the eR macro
# package (included here under eR).
#
PRT = pt10

editor.nroff:  e.stdkey.out    editor.eR
	nroff -T$(PRT) eR/tmac.eR editor.eR > editor.nroff
test:
	head -198 editor.nroff | lpr -Plaser
