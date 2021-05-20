// Prior Quneue����ȫ��������ʽʵ�ֵ����ѹ���
typedef struct MaxPriorQue {
    int** heap;  // ��ά���� heap[i][0/1] 0��idx,1��val
    int size;    // ��ǰ���д�С
    int capcity; // �����������
} MaxPriorQueStru, *pMaxPriorQueStru;

void init(pMaxPriorQueStru p, int size)
{
    p->size = 0;
    p->heap = (int**)malloc((size + 1) * sizeof(int*));
    // if (p->heap == NULL) { return NULL;}
    p->capcity = size + 1;

    int i;
    for (i = 0; i < p->capcity; i++) {
        p->heap[i] = (int *)malloc(2 * sizeof(int));
        // if (p->heap[i] == NULL) { return NULL; }
    }

    return;
}

int cmpValOrIdx(int *a, int *b)
{
    return a[1] == b[1] ? a[0] - b[0] : a[1] - b[1]; // ���ȱȽ���ֵ���ٱȽ��±�
}

// ��ȫ��������ʽʵ�ֵ����ѹ���
void push(pMaxPriorQueStru p, int idx, int val)
{
    // �ѱ�֤���㹻�󣬲��õ������
    p->size += 1;

    // �ȷ�ĩ�˽ڵ�
    p->heap[p->size][0] = idx;
    p->heap[p->size][1] = val;

    // ͨ�����ϲ�ڵ㲻�ϱȽϽ������ҵ�����λ��
    int i0 = p->size >> 1;
    int i1 = p->size;
    while (i0 > 0 && cmpValOrIdx(p->heap[i0], p->heap[i1]) < 0) {
        int *tmp = p->heap[i0]; // ��������ָ��ָ���һ��ָ���ַ
        p->heap[i0] = p->heap[i1];
        p->heap[i1] = tmp;
        i1 = i0; // ��������һ��ĩ�˽ڵ�Ƚ�
        i0 >>= 1;
    }

    return;
}

void pop(pMaxPriorQueStru p)
{
    // �����˵�ֵ��ĩβ�ڵ㽻�������Լ�����
    int *tmp = p->heap[1]; // ��������ָ��ָ���һ��ָ���ַ
    p->heap[1] = p->heap[p->size];
    p->heap[p->size] = tmp;
    p->size--;

    // �����ѣ���ĩβ�ڵ��³�������λ��
    int i = 1; // �Ӷ��˿�ʼ
    while (i <= p->size) {
        int l = i << 1; // ��������
        int r = l + 1; // �Һ�������
        int max = i;
        if (l <= p->size && cmpValOrIdx(p->heap[max], p->heap[l]) < 0) {
            max = l;
        }
        if (r <= p->size && cmpValOrIdx(p->heap[max], p->heap[r]) < 0) {
            max = r;
        }
        if (max == i) { // ������ڵ���������ֵ���������ϣ����˽�����ֵ���ҵ�����λ��
            break;
        }
        // ��Ҫ����
        int *tmp = p->heap[i]; // ��������ָ��ָ���һ��ָ���ַ
        p->heap[i] = p->heap[max];
        p->heap[max] = tmp;

        i = max; // ��max��ָ�뽻���󣬵�ǰmax�����Ǳ����������˵ĵײ�ֵ������һ���³��Ƚ�
    }
    // i�³�����ĩ�˻���ĩβ�ڵ����³�������λ�ã���������

    return;
}

int* top(pMaxPriorQueStru p)
{
    return p->heap[1]; // Ϊ�����±����ã�����0���ò���
}

void SetFree(pMaxPriorQueStru p)
{
    int i;
    for (i = 0; i < p->capcity; i++) {
        free(p->heap[i]);
    }
    free(p->heap);
    free(p);
    return;
}

// �������Ѷ������ݽṹ�����
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    if (k == 1) {
        *returnSize = numsSize;
        return nums;
    }

    // ѹ��ǰk������
    pMaxPriorQueStru q = (pMaxPriorQueStru)malloc(sizeof(MaxPriorQueStru));
    if (q == NULL) { return NULL; }
    init(q, numsSize);

    int resSize = numsSize - k + 1;
    int *resArr = (int *)malloc(resSize * sizeof(int));
    if (resArr == NULL) { return NULL; }

    int end = 0;
    int i;
    for (i = 0; i < k; i++) {
        push(q, i, nums[i]);
    }
    int *heap = top(q);
    // resArr[*returnSize++] = heap[1]; // �����ǣ�resArr[*returnSize], ��returnSize++�����ڵ�ַ���ˣ���Ԥ�ڲ���
    resArr[end++] = heap[1];
    //printf("%d \n", *returnSize);
    //printf("%d ", heap[1]);

    // ��k�����ƶ�
    for (i = k; i < numsSize; i++) {
        push(q, i, nums[i]);
        heap = top(q);
        while (heap[0] <= i - k) {
            pop(q);
            heap = top(q);
        }
        //resArr[*returnSize++] = heap[1];
        resArr[end++] = heap[1];
        // printf("%d \n", *returnSize);
        // printf("%d ", heap[1]);
    }
    //printf("%d \n", *returnSize);

    *returnSize = end;
    SetFree(q);

    return resArr;
}