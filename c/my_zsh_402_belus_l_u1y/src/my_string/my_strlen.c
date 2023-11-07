int my_strlen(char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {  
        len += 1;
    }
    return len;
}