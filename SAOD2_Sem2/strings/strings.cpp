

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
void string_copy(char* d, char* s) {
	for (char* pd = d, *ps = s; (*pd++ = *ps++);)
		;
}
int len(const char* s) {
    int i = 0;
    while (*s++ != 0)
        i++;
    return i;
}

int compare(const char* s, const char* t) {
    while (*s != 0 && *t != 0) {
        int c = *s - *t;
        if (c != 0) {
            return c;
        }
        s++;
        t++;
    }
    return 0;
}
int main()
{
	char str[] = "Hello!";
	cout << str << endl;
	cout << strlen(str) << ' ' << sizeof(str) << endl;

    char t[32];
    string_copy(t, str);
    printf("cop: %s\n", t);

    printf("len: %i\n", len(str));
    printf("compare: %i\n", compare(str, t));
    t[0] = 'g';
    printf("compare: %i\n", compare(str, t));

    return 0;
}

