#include "../../include/main_header.h"

int header_size (ph_t * header)
{
    long unsigned int index = 0;
    int size = 0;

    size += inter_size(header->name, sizeof(header->name));
    size += inter_size(header->mode, sizeof(header->mode));
    size += inter_size(header->uid, sizeof(header->uid));
    size += inter_size(header->gid, sizeof(header->gid));
    size += inter_size(header->size, sizeof(header->size));
    size += inter_size(header->mtime, sizeof(header->mtime));

    while (index < sizeof(header->chksum))
    {
        size += ' ';
        index += 1;
    }

    size += header->typeflag;
    size += inter_size(header->linkname, sizeof(header->linkname));
    size += inter_size(header->magic, sizeof(header->magic));
    size += inter_size(header->version, sizeof(header->version));
    size += inter_size(header->uname, sizeof(header->uname));
    size += inter_size(header->gname, sizeof(header->gname));
    size += inter_size(header->devmajor, sizeof(header->devmajor));
    size += inter_size(header->devminor, sizeof(header->devminor));
    size += inter_size(header->prefix, sizeof(header->prefix));
    return size;
}