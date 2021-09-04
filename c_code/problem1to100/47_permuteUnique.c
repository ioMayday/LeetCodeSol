/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/*
˼·��
1���Ȱ������Ϊ��������
2���������������ظ����������ȫ���й���
3�����õڶ�����֮ǰ��ͬ������continue��ֱ����ͬ
*/

int *g_vis;

// ����backtrackģ��
void backtrack(int *nums, int numsSize, int *returnSize, int **res, int *track, int idx)
{
    // ����Ҷ�ڵ�track����returnColumSizes����¼��·���Ѿ��������鳤��ֹͣ
    int i;
    if (idx == numsSize) {
        int *ans = (int *)malloc(sizeof(int) * numsSize);
        if (ans == NULL) {
            return;
        }
        memcpy(ans, track, sizeof(int) * numsSize);
        res[(*returnSize)++] = ans;
        return;
    }

    // �ݹ����
    for (i = 0; i < numsSize; i++) {
        // ȷ�ϵ�ǰֵ�Ƿ���track��
        // i > 0 && nums[i] == nums[i - 1] && !g_vis[i - 1] ��֤�ظ���������ֻ�е�һ��û������Ĳ��ܱ����룬���ظ����ķ��ã�ֻ��һ��˳�򣬴���������ȥȡ�ظ������ţ��Ӷ������ظ�����
        if (g_vis[i] || (i > 0 && nums[i] == nums[i - 1] && !g_vis[i - 1])) {
            continue;
        }
        // �������ȥ���ж������Ǻ����еĺ���

        // ���ڵĻ�������track
        track[idx] = nums[i];
        g_vis[i] = 1;
        // ����������
        backtrack(nums, numsSize, returnSize, res, track, idx + 1);
        // �ڵ㷵�غ�ȡ��track�е�ֵ
        g_vis[i] = 0;
    }

    return;
}

int cmp(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

// ����funcģ��
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    // �����Ӧ��С�Ķ�ά���鲢����ռ�
    int maxRow = 1, i;
    for (i = numsSize; i > 0; i--) {
        maxRow *= i;
    }
    int **res = (int **)malloc((maxRow) * sizeof(int*));
    if (res == NULL) {
        return NULL;
    }

    // ����vis��Ǻ�track����
    int *p = (int*)malloc(numsSize * sizeof(int));
    if (p == NULL) {
        return NULL;
    }
    int *track = p;
    p = (int*)malloc(numsSize * sizeof(int));
    if (p == NULL) {
        return NULL;
    }
    g_vis = p;
    memset(g_vis, 0, numsSize * sizeof(int));

    // �ȶ���������
    qsort(nums, numsSize, sizeof(int), cmp);

    // ����������п�������
    *returnSize = 0;
    int idx = 0;
    backtrack(nums, numsSize, returnSize, res, track, idx); // ��0�п�ʼ�Ž��

    // ���п��ܵ�����ֻ�л�������֪��
    // ���㷵��������ÿ�е�����
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    if (returnColumnSizes == NULL) {
        return NULL;
    }
    for (i = 0; i < *returnSize; i++) {
        // (*returnColumnSizes)[i] = numsSize;
        // �ȼ���������䣬returnColumnSizes[0]������ָ�������Ϊһ��ָ�룬[i]�����õ���Ӧ��val���ڵط���ɸ�ֵ
        returnColumnSizes[0][i] = numsSize;
    }

    return res;
}