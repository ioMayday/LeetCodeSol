// ����1288���56��ⷨ���Ľ�

// ver2:�Ż���i,j˫ָ����λ����

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
int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes)
{
    // ������������
    if (firstList == NULL || secondList == NULL || firstListSize == 0 || secondListSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = (int*)malloc(sizeof(int));
        if (*returnColumnSizes == NULL) {
            *returnSize = 0;
        }
        **returnColumnSizes = 0;
        return NULL;
    }

    // �����Ѿ����ź����
    // ���붯̬�ռ�
    int maxListSize = firstListSize + secondListSize;
    int **resArr = (int**)malloc(sizeof(int*) * maxListSize);
    if (resArr == NULL) {
        *returnSize = 0;
        return NULL; // ������
    }
 
    int num = 0; // �������������
    int a1, a2, b1, b2, left, right;
    int i = 0;
    int j = 0;
    int col = *firstListColSize;
    int minListSize = firstListSize < secondListSize ? firstListSize : secondListSize;
    while (i < firstListSize && j < secondListSize) {
        a1 = firstList[i][0];
        a2 = firstList[i][1];
        b1 = secondList[j][0];
        b2 = secondList[j][1];

        // �ж��Ƿ��н���
        if (a1 <= b2 && b1 <= a2) { // �н���
            left = a1 > b1 ? a1 : b1;
            right = a2 < b2 ? a2 : b2;
            // ���潻�����
            resArr[num] = (int*)malloc(sizeof(int) * col);
            if (resArr[num] == NULL) {
                *returnSize = 0;
                return NULL; // ������                    
            }
            resArr[num][0] = left;
            resArr[num][1] = right;
            num++;
        }

        // ��λ����
        if (a2 > b2) {
            j += 1;
        } else {
            i += 1;
        }
    }

    *returnColumnSizes = (int*)malloc(sizeof(int) * num);
    if (*returnColumnSizes == NULL) {
        *returnSize = 0;
        return NULL; // ������
    }
    for (i = 0; i < num; i++) {
        (*returnColumnSizes)[i] = col;
    }

    *returnSize = num;
    return resArr;

}

