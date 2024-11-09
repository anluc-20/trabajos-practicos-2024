#include <stdio.h>
int main()
{
        int nums[] = {8,6,3,5,2};
        int aux;
        for(int i = 5 - 1; i > 0; i--) {
                for (int j = 0; j < i; j++) {
                        if(nums[j]> nums[j+1]) {
                                aux = nums[j];
                                nums[j] = nums[j+1];
                                nums[j+1] = aux;
                        }
                }
        }
        for (int i = 0; i < 5; i++) {
                printf("%d, ", nums[i]);
        }
}