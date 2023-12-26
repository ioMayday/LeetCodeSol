/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    if (k == 1) {
        *returnSize = numsSize;
        return nums;
    }
    // ��������˼·�������ҵݼ���˼·��ͬ��һ�������һ�ڶ������ֵ˼·
    int maxQueIdx[numsSize];
    int resSize = numsSize - k + 1;
    int *resArr = (int *)malloc(resSize * sizeof(int));
    if (resArr == NULL) { return NULL; }
    *returnSize = resSize;

    int i;
    int left = 0;
    int right = 0;
    for (i = 0; i < k; i++) {
        while (left < right && nums[i] >= nums[maxQueIdx[right - 1]]) {
            right--; // ������
        }
        maxQueIdx[right++] = i;
    }
    resSize = 0;
    resArr[resSize++] =  nums[maxQueIdx[left]];

    for (i = k; i < numsSize; i++) {
        // �����ڼ������Ԫ�رȶ�βԪ�ش��ڵ��ڣ����βԪ�س����� 
        // ֮���Ե���ҲҪ�����У�����Ϊ�±�idx���£��������Ƴ�����
        while (left < right && nums[i] >= nums[maxQueIdx[right - 1]]) { // ��ǰ��βԪ��Ϊright - 1,��βָ����right
            right--; // ������
        }
        maxQueIdx[right++] = i;

        while (maxQueIdx[left] <= i - k) { // ���ֵ���ڴ���
            left++; // ��������Ԫ�أ�����
        }
        resArr[resSize++] =  nums[maxQueIdx[left]];
    }

    return resArr;
}