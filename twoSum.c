#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int index;
} cel;

void insert(cel *hash, int val, int n, int idx) {
    int i = val % n;
    while (hash[i].index != -1)
        i = (i + 1) % n;
    hash[i].key = val;
    hash[i].index = idx;
}

int search(cel *hash, int val, int n, int idx) {
    int i = val % n;
    while (hash[i].index != -1 && hash[i].key != val) 
        i = (i + 1) % n;
    return hash[i].index;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int x, i;
    int *res = malloc(2 * sizeof(int));
    cel *hashTable = malloc(numsSize * sizeof(cel));
    res[0] = NULL;
    res[1] = NULL;
    for (i = 0; i < numsSize; i++) 
        hashTable[i].index = -1;
    for (i = 0; i < numsSize; i++) {
        x = search(hashTable, target - nums[i], numsSize, i);
        if (x != -1) {
            res[0] = i;
            res[1] = x;
            return res;
        }
        else insert(hashTable, nums[i], numsSize, i);
    }
    return res;
}

int main () 
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9, *result;
    result = twoSum(nums, 4, target);
    printf("[%d, %d]", result[0], result[1]);
    return 0;
}
