#include <stdio.h>

int isBadVersion(int version) {
    return (version >= 3);
}

int divide(int start, int end) {
    int m = start + (end - start)/2;
    printf("--- m: %d, start: %d, end: %d\n", m, start, end);
    if (isBadVersion(m)) {
        printf("m: %d, start: %d, end: %d\n", m, start, end);
        if (end - start == 0) 
            return m;
	return divide(start, m);
    }
    else return divide(m + 1, end);
}

int firstBadVersion(int n) {
    return divide(1, n);
}

int main() {
    int a = firstBadVersion(12);
    printf("%d\n", a);
    return 0;
}
