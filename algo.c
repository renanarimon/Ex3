#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TXT 256
#define WORD 30
#define SIZE 51

static char word[WORD];
static char txt[TXT];
static char Watbash[WORD];

void init(char *w, char *t)
{
    strcpy(word, w);
    strcpy(txt, t);
}

int gimatryNum(char x)
{
    int ans = 0;
    if (isupper(x))
    {
        ans = x - 'A' + 1;
    }
    else if (islower(x))
    {
        ans = x - 'a' + 1;
    }
    return ans;
}

char *strrev(char *str)
{
    char *p1, *p2;

    if (!str || !*str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

char *AZBY_algo()
{
    char ch;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            ch = 'Z' - word[i] + 'A';
        }
        else if (islower(word[i]))
        {
            ch = 'z' - word[i] + 'a';
        }
        Watbash[i] = ch;
    }
    return Watbash;
}

void atbash()
{
    char str[2 * strlen(txt)];
    char ans[2 * strlen(txt)];
    char *search = AZBY_algo(); //atbash word
    char rev[strlen(search)];   // reverse of atbash word
    char tmp[2 * strlen(txt)];
    strcpy(rev, search);
    strrev(rev);

    str[0] = '\0';
    tmp[0] = '\0';

    int k = 0;
    int i = 0;
    while (i < strlen(txt))
    {
        if (txt[i + k] == ' ' && strlen(str) > 0)
        {

            strncat(tmp, &txt[i + k], 1);
            k++;
        }
        else
        {
            char *sub;
            char *subrev;
            strncat(str, &txt[i + k], 1);
            strncat(tmp, &txt[i + k], 1);
            k++;
            sub = strstr(search, str);
            subrev = strstr(rev, str);

            if (sub == NULL && subrev == NULL)
            {

                k = 0;
                str[0] = '\0';
                tmp[0] = '\0';
                i++;
            }
            if (strcmp(str, search) == 0 || strcmp(str, rev) == 0)
            {
                strcat(ans, tmp);
                strcat(ans, "~");
                str[0] = '\0';
                tmp[0] = '\0';
                k = 0;
                i++;
            }
        }
    }
    ans[strlen(ans) - 1] = '\0';
    printf("%s", ans);
}

int sumWord()
{
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += gimatryNum(word[i]);
    }
    return sum;
}

void GimatryProg()
{
    char str[2 * strlen(txt)];
    str[0]='\0';
    char ans[2 * strlen(txt)];
    ans[0]='\0';
    int search = sumWord();
    int sum = 0;
    int k = 0;
    int i = 0;
    while (i < strlen(txt))
    {
        int GimatriI = gimatryNum(txt[i + k]);
        sum += GimatriI;
        strncat(str, &txt[i + k], 1);
        k++;
        if (sum > search)
        
        {
            k = 0;
            sum = 0;
            str[0] = '\0';
            i++;
        }
        if (sum == search)
        { 
            if (gimatryNum(str[0]) != 0)
            {
                
                strcat(ans, str);
                strcat(ans, "~");
            }
            k = 0;
            sum = 0;
            str[0] = '\0';
            i++;
        }
    }
    ans[strlen(ans) - 1] = '\0';
    printf("%s", ans);
}

void removeChar(char *str, char ch)
{
    int i, j, len;

    len = strlen(str);
    int flag = 0;
    for (i = 0, j = 0; i < len; i++, j++)
    {
        if (str[j] != ch || flag==1)
        {
            str[i] = str[j];
        }
        else if(flag==0){
            i--;
            flag =1;
        }
    }
}

void AnagramProg()
{
    char str[2 * strlen(txt)];
    str[0] = '\0';
    char ans[2 * strlen(txt)];
    ans[0] = '\0';
    char w[WORD];
    strcpy(w, word);
    int k = 0;
    int i = 0;
    while (i < strlen(txt))
    {
        char *tmp = strchr(word, txt[i + k]); //searches for the first occurrence of the character txt[i + k]

        if (tmp != NULL)
        {
            char t = *tmp;
            removeChar(w, t);
            strncat(str, &txt[i + k], 1);
            k++;
        }
        else if (txt[i + k] == ' ' && strlen(str) > 0)
        {
            strncat(str, &txt[i + k], 1);
            k++;
        }
        else
        {
            strcpy(w, word);
            k = 0;
            str[0] = '\0';
            i++;
        }
        if (strlen(w) == 0)
        {
            strcat(ans, str);
            strcat(ans, "~");
            k = 0;
            strcpy(w, word);
            str[0] = '\0';
            i++;
        }
    }
    ans[strlen(ans) - 1] = '\0';
    printf("%s\n", ans);
}
