// �����ⷨ��runtime error: signed integer overflow�����ַ����ᣬ�����������£�
// [332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184]
// 823855818
// �����ڶ��ַ�ʱ�������ұ߽�ʱ���׳����⣬Ҫ������ϰ���������

int GetMaxVal(int* piles, int pilesSize)
{
    int maxVal, i;
    maxVal = INT_MIN;
    for (i = 0; i < pilesSize; i++) {
        if (piles[i] > maxVal) {
            maxVal = piles[i];
        }
    }

    return maxVal;
}

int timeOf(int s, int speed)
{
    return s / speed + ((s % speed > 0) ? 1 : 0);
}

int CanFinish(int* piles, int pilesSize, int h, int speed)
{
    int isFlag = 0;
    int i, timeSum = 0;
    for (i = 0; i < pilesSize; i++) {
        timeSum += timeOf(piles[i], speed);
    }
    if (timeSum <= h) isFlag = 1;

    return isFlag;
}

int minEatingSpeed(int* piles, int pilesSize, int h){
     // ���ֲ��ҽⷨ
     if (piles == NULL || pilesSize == 0) return -1;

     int minSpeed = 1;
     int right = GetMaxVal(piles, pilesSize);
     
     while (minSpeed <= right) { // �����ʱ����߽磬����Сֵ
         int mid = minSpeed + (right - minSpeed) / 2;
         if (CanFinish(piles, pilesSize, h, mid)) { // ������
             right = mid - 1; // �Ҳ�߽�����
        } else {  // ��������㣬�򲻶���С�Ҳ෶Χ
             minSpeed = mid + 1;  // ���߽����ƣ�midԽ�󣬱�ʾ�ٶ�Խ�죬Խ��������
         }
     }
     
     return minSpeed;
}
