/*	@(#)varargs.h 1.7 88/02/07 SMI; from UCB 4.1 83/05/03	*/

typedef char *va_list;
#if defined(sparc)
# define va_alist __builtin_va_alist
#endif
# define va_dcl int va_alist;
# define va_start(list) list = (char *) &va_alist
# define va_end(list)
# define va_arg(list,mode) ((mode *)(list += sizeof(mode)))[-1]
