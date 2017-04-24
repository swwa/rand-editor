/***********************************************************************\
*       system environment stuff                                        *
\***********************************************************************/

/***********************************************************************\
*       SUN Workststations                                              *
\***********************************************************************/

#ifdef linux

#define LINKS                   /* file system has links */
#define CANFORK                 /* system has fork() */
#define VFORK                   /* system has vfork() */
#define ABORT_SIG SIGABRT       /* which signal does abort() use */
#define SIGARG                  /* signal catch routine has sig num as arg */
#define SIG_INCL <signal.h>
#define SGTT_INCL <sys/ioctl.h>
#define TTYNAME                 /* use ttyname function */
#define SHORTUID                /* uid is a short, not a char (v7+) */
#define ENVIRON                 /* getenv() is implemented */
#define SIGNALS                 /* system has signals */
#define SYMLINKS                /* 4.2 symbolic links */
#define NDIR                    /* 4.2 directory routines */
#define SYSMKDIR                /* use mkdir(name, mode) system call */
#define SYSRMDIR                /* use rmdir(name) system call */
#define SYSFCHOWN               /* use fchown(fd, ...) system call */
#define SYSFCHMOD               /* use fchmod(fd, ...) system call */
#define CLR_SUID_ON_WRITE       /* modifying a file clrs suid and sgid bits */
#define SYSSELECT               /* system has berkeley select system call */
#define RENAME                  /* system has berkeley rename system call */

#endif /* sun */

/***********************************************************************\
*       HP  Workststations                                              *
\***********************************************************************/

#ifdef hpux

#define LINKS                   /* file system has links */
#define CANFORK                 /* system has fork() */
#define VFORK                   /* system has vfork() */
#define ABORT_SIG SIGABRT       /* which signal does abort() use */
#define SIGARG                  /* signal catch routine has sig num as arg */
#define SIG_INCL <signal.h>
#define SGTT_INCL <sgtty.h>
#define TTYNAME                 /* use ttyname function */
#define SHORTUID                /* uid is a short, not a char (v7+) */
#define ENVIRON                 /* getenv() is implemented */
#define SIGNALS                 /* system has signals */
#define SYMLINKS                /* 4.2 symbolic links */
#define NDIR                    /* 4.2 directory routines */
#define SYSMKDIR                /* use mkdir(name, mode) system call */
#define SYSRMDIR                /* use rmdir(name) system call */
#define SYSFCHOWN               /* use fchown(fd, ...) system call */
#define SYSFCHMOD               /* use fchmod(fd, ...) system call */
#define CLR_SUID_ON_WRITE       /* modifying a file clrs suid and sgid bits */
#define SYSSELECT               /* system has berkeley select system call */
#define RENAME                  /* system has berkeley rename system call */

#endif /* hpux */

/***********************************************************************\
*       system environment stuff for ATARI ST MINIX                     *
\***********************************************************************/

#ifdef MINIX

#define LINKS                   /* file system has links */
#define CANFORK                 /* system has fork() */
#define ABORT_SIG SIGABRT       /* which signal does abort() use */
#define SIGARG                  /* signal catch routine has sig num as arg */
#define SIG_INCL <signal.h>
#define SGTT_INCL <sgtty.h>
#define TTYNAME                 /* use ttyname function */
#define SHORTUID                /* uid is a short, not a char (v7+) */
#define ENVIRON                 /* getenv() is implemented */
#define SIGNALS                 /* system has signals */
#define NOIOCTL_H		/* use tty.h instead */
#define _iob *_io_table
#define _flag _flags
#define _cnt _count 
#define _NFILE NFILES
#define _IOREAD READMODE
#define _IOWRT  WRITEMODE
#define _IOEOF  _EOF
#define _IOERR  _ERR
#define NSIG _NSIG
#define NOSOBUF

#endif /* MINIX */
