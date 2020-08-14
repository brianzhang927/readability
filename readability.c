#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>


float grade(int letters, int words, int sentences);     //function prototype

int main(void)
{

    string text = get_string("Text: ");     //get text
    int n = strlen(text);
    int letters = 0;
    int words = 1;
    int sentences = 0;


    for (int i = 0; i < n; i++)      //count letters, words, sentences
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }

        else if (text[i] == ' ')
        {
            words++;
        }

        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }


    if (grade(letters, words, sentences) < 1)       //print grade level
    {
        printf("Before Grade 1\n");
    }

    else if (grade(letters, words, sentences) > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", (int) grade(letters, words, sentences));
    }
}


float grade(int letters, int words, int sentences)      //get grade level
{

    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    return round(0.0588 * L - 0.296 * S - 15.8);

}

