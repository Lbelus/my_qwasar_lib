#include "../../include/main_header.h"

void set_header(ph_t* ph)
{
    my_bzero(ph->name, sizeof(ph->name));
    my_bzero(ph->linkname, sizeof(ph->linkname));
    my_bzero(ph->version, sizeof(ph->version));
    my_bzero(ph->uname, sizeof(ph->uname));
    my_bzero(ph->gname, sizeof(ph->gname));
    my_bzero(ph->devmajor, sizeof(ph->devmajor));
    my_bzero(ph->devminor, sizeof(ph->devminor));
    my_bzero(ph->prefix, sizeof(ph->prefix));

    set_header_field(ph->mode, '0', sizeof(ph->mode));
    set_header_field(ph->uid, '0', sizeof(ph->uid));
    set_header_field(ph->gid, '0', sizeof(ph->gid));
    set_header_field(ph->size, '0', sizeof(ph->size));
    set_header_field(ph->mtime, '0', sizeof(ph->mtime));
    set_header_field(ph->chksum, '0', sizeof(ph->chksum) - 1);
}
