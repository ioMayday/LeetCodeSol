
// input :
// [], 0
// [1], 1
// [1], 0

// ���ص���ok
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    // ��̬���䷵������
    int *returnArray = (int *)malloc(2 * sizeof(int)); // ��������
    if (returnArray == NULL || returnSize == NULL) return NULL;
    returnArray[0] = -1;
    returnArray[1] = -1;
	*returnSize = 2; // ��������ĳ���, [-1, -1]ֻ��������

    if (nums == NULL || numsSize == 0) { // [],0 ����ʱ��nums����Ϊ��ָ�룬ֻ�Ƕ����ˣ���δ��ֵ��
        return returnArray;              // ��numsSize=0����������
    }

    // ����߽�
    int left = 0;
    int right = numsSize - 1; // ����ұ�����
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    // �߽����Ƽ򻯣�������߽����Ƿ񳬹�numsSize,��Ϊleft�Ǵ�0��ʼ�������ģ�������С��0
    if (left >= numsSize || nums[left] != target) { ; }
    else  returnArray[0] = left;

    // ���ұ߽�
    left = 0;
    right = numsSize - 1; // ����ұ�����
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            left = mid + 1;  // ע��Ҫ������mid + 1������������෶Χ
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }

     // �߽����Ƽ򻯣������ұ߽����Ƿ�С��0����Ϊright�Ǵ�numsSize-1��ʼ���¼��ģ������д���numsSize
    if (right < 0 || nums[right] != target) { ; }
    else returnArray[1] = right;

    return returnArray; // ������
}

int main(void)
{
    int nums[] = {5,7,7,8,8,10};
    int returnSize;
    int *res = searchRange(NULL, 0, 0, &returnSize);
    printf("%d %d\n", res[0], res[1]);

    return 0;
}
