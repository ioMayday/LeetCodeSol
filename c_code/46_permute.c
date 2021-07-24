/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// �ο���1��labuladong 2������
// ���ߣ�zhangdengyu
// ���ӣ�https://leetcode-cn.com/problems/permutations/solution/46-quan-pai-lie-by-ac_fun-peev/
// ��Դ�����ۣ�LeetCode��
// ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

int isContain(int *nums, int len, int val)
{
    int flag = 0;
    int i;
    for (i = 0; i < len; i++) {
        if (nums[i] == val) {
            flag = 1;
            break;
        }
    }
    return flag;
}

int g_trackNum = 0; // ���ڵݹ����ʱ��ʱ��ջ��
int g_rowPos = 0;
void backtrack(int *nums, int numsSize, int **returnColumnSizes, int *track)
{
    // ����Ҷ�ڵ�track����returnColumSizes����¼��·���Ѿ��������鳤��ֹͣ
    int i;
    if (g_trackNum == numsSize) {
        // printf("back: g_rowPos = %d\n", g_rowPos);
        for (i = 0; i < numsSize; i++) {
            // printf("back: g_rowPos = %d\n", g_rowPos);
            returnColumnSizes[g_rowPos][i] = track[i];
        }
        g_rowPos++;
        return;
    }

    // �ݹ����
    for (i = 0; i < numsSize; i++) {
        // ȷ�ϵ�ǰֵ�Ƿ���track��
        if (isContain(track, g_trackNum, nums[i])) {
            continue;
        }

        // ���ڵĻ�������track
        // printf("back: g_trackNum = %d\n", g_trackNum);
        track[g_trackNum++] = nums[i];
        
        // ����������
        backtrack(nums, numsSize, returnColumnSizes, track);
        // �ڵ㷵�غ�ȡ��track�е�ֵ
        g_trackNum--;
    }

    return;
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    // �������п��ܵ�����n!
    int row = 1, i;
    for (i = numsSize; i > 0; i--) {
        row *= i;
    }
    *returnSize = row;

    // printf("row = %d\n", row);

    // ���㷵��������ÿ�е�����
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    if (returnColumnSizes == NULL) {
        return NULL;
    }
    for (int i = 0; i < row; i++) {
        // (*returnColumnSizes)[i] = numsSize;
        // �ȼ���������䣬returnColumnSizes[0]������ָ�������Ϊһ��ָ�룬[i]�����õ���Ӧ��val���ڵط���ɸ�ֵ
        returnColumnSizes[0][i] = numsSize;
    }

    // �����Ӧ��С�Ķ�ά���鲢����ռ�
    int **res = (int **)malloc((row + 10) * sizeof(int*));
    if (res == NULL) {
        return NULL;
    }
    int *p;
    for (i = 0; i < row; i++) {
        p = (int*)malloc((numsSize + 10) * sizeof(int));
        if (p == NULL) {
            return NULL;
        }
        res[i] = p;
    }
    p = (int*)malloc(numsSize * sizeof(int));
    if (p == NULL) {
        return NULL;
    }
    int *track = p;

    // ����������п�������
    g_trackNum = 0;
    g_rowPos = 0;
    backtrack(nums, numsSize, res, track); // ��0�п�ʼ�Ž��

    // ����res
    return res;
}