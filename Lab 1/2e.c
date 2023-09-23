#include <stdio.h>
int main() {
    char str[50], *checker1, *checker2;
    scanf("%s", str);
    checker1 = str;

    while (*checker1 != '\0') {

        ++checker1;
    }
    --checker1;

    for (checker2 = str; checker1 >= checker2;) {

        if (*checker1 != *checker2) break;
        else {
            --checker1;
            checker2++;
        }
    }

    if (checker2 > checker1) {


       printf("The String is Palindrome");
    }

    else {
       printf("The String is not a Palindrome");
    }


  return 0;
}
