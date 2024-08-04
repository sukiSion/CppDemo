#include<stdio.h>
#include<string.h>


int main(int argc, char const *argv[])
{
    char text[10];

    strcpy(text , "The text is too long for text."); // 太长
    printf("strlen(text): %u\n" , strlen(text)); // 漏了'\0'
    printf("%s\n" , text);
    text[sizeof(text) - 1] = '\0';
    printf("strlen(text): %u\n" , strlen(text));
    return 0;
}
