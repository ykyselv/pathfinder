#include "../inc/libmx.h"

int mx_strcmp(const char*s1, const char*s2) {
    
    while(*s1 != '\0' || *s2 != '\0') {
        if (*s1 != *s2) 
        return *s1 - *s2;
    s1++;
    s2++;
    }
    return 0;
}

// int main() {
//     const char s1[] = "HellW";
//     const char s2[] = "Hello";
//     printf("%d\n", mx_strcmp(s1,s2));
// }
