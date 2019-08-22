#include "head.h"

int count_args(char **args)
{
        int j = 0;
        while(args[j])
                j++;
        return(j);
}
char *_strcpy(char *dest, const char *src)
{
        int i, n = _strlen(src);
        for(i = 0; i < n && src[i] != '\0'; i++)
                if (src[i] != '\n')
                        dest[i] = src[i];
                else
                        dest[i] = '\0';
        return(dest);
}
size_t _strlen(const char *s)
{
        size_t i = 0;
        while(s[i])
                i++;
        return(i);
}

