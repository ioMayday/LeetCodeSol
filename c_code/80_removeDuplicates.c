// �����⣺26,27,80,283
int removeDuplicates(int* nums, int numsSize)
{
    int i, start;

    if (numsSize <= 2) { // ���Ȳ�����1����ֱ�ӷ���
        return numsSize;
    }
    
    // ˫ָ��
    int cnt = 1;
    for (i = 1, start = 1; i < numsSize; i++) {
        if (nums[i - 1] == nums[i]) { // i�����Ҳ��ظ���ֵ
            cnt++; // �õ����ִ���
            if (cnt > 2) { // ���ִ�������2����start���겻��λ
                continue;
            }
        } else {
            cnt = 1; // ����ʱ
        }
        if (nums[i - 1] != nums[i] || cnt == 2) { // �����ʱ ������cnt==2ʱ�ɸ�ֵ
            if (start < i) { // һ�����ظ���start�±�С��i���򽫺�����ظ�ֵ��ֵ��ǰ���ظ��ĵط�
                // printf("start=%d, i=%d\n", start, i); // for debug
                nums[start] = nums[i]; // �Ӷ����ÿ����¿ռ䣬��start==i�������ظ���ֵ
            }
        }
        // ע��start++һ��Ҫ����continue���Ҳ��ܺ�i++�ϲ�
        start++; // ֻҪû���ظ�ֵ��start��Ҫ����һλ
    }

    return start;
}