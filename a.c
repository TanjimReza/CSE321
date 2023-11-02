#include <stdio.h>
#include <string.h>

int old_or_new(char *old)
{
    char *domain = "sheba.xyz";
    char *old_domain = old + strlen(old) - strlen(domain);

    if (strcmp(old_domain, domain) == 0)
    {
        printf("Email address is okay");
    }
    else
    {
        printf("Email address is outdated");
    }
}

int main()
{
    char old[25];
    printf("Enter email address: ");
    scanf("%s", old);

    old_or_new(old);

    return 0;
}