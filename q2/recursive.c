#include<stdio.h>

int strlenth(char str[])
{
    int count = 0;
    while(str[count]!='\0') {
        count++;
    }
    return(count);
}
char result(char str[], char c,int low,int high)
{
    int mid = (low+high)/2;
    if(c < str[low]) {
        return(str[low]);
    } else if(c == str[mid]) {
        return(str[mid+1]);
    } else if(c > str[mid]) {
        if(c < str[mid+1]) {
            return(str[mid+1]);
        }
        result(str,c,mid+1,high);
    } else if(c < str[mid]) {
        result(str,c,low,mid);
    }
}
char smallest_character_recursive(char str[], char c)
{
    int low = 0;
    int high = strlenth(str);
    if(c >= str[high-1]) {
        return(str[0]);
    } else {
        return(result(str,c,low,high));
    }
}