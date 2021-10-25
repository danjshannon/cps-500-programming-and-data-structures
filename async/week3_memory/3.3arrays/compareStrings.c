#include <stdio.h>

int compareStrings(char *string1, char *string2, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (string1[i] != string2[i])
        {
            return 0; //false
        }
    }
    return 1; //true
}
int main()
{
    char string1[0] = "hello\0";
    char string2[0] = "hello\0";
    compareStrings(string1, string2, N);
    return 0;
}