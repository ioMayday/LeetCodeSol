// ����1288��ⷨ���Ľ�

/*
1����������ʼ��С������ͬʱ�յ�Ӵ�С
2����������кϲ���˫ָ��left/right���ƶ����ж��������Ƿ������棬���ϲ�
*/

int CompareIntArray2(const void *a, const void *b)
{
    int ret = *(*(int **)a) - *(*(int **)b);
    if (ret == 0) { // �����ͬʱ���յ����Ƚ�
        ret = *(*(int **)b + 1) - *(*(int **)a + 1);
    }
    return ret;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    if (intervalsSize == 1) {
        *returnSize = 1;
        *returnColumnSizes = (int*)malloc(sizeof(int));
        if (*returnColumnSizes == NULL) {
            *returnSize = 0;
        }
        **returnColumnSizes = *intervalsColSize;
        return intervals; // ��һ�����ݲ��úϲ�
    }

    qsort(intervals, intervalsSize, sizeof(int*), CompareIntArray2);
    int i, j;
    int row = intervalsSize;
    int col = *intervalsColSize;

    // ���붯̬�ռ�
    int **resArr = (int**)malloc(sizeof(int*) * intervalsSize);
    if (resArr == NULL) {
        *returnSize = 0;
        return intervals; // ������
    }
 
    int num = 0; // �������������
    int left = intervals[0][0];
    int right = intervals[0][1];
    for (i = 1; i < row; i++) {
        if (right < intervals[i][1]) {
            if (right >= intervals[i][0]) {
                right = intervals[i][1]; // combine
            } else { // can't combine
                // ���浱ǰ��������
                resArr[num] = (int*)malloc(sizeof(int) * col);
                if (resArr[num] == NULL) {
                    *returnSize = 0;
                    return intervals; // ������                    
                }
                resArr[num][0] = left;
                resArr[num][1] = right;
                num++;

                // �ƶ�����һ����
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
    }
    // �������һ������������
    resArr[num] = (int*)malloc(sizeof(int) * col);
    if (resArr[num] == NULL) {
        *returnSize = 0;
        return intervals; // ������                    
    }
    resArr[num][0] = left;
    resArr[num][1] = right;
    num++;

    *returnColumnSizes = (int*)malloc(sizeof(int) * num);
    if (*returnColumnSizes == NULL) {
        *returnSize = 0;
        return intervals; // ������
    }
    for (i = 0; i < num; i++) {
        (*returnColumnSizes)[i] = col;
    }

    *returnSize = num;
    return resArr;

}