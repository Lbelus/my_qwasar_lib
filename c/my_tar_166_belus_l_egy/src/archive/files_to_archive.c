#include "../../include/main_header.h"
#include <stdio.h>

// set fd position for -rf and then write to archive 

void files_to_archive(my_getopt_t *getopt_ptr, node_t* m_head) 
{
    int fd = 0, archive_fd = 0, index = 0, byte_count = 0, block_count = 0, pos = 0;
    ph_t* ph;

    archive_fd = open(getopt_ptr->path_arr[index], getopt_ptr->oflag , 0644);

    if (getopt_ptr->bool_arr[2] == true || getopt_ptr->bool_arr[4] == true)
    {
        block_count += set_fd_pos(archive_fd , getopt_ptr);
    }

    while (index < getopt_ptr->nbr_str -1)
    {
        index++;
        if (getopt_ptr->bool_arr[1] == true || getopt_ptr->bool_arr[2] == true)
        {
            ph = malloc(sizeof(ph_t));
            pos = path_to_name(getopt_ptr->path_arr[index]);

            if(pos > 1)
            {
                swd(getopt_ptr->path_arr[index], pos);
                ph = fill_ph(m_head, ph, &getopt_ptr->path_arr[index][pos + 1]);
                my_strcpy(ph->name, &getopt_ptr->path_arr[index][0]);
                int sum = header_size(ph);
                field_update(ph->chksum, sum, sizeof(ph->chksum) -1);
                ph->chksum[sizeof(ph->chksum) -1] = ' ';
                fd = open(&getopt_ptr->path_arr[index][pos + 1], O_RDONLY);  
            }
            else
            {
                ph = fill_ph(m_head, ph, getopt_ptr->path_arr[index]);
                fd = open(getopt_ptr->path_arr[index], O_RDONLY);
                if (fd == -1)
                {
                    fprintf(stderr, "my_tar: i_don_t_exist: Cannot stat: No such file or directory\n");
                    continue;
                }
            }
            byte_count += write_to_archive(fd, archive_fd, ph);
            free(ph);
            chdir(getopt_ptr->home);
        }
    }
    block_count += byte_count / BLOCKSIZE;
    end_block(archive_fd, block_count);
    close(archive_fd);
}