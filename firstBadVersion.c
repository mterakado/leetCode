#include <stdio.h>

int isBadVersion(int version) {
    return (version >= 3);
}

int divide(int start, int end) {
    int m = start + (end - start)/2;
    if (isBadVersion(m)) {
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
