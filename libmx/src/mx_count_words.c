#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    int counter = 0;

    if (str == NULL)
        return -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c && str[i + 1] != '\0')
            i++;
        if (str[i] != c) {
            counter++;
            while((str[i]) != c && str[i + 1] != '\0' )
                i++;
        }        
    }
    return counter;
}

// int main() {
// const char str[]=  "     follow  *   the  white rabbit ";
// printf("%d\n",mx_count_words(str, '*')); //returns 2
// printf("%d\n",mx_count_words(str, ' '  )); //returns 5
// printf("%d\n",mx_count_words(NULL, ' '));
// } 
