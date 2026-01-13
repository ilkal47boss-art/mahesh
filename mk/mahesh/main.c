#include <stdio.h>
#include <ctype.h>

char s[50];
int top = -1;

int pr(char c)
{
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main()
{
    char infix[50], postfix[50];
    int i = 0, j = 0;
    char ch;

    printf("Enter the infix expression:\n");
    gets(infix);

    while (infix[i] != '\0')
    {
        ch = infix[i];

        if (isalnum(ch))
            postfix[j++] = ch;

        else if (ch == '(')
            s[++top] = ch;

        else if (ch == ')')
        {
            while (s[top] != '(')
                postfix[j++] = s[top--];
            top--;
        }
        else
        {
            while (top != -1 && pr(s[top]) >= pr(ch))
                postfix[j++] = s[top--];
            s[++top] = ch;
        }
        i++;
    }

    while (top != -1)
        postfix[j++] = s[top--];

    postfix[j] = '\0';

    printf("\nInfix Expression  : %s", infix);
    printf("\nPostfix Expression: %s", postfix);

    return 0;
}
