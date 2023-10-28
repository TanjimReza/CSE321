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