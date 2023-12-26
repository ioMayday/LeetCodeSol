// ���ⲻ�죬��Ҫ����ϰ
// ֪��˼·��1h��д��debug��ͨ��
int GetMaxVal(int* weights, int weightsSize, int* sum)
{
    int maxVal = 0;
    int resSum = 0;
    int i;
    for (i = 0; i < weightsSize; i++) {
        if (weights[i] > maxVal) maxVal = weights[i];
        resSum += weights[i];
    }

    *sum = resSum;
    return maxVal;
}

int CanFinish(int* weights, int weightsSize, int D, int load)
{
    int i = 0, day;
    
    for (day = 1; day <= D; day++) { //day�����ǰ���ӵģ��ʺ�for
        int curLoad = load;
        while ((curLoad -= weights[i]) >= 0) { //ע���Ǵ��ڵ��ڣ����Ǵ���
            i++;
            if (i == weightsSize) return 1; // <=D��������
        }
    }

    return 0; // ��D����û����
}

// ���ֲ��ҵ�Ӧ��
int shipWithinDays(int* weights, int weightsSize, int D){
    int right = -1;  // �����������Ϊ���а��������ͣ�һ�θ㶨
    int left = GetMaxVal(weights, weightsSize, &right);  // ���İ���������Ϊ��С�Ĵ���������
    int sum = right;
    while (left <= right) { // ������߽磬�������������
        int mid = left + (right - left) / 2;
        if (CanFinish(weights, weightsSize, D, mid)) {
            right = mid - 1;
        } else {
            left = mid + 1; // ��mid�������㣬mid���µĸ�����
        }
    }
    // ���ü���߽磬�������������б߽���������
    // �����Է����գ�����У����
    if (left > sum) return -1;  // ����������Ŀ���������ܲ�������

    return left;
}