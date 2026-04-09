#include<stdio.h>
void reverseString(char* s, int sSize)

{
    int first =0;
    int last = sSize-1;

    while(first<last)
    {
        int temp = s[first];
        s[first]=s[last];
        s[last]=temp;

    first++;
    last--;
    }

}



int main()
{
    char s[] = {'h','e','l','l','o'};
    
    reverseString(s, 5);

    for(int i = 0; i < 5; i++)
    {
        printf("%c ", s[i]);
    }

    return 0;
}

