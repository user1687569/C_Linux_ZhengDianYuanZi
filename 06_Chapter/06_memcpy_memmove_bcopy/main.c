#include <stdio.h>
#include <string.h>

struct {
    char name[40];
    int age;
}person_t, person_copy_t;

int main()
{
    /*
     * 函数的功能是从源内存地址的起始位置开始拷贝若干个字节到目标内存地址中
     */
    fprintf(stdout, "Using memcpy()...\n");
    char myName[] = "Piece de Fermat";
    memcpy(person_t.name, myName, strlen(myName) + 1);
    person_t.age = 27;

    memcpy(&person_copy_t, &person_t, sizeof(person_t));
    printf("person_copy: %s, %d\n", person_copy_t.name, person_copy_t.age);

    /*
     * memmove用于拷贝字节，如果目标区域和源区域有重叠的话，
     * memmove能够保证源串在被覆盖之前将重叠区域的字节拷贝至目标区域中，
     * 但复制后源内容会被更改
     * 但是当目标区域与源区域没有重叠则和memcpy函数功能相同
     */
    fprintf(stdout, "Using memmove()...\n");
    char s[] = "Golden Global View";
    memmove(s, s+7, strlen(s)+1-7);
    printf("%s", s);
    getchar();

    return 0;
}




















































