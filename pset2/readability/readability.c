#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int countLetters(string s);
int countWords(string s);
int countSentences(string s);
int getColemanLiauIdx(int letterCount, int wordCount, int sentenceCount);

int main(void)
{
    int letterCount = 0, wordCount = 0, sentenceCount = 0;
    int index = 0;

    string input = get_string("Text: ");

    letterCount = countLetters(input);

    wordCount = countWords(input);

    sentenceCount = countSentences(input);

    index = getColemanLiauIdx(letterCount, wordCount, sentenceCount);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int countLetters(string s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            count++;
        }
    }
    return count;
}

int countWords(string s)
{
    int count = 0;

    if (0 < strlen(s))
    {
        count++;
    }

    for (int i = 0; i < strlen(s); i++)
    {
        if (isspace(s[i]))
        {
            count++;
        }
    }
    return count;
}

int countSentences(string s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if ('?' == s[i] || '!' == s[i] || '.' == s[i])
        {
            count++;
        }
    }
    return count;
}

int getColemanLiauIdx(int letterCount, int wordCount, int sentenceCount)
{
    float index = 0, L = 0, S = 0;

    L = (float)letterCount / (float)wordCount * 100;
    S = (float)sentenceCount / (float)wordCount * 100;
    index = 0.0588 * L - 0.296 * S - 15.8;

    return round(index);
}