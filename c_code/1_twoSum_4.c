/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 2021��4��15�� 22:28:26
// ˼·��
// �ȿ������������ṹ������������±��ֵ
// �Խṹ����������
// �бƷ���ͣ��ҵ���target��ȵ��±�
typedef struct SortedNums {
    int val;
    int idx;
} SortedNums, *pSortedNums;

int comp(const void *a, const void *b)
{
    return ((pSortedNums)a)->val - ((pSortedNums)b)->val; // ��������
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    if (nums == NULL || numsSize == 0) return NULL;

    int *resArray = (int *)malloc(2 * sizeof(int));
    if (resArray == NULL) return NULL;
    *returnSize = 2;
    resArray[0] = -1;
    resArray[1] = -1;

    pSortedNums qsortedNums = (pSortedNums)malloc(numsSize * sizeof(SortedNums));
    if (qsortedNums == NULL) return NULL;
    // ����
    int i;
    for (i = 0; i < numsSize; i++) {
        qsortedNums[i].val = nums[i];
        qsortedNums[i].idx = i;
    }

    // ����
    qsort(qsortedNums, numsSize, sizeof(SortedNums), comp);
    
    i = 0;
    int j = numsSize - 1; // ������[i, j]
    while (i < j) { // ��i==jʱ��û�ҵ�����û��
        if (qsortedNums[i].val + qsortedNums[j].val < target) {
            i++;  // ��߽������ƣ�������
        } else if (qsortedNums[i].val + qsortedNums[j].val > target) {
            j--; // �ұ߽������ƣ���С���
        } else if (qsortedNums[i].val + qsortedNums[j].val == target) {
            resArray[0] = qsortedNums[i].idx;
            resArray[1] = qsortedNums[j].idx;
            break;
        }
    }

    return resArray;
}
