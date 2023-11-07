#include <main_header.h>

// cpu info goes in that order user, nice, system, idle, iowait, irq, softirq, steal;
int linux_cpu_perf()
{
    int size = my_strlen(rl_buff);
    char buff[size];
    my_strcpy(buff, rl_buff);
    my_readline(-1);
    init_my_readline();
    int index = 1;
    long long total = 0;
    long long value = 0;
    long long idle = 0;
    double cpu_usage = 0;
    int len = 0;
    int fd = open("/proc/stat", O_RDONLY);
    char* str = my_readline(fd);
    close(fd);
    char** tokens = dirty_split(str, 0, __SPACE_CHAR__);
    while (index < CPU_SIZE_ARR)
    {
        len = my_strlen(tokens[index]);
        value = my_ctoi(tokens[index],len);
        total += value; 
        if (index == 5)
        {
            idle = value; 
        }
        index += 1;
    }
    cpu_usage = (double)(total - idle) / total * 100.0;
    my_readline(-1);
    init_my_readline();
    my_strcpy(rl_buff, buff);
    return cpu_usage; 
}

int linux_mem_perf()
{
    int size = my_strlen(rl_buff);
    char buff[size];
    my_strcpy(buff, rl_buff);
    my_readline(-1);
    init_my_readline();
    int fd = open("/proc/meminfo", O_RDONLY);
    char* str = NULL ;
    int index = 0;
    char** tokens = NULL;
    int count = 0;
    long arr[3] = {0};
    int len = 0;
    double mem_usage = 0;
    while ((str = my_readline(fd)))
    {
        count = count_cmd(str) - 1;
        tokens = dirty_split(str, 0, __SPACE_CHAR__);
        len = my_strlen(tokens[count]);
        arr[index] = my_ctoi(tokens[count], len);
        index += 1;
        free(str);
        free(tokens);
        if (index == 3)
        {
            tmp_buff_reset();
            break;
        }
    }
    mem_usage = (double)(arr[0] - arr[2]) / arr[0] * 100.0;
    close(fd);
    my_readline(-1);
    init_my_readline();
    my_strcpy(rl_buff, buff);
    return mem_usage;
}

int operating_sys()
{
#ifdef _WIN32
    write(STDERR_FILENO,ERR_MESSAGE_WIN, ERR_MESSAGE_WIN_SIZE)
    return EXIT_SUCCESS
#elif _WIN64
    write(STDERR_FILENO,ERR_MESSAGE_WIN, ERR_MESSAGE_WIN_SIZE)
    return EXIT_SUCCESS
#elif __linux__
    if (linux_cpu_perf() > PERF_LIMIT || linux_mem_perf() > PERF_LIMIT )
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
#elif __APPLE__
    write(STDERR_FILENO, ERR_MESSAGE_MACOS, ERR_MESSAGE_MACOS_SIZE)
    return EXIT_SUCCESS
#endif
}

    // printf("CPU usage: %.2f%%\n", cpu_usage);
    // printf("the total is : %lli\n", total);
    // printf("idle value is : %lli\n", idle);
    // printf("mem usage is: %.2f%%\n",mem_usage);