/***********************************************************************\
*       C Standard defines                                              *
*       This file containes machine- and compiler-specific #defines     *
\***********************************************************************/

/***********************************************************************\
*       SUN Workststations                                              *
\***********************************************************************/

#ifdef linux

#define Reg1
#define Reg2
#define Reg3
#define Reg4
#define Reg5
#define Reg6
#define Reg7
#define Reg8
#define Reg9
#define Reg10
#define Reg11
#define Reg12

#define CHARMASK   0xFF
#define CHARNBITS  8
#define MAXCHAR    0xFF

#define SHORTMASK  0xFFFF
#define SHORTNBITS 16
#define MAXSHORT   0x7FFF

#define LONGMASK  0xFFFFFFFF
#define LONGNBITS 32
#define MAXLONG   0x7FFFFFFF

#define INTMASK  0xFFFFFFFF
#define INTNBITS 32
#define MAXINT   0x7FFFFFFF

#define BIGADDR         /* text address space > 64K */

#define INT4            /* sizeof (int) == 4 */

#define PTR4            /* sizeof (char *) == 4 */

/* unsigned types supported by the compiler: */
#define UNSCHAR         /* unsigned char  */
#define UNSSHORT        /* unsigned short */
#define UNSLONG         /* unsigned long  */

#define STRUCTASSIGN    /* Compiler does struct assignments */

#define UNIONS_IN_REGISTERS     /* compiler allows unions in registers */

#endif /* sun */


/***********************************************************************\
*       HP  Workststations                                              *
\***********************************************************************/

#ifdef hpux

#define Reg1
#define Reg2
#define Reg3
#define Reg4
#define Reg5
#define Reg6
#define Reg7
#define Reg8
#define Reg9
#define Reg10
#define Reg11
#define Reg12

#define CHARMASK   0xFF
#define CHARNBITS  8
#define MAXCHAR    0x7F

#define SHORTMASK  0xFFFF
#define SHORTNBITS 16
#define MAXSHORT   0x7FFF

#define LONGMASK  0xFFFFFFFF
#define LONGNBITS 32
#define MAXLONG   0x7FFFFFFF

#define INTMASK  0xFFFFFFFF
#define INTNBITS 32
#define MAXINT   0x7FFFFFFF

#define BIGADDR         /* text address space > 64K */

#define INT4            /* sizeof (int) == 4 */

#define PTR4            /* sizeof (char *) == 4 */

/* unsigned types supported by the compiler: */
#define UNSCHAR         /* unsigned char  */
#define UNSSHORT        /* unsigned short */
#define UNSLONG         /* unsigned long  */

#define STRUCTASSIGN    /* Compiler does struct assignments */

#define UNIONS_IN_REGISTERS     /* compiler allows unions in registers */

#endif /* hpux */

/***********************************************************************\
*       Atari ST MINIX                                                  *
\***********************************************************************/

#ifdef MINIX

#define Reg1	register
#define Reg2	register
#define Reg3	
#define Reg4
#define Reg5
#define Reg6
#define Reg7
#define Reg8
#define Reg9
#define Reg10
#define Reg11
#define Reg12

#define CHARMASK   0xFF
#define CHARNBITS  8
#define MAXCHAR    0x7F

#define SHORTMASK  0xFFFF
#define SHORTNBITS 16
#define MAXSHORT   0x7FFF

#define LONGMASK  0xFFFFFFFFL
#define LONGNBITS 32
#define MAXLONG   0x7FFFFFFFL

#define INTMASK  0xFFFF
#define INTNBITS 16
#define MAXINT   0x7FFF

#define BIGADDR         /* text address space > 64K */

#define INT2            /* sizeof (int) == 2 */

#define PTR4            /* sizeof (char *) == 4 */

/* unsigned types supported by the compiler: */
/* fine UNSCHAR         /* unsigned char  */
/* fine UNSSHORT        /* unsigned short */
/* fine UNSLONG         /* unsigned long  */

/* fine STRUCTASSIGN	/* Compiler does struct assignments */

/* fine UNIONS_IN_REGISTERS     /* compiler allows unions in registers */

#endif /* MINIX */
