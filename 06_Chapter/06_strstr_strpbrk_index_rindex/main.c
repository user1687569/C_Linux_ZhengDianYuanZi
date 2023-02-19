#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *ptr = NULL;
    char str[] = "I love my home";

    ptr = strstr(str, "home");
    if(ptr != NULL)
    {
        printf("String:%s\n", ptr);
        printf("Offset:%ld\n", ptr - str);
    }

    char *s1 = "Welcome To Beijing";
    char *s2 = "lcB";
    char *p;

    /*
     * 在源字符串s1中找出最先含有搜索字符串s2中任一字符的位置并返回,
     * 若找不到则返回空指针
     */
    p = strpbrk(s1, s2);
    if(p)
    {
        printf("%s\n", p);
    }
    else
    {
        printf("Not Found!\n");
    }

    char *string = "Good job!";
    char *ptr1 = NULL;
    ptr1 = index(string, 'j');
    if(ptr1 != NULL)
        printf("First occurence of character j is:%d\n", ptr1 - string);
    else
        printf("Character j not found!\n");

    ptr1 = NULL;
    ptr1 = rindex(string, 'o');
    if(ptr1 != NULL)
        printf("Last occurence of character o is:%d\n", ptr1 - string);
    else
        printf("Character o not found!\n");

    return 0;
}
