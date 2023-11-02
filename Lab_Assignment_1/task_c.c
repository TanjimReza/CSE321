#include <stdio.h>

<<<<<<< HEAD
=======
int main()
{
    char password[50];
    int len;
    int lowercase;
    int uppercase;
    int digit;
    int special;

    lowercase = 0;
    uppercase = 0;
    digit = 0;
    special = 0;

    printf("Enter password: ");
    scanf("%s", password);

    len = strlen(password);

    for (int i = 0; i < len; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            lowercase = 1;
        }
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            uppercase = 1;
        }
        if (password[i] >= '0' && password[i] <= '9')
        {
            digit = 1;
        }
        else if (password[i] == '_' || password[i] == '$' || password[i] == '#' || password[i] == '@')
        {
            special = 1;
        }
    }

    if (lowercase == 0)
    {
        printf("Lowercase character missing, ");
    }

    if (uppercase == 0)
    {
        printf("Uppercase character missing, ");
    }

    if (digit == 0)
    {
        printf("Digit missing, ");
    }

    if (special == 0)
    {
        printf("Special character missing");
    }

    if (lowercase && uppercase && digit && special)
    {
        printf("OK\n");
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

int is_valid_email(char *email)
{
    char *domain = strstr(email, "sheba.xyz");
    if (domain)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
>>>>>>> 91fac4fa361f1ec8fa82f4237a26eea17b9612f9

int main()
{
    char email[100];
    printf("Enter email ID: ");
    scanf("%s", email);

    if (is_valid_email(email))
    {
        printf("Email address is okay");
    }
    else
    {
        printf("Email address is outdated");
    }

    return 0;
}