#include <stdio.h>
#include <string.h>

char replaceEmail(char email[]) {
    char username[100];
    char domain[100];

    char previous_domain[] = "kaaj.com";
    char previous_domain_caps[] = "KAAJ.COM";
    char new_domain[] = "sheba.xyz";

    int i = 0; 
    while (email[i] != '@') {
        username[i] = email[i];
        i++;
    }
    username[i] = '\0';
    i++;

    int j = 0; 
    while (email[i] != '\0') {
        domain[j] = email[i];
        i++;
        j++;
    }
    domain[j] = '\0';

    // printf("Username: %s", username);
    // printf("Domain: %s", domain);

    if ((strcmp(domain, previous_domain) == 0) || 
        (strcmp(domain, previous_domain_caps) == 0)) 
        {
            printf("Email address is outdated");
        }
    else {
            printf("Email address is okay");
        }

}

int main() {
    char email[100];
    printf("Enter email: ");
    scanf("%s", email);
    replaceEmail(email);
}

