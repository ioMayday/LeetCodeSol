int removeDuplicates(int* nums, int numsSize)
{
    int i, start;

    if (numsSize <= 1) { // ���Ȳ�����1����ֱ�ӷ���
        return numsSize;
    }
    
    // ˫ָ��
    for (i = 1, start = 1; i < numsSize; i++) {
        if (nums[i - 1] == nums[i]) { // i�����Ҳ��ظ���ֵ
            continue;
        }

        if (start < i) { // һ�����ظ���start�±�С��i���򽫺�����ظ�ֵ��ֵ��ǰ���ظ��ĵط�
            nums[start] = nums[i]; // �Ӷ����ÿ����¿ռ䣬��start==i�������ظ���ֵ
        }
        start++; // ֻҪû���ظ�ֵ��start��Ҫ����һλ
    }

    return start;
}