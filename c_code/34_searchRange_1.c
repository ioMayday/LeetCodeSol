/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// �Լ���˼·��
// 1�����ö��ַ��ҵ����ֵ
// 2�����ڶ��ַ���С�ķ�Χ�ڣ����������ұ߽�

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    // ��̬���䷵������
    int *returnArray = (int *)malloc(2 * sizeof(int)); // ��������
    if (returnArray == NULL || returnSize == NULL) return NULL;
    returnArray[0] = -1;
    returnArray[1] = -1;
	*returnSize = 2; // ��������ĳ���, [-1, -1]ֻ��������

    // returnArray = &g_returnArray[0];

    if (nums == NULL) {
        return returnArray;
    }

    // �ȶ����ҵ���ȵĵط�
    int left = 0;
    int right = numsSize - 1; // ����ұ�����
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            break;  // �ҵ�һ�����ֵ��������
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    // �ж��Ƿ�Ϊ�ҵ����ֵ���������
    if (left <= right) { // ��������
        // �����������ұ߽�
        // ����߽�
        int tmp = mid - 1;
        while (tmp >= left && nums[tmp] == target) {
            tmp--;
        }
        returnArray[0] = ++tmp;  // ++�������ǰ�棬���Լ��ٸ�ֵ
        // ���ұ߽�
        tmp = mid + 1;
        while (tmp <= right && nums[tmp] == target) {
            tmp++;
        }
        returnArray[1] = --tmp;  // --�������ǰ��
    } 

    return returnArray; // ������
}