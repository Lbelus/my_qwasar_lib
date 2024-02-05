# Welcome to My Ls
***

## Task

Realise my own version of ls following the man page specification

to complete qwasar_my_ls we need to gather the following information : 
- Name of directories and files. 
- Date of creation.
- Type of files.
- A node management system. 
- A lexicographical sort.

## Description

- Display each operand that names a file of a type different than directory.
Must display names any requested or/and associated information.
- Display each operand that names a file of a type directory.
Must display names of files within directory any requested or/and associated  information.

- if no operand : content of current directory's content is displayed
- if more than one operand :  non directory operand are displayed first  
                              directory and non directory are sorted separately and in lexicographical order. 

Flags :
- -a include directory entries beginning with a dot (.).
- -t sort by time modified (most recently modified first) before sorting by lexicographical order.
    ==>Recommendation : make use of ``tv_sec`` and ``tv_nsec``.


Observations :

st_mtim ? 

/dev ? is the location of special or device files. it represents vairous partition of the first master drive of the system 

stat ?  Display a file or file status in terminal

lstat ? "library" that display a file status
 man pages  suggest following headersfiles: 

```c

#include <sys/types.h>
#include <sys/stats.h>
#include <unistd.h>

int stat(const char *pathname, struct stat *statbuf);
int fstat(int fd, struct stat *statbuf);
int lstat(const char *pathname, struct stat *statbuf);
```
Return information about a file, in the buffer pointer to by statbuf. 
No permissions are required on the file itself exception made for stats(), fstatat(), and lstat() that requires permission on all directories in pathname leading to the file.

stats() retrieve information about the file pointed to by pathname
same for lstat() but returns information on link if pathname is a symbolic link and not thefile
same for lstat() but the file is to be specified via File Descriptor. 

These system calls rely on a stat structure containing following field:

```c           
    //the orders of fields varies accross architectures.
    //padding bytes may be present between fields on some architectures. 

            struct stat {
               dev_t     st_dev;         /* ID of device containing file */ // major(3) or minor(3) macros could help decompose device ID 
               ino_t     st_ino;         /* Inode number */ 
               mode_t    st_mode;        /* File type and mode */ // see inode(7)
               nlink_t   st_nlink;       /* Number of hard links */
               uid_t     st_uid;         /* User ID of owner */
               gid_t     st_gid;         /* Group ID of owner */
               dev_t     st_rdev;        /* Device ID (if special file) */
               off_t     st_size;        /* Total size, in bytes */
               blksize_t st_blksize;     /* Block size for filesystem I/O */ //prefered block size for efficient filesystem I/O
               blkcnt_t  st_blocks;      /* Number of 512B blocks allocated */

               /* Since Linux 2.6, the kernel supports nanosecond
                  precision for the following timestamp fields.
                  For the details before Linux 2.6, see NOTES. */

               struct timespec st_atim;  /* Time of last access */
               struct timespec st_mtim;  /* Time of last modification */
               struct timespec st_ctim;  /* Time of last status change */

           #define st_atime st_atim.tv_sec      /* Backward compatibility */
           #define st_mtime st_mtim.tv_sec
           #define st_ctime st_ctim.tv_sec
           };
            
            Include: <time.h>.  Alternatively, <aio.h>, <mqueue.h>, <sched.h>, <signal.h>, <sys/select.h>, or <sys/stat.h>.

            struct timespec {
                  time_t  tv_sec;  /* Seconds */
                  long    tv_nsec; /* Nanoseconds */
            };

          /*
              Last modification timestamp (mtime)
              stat.st_mtime; statx.stx_mtime

              This is the file's last modification timestamp.  It is changed by file modifications, for example, by mknod(2), truncate(2), utime(2), and write(2) (of more  than  zero
              bytes).  Moreover, the mtime timestamp of a directory is changed by the creation or deletion of files in that directory.  The mtime timestamp is not changed for changes
              in owner, group, hard link count, or mode.
          */

          /*
           S_IFMT     0170000   bit mask for the file type bit field

           S_IFSOCK   0140000   socket
           S_IFLNK    0120000   symbolic link
           S_IFREG    0100000   regular file
           S_IFBLK    0060000   block device
           S_IFDIR    0040000   directory
           S_IFCHR    0020000   character device
           S_IFIFO    0010000   FIFO
          */

          //CHECK FILE TYPE;
           stat(pathname, &sb);
           if ((sb.st_mode & S_IFMT) == S_IFREG) {
               /* Handle regular file */
           }

  //        man dircolor
//check The LS_COLORS environment variable 

```
regarding your environment, you may have to specify <sys/stats.h> path to include it.

other required header to complete function :

```c
#include <sys/stat.h> // struct stat ; lstat(); 
#include <sys/types.h>  //...
#include <pwd.h>  //? why ? does it redefine git_t uid_t size_t from sys/types ?  
#include <dirent.h> //struct dirent ; dirent opendir(".") ; chdir() 
#include <time.h>

```

lstat() call upon : 
```c

// AT_FDCWD : pathname is interpertred from current directory

#include <sys/stat.h>
int
__lstat (const char *file, struct stat *buf)
{
  return __fstatat (AT_FDCWD, file, buf, AT_SYMLINK_NOFOLLOW);
}
weak_alias (__lstat, lstat)

```

lstat() return 0 on success else return -1 and set errno

cmd to get curent working directory :

```c
#include <unistd.h>

       char *getcwd(char *buf, size_t size);

       char *getwd(char *buf); //deprecated DO NOT USE

       char *get_current_dir_name(void);
```

## Installation

In order to use my_ls you must first compile the program :

> Insert ``make my_ls`` into terminal

If you want to clean compile file :

> Insert ``make fclean`` into terminal

## Usage


 insert ``my_ls [OPTION]... [file]...`` into terminal

 - ``-t`` provide a file list sorted by time
 - ``-a`` provide a list with hidden files

 exemple : 

 ```
    my_ls
    my_ls -t dir1
    my_ls -a dir1 
    my_ls -at dir1 dir2 dir3
 ```

### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt="Qwasar SV -- Software Engineering School's Logo" src="https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png" width="20px" /></span>
