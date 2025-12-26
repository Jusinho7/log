#include <iostream>
#include <unistd.h>
using namespace std;

void putcat(char c)
{
    write(1, &c, 1);
}

void puttext(const char *str)
{
    while (*str)
        putcat(*str++);
    putcat('\n');
}   

int length(char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

void toLowercase(char *str)
{
    int i;
    int n;

    n = length(str);
    i = 0; 
    while (i < n)
    {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        i++;
    }

}

bool estPalindrome(char *str)
{
    int n = length(str);
    if (n <= 2)
        return false;

    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - 1 - i])
            return false;
    }
    return true;
}

int main(void)
{
    char name[100];

    cout << "Entrez un mot : ";
    cin >> name;

    toLowercase(name);

    if (estPalindrome(name))
        puttext("C'est un palindrome !");
    else
        puttext("Ce n'est pas un palindrome !");
}