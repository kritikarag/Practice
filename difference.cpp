#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(char a[])
{
    bool flag = true; 
    for (int i = 0; i < strlen(a) / 2; i++)
    {
        if (a[i] != a[strlen(a) - i - 1])
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    char string[] = "Wow you own kayak";
    char words[100][100], smallPalin[100], bigPalin[100];
    int i = 0, j = 0, k, length, count = 0;

    // Split the string into words such that each row of array words represents a word
    for (k = 0; string[k] != '\0'; k++)
    {
        // Here, i represents row and j represents column of two-dimensional array words
        if (string[k] != ' ' && string[k] != '\0')
        {
            words[i][j++] = tolower(string[k]);
        }
        else
        {
            words[i][j] = '\0';
            // Increment row count to store new word
            i++;
            // Set column count to 0
            j = 0;
        }
    }
    // Store row count in variable length
    length = i + 1;

    // Determine the smallest and biggest palindromes in a given string
    for (int i = 0; i < length; i++)
    {
        if (isPalindrome(words[i]))
        {

            count++;
            // When first palindromic word is found
            if (count == 1)
            { 
                strcpy(smallPalin, words[i]);
                strcpy(bigPalin, words[i]);
            }
 
            else
            { 
                if (strlen(smallPalin) > strlen(words[i]))
                    strcpy(smallPalin, words[i]);

                if (strlen(bigPalin) < strlen(words[i]))
                    strcpy(bigPalin, words[i]);
            }
        }
    }

    if (count == 0)
        printf("No palindrome is present in the given string");
    else
    {
        printf("Smallest palindromic word: %s\n", smallPalin);
        printf("Biggest palindromic word: %s", bigPalin);
    }

    return 0;
}