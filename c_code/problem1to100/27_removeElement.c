// �����⣺26,27,80,283
int removeElement(int* nums, int numsSize, int val)
{
    int i, start;
    
    // ˫ָ��
    for (i = 0, start = 0; i < numsSize; i++) {
        if (val == nums[i]) { // i������val��ֵ
            continue;
        }

        if (start < i) { // һ�����ظ���start�±�С��i���򽫺�����ظ�ֵ��ֵ��ǰ���ظ��ĵط�
            nums[start] = nums[i]; // �Ӷ����ÿ����¿ռ䣬��start==i�������ظ���ֵ
        }
        start++; // ֻҪû���ظ�ֵ��start��Ҫ����һλ
    }

    return start;
}