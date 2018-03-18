#include <stdio.h>
#include <string.h>

void revString( char* s, int start, int end) {
    char aux;
    int m = start + (end - start + 1)/2;
    for (int i = start, j = end; i < m; i++, j--) {
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
    }
}

char* reverseString( char* s, int k) {
    int count = 1, n = strlen(s), i, j, l;
    if (n <= k) {
         revString( s, 0, n - 1);
         return s;
    }
    for (i = k; i < n; i += k) {
        if (count % 2 != 0) 
            revString( s, i - k, i - 1);
        count += 1;
    }
    l = (count - 1) * k;
    if (count % 2 != 0 && l != n) {
        j = n - l;
        revString(s, l, n - 1);
    }
    return s;
}

int main() {
    char t[] = "hyzqyljrnigxvdtneasepfahmtyhlohwxmkqcdfehybknvdmfrfvtbsovjbdhevlfxpdaovjgunjqlimjkfnqcqnajmebeddqsgl";
    char* aux;
    printf("%d\n ", strlen(t));
    aux = reverseString(t, 39);
    for (int i = 0; i < strlen(t); i++)
        printf("%c ", aux[i]);
    return 0;
}
