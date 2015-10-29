/* FIXME: Implement! */

#include<stdio.h>

int strlenth(char str[])
{
    int count = 0;
    while(str[count]!='\0') {
        count++;
    }
    return(count);
}

char smallest_character_iterative(char str[], char c)
{
    int i=0;
    if(c >= str[strlenth(str)-1]) {
        return(str[0]);
    } else {
        while(c >=str[i]) {
            i++;
        }
        return(str[i]);
    }
}

