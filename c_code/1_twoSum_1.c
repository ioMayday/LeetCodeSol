/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**˼·���������������O��N^2��
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    *returnSize = 0; //��ʼ���ش�СΪ0
    
    for (int i=0; i < numsSize; i++) {
        for (int j=i+1; j < numsSize; j++) {
            if (target == (nums[i] + nums[j])) {
                int* ret = (int*)malloc(2*sizeof(int));
                if(ret ==NULL)
                    return NULL;
                
                *returnSize = 2;  //��ʾ���鷵�ش�С
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    
    return NULL;

}