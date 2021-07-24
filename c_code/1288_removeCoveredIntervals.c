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

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize)
{
    if (intervalsSize == 1) {
        return intervalsSize; // ��һ�����ݲ��úϲ�
    }

    int num = 0;
    qsort(intervals, intervalsSize, sizeof(int*), CompareIntArray2);
    int i, j;
    int row = intervalsSize;
    int col = *intervalsColSize;
    int left = intervals[0][0];
    int right = intervals[0][1];
    for (i = 1; i < row; i++) {
        if (right < intervals[i][1]) {
            if (right >= intervals[i][0]) {
                right = intervals[i][1]; // combine
            } else { // can't combine
                left = intervals[i][0];
                right = intervals[i][1];
            }
        } else {
            num++; // ���ϲ���������
        }
    }

    return intervalsSize - num; // ʣ�������� = �������� - ��ɾ����������
}