#include "../../include/main_header.h"

//head->st.st_mode & S_IFMT) == S_IFDIR)
/*
    S_IFMT     0170000   bit mask for the file type bit field
    '0'    S_IFREG    0100000   regular file
    '1'    HARD_LINK ?
    '2'    S_IFLNK    0120000   symbolic link
    '3'    S_IFCHR    0020000   character device
    '4'    S_IFBLK    0060000   block device
    '5'    S_IFDIR    0040000   directory
    '6'    S_IFIFO    0010000   FIFO
    '?'    S_IFSOCK   0140000   socket
*/


char my_is_type(struct stat st)
{
    switch (st.st_mode & S_IFMT)
    {
    case (S_IFREG):
        return REG_T;
        //break;
    case (S_IFLNK):
        return SYM_T;
        //break;
    case (S_IFCHR):
        return CHR_T;
       //break;
    case (S_IFBLK):
        return BLK_T;
        //break;
    case (S_IFDIR):
        return DIR_T;
        //break;
    case (S_IFIFO):
        return FIFO_T;
    }
    return '?';
}