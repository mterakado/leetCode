#include <stdio.h> 

int removeDuplicates(int* nums, int numSize) {
   int start = 0, end;
   if (numSize <= 0 || !nums)
       return 0;
   for (end = 1; end < numSize; end++) {
       if (nums[end] != nums[start])
           nums[++start] = nums[end];
   }
   return start + 1;
}

int main() {
   int array[6] = { 1, 1, 1, 3, 3, 4};
   int r;
   r = removeDuplicates( array, 6 );
   printf ("%d\n", r); 
   return 0;
}
