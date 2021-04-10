/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**˼·���������鸱�������򣬼б���С��Χ����Ȼ���죬���������ڴ棬����O��N��
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct object {
    int val;
    int index; //��������󽻻�˳�����ʧ��ԭ����ֵ��Ӧ���±�
};

static int compare(const void *a, const void *b)
{
    return ((struct object *) a)->val - ((struct object *) b)->val;
}

static int * twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j;
    struct object *objs = malloc(numsSize * sizeof(*objs));
    for (i = 0; i < numsSize; i++) {
        objs[i].val = nums[i];
        objs[i].index = i;
    }
    qsort(objs, numsSize, sizeof(*objs), compare); //����ʱ��ÿ��objs[i]����������󶼽�����˳��
    
    int *results = malloc(2 * sizeof(int));
    i = 0;
    j = numsSize - 1;
    while (i < j) {
        int sum = objs[i].val + objs[j].val;
        if (sum < target) {
            i++;
        } else if (sum > target) {
            j--;
        } else {
            results[0] = objs[i].index;
            results[1] = objs[j].index;
            *returnSize = 2;
            return results;
        }
    }
    return NULL;
}



// 2020��9��13�� 17:30:54
// ��������˼·��ɵĴ���
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ObjNums {
    int val;
    int index;
};

static int cmp(const void* a, const void* b)  //�Ƚ����
{
    return ( *(struct ObjNums *)a ).val - ( *(struct ObjNums *) b).val; //��С�������򣬽���return��a��b��Ӵ�С����
	
    // ע�������¶������ -> ������� ֻ��Ϊ . ���ܱ���ͨ��
	// return ((struct object *) a)->val - ((struct object *) b)->val;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *ret = (int *) malloc( 2 * sizeof(int));
    struct ObjNums *sortedNums = (struct ObjNums *) malloc(numsSize * sizeof(*sortedNums));
    int i,j;
    *returnSize = 0; 

    for(i=0; i < numsSize; i++) { // ��������
        sortedNums[i].val = nums[i];
        sortedNums[i].index = i;
    }
    qsort(sortedNums, numsSize, sizeof(*sortedNums), cmp); // ����,��С����

    i = 0;
    j = numsSize - 1;
    while (i < j) { // �б���ͣ�һ��ѭ������
        //if (sortedNums[(i + j) / 2].val > target) { // �м�����target�����۰�������
        //    j = (i + j) / 2 - 1;
		//    continue;   
        //} //�������if�ж�����и���������ʱ���ʧЧ������ -3 -2 -1 1 2 3 5�� target = 0
        if (sortedNums[i].val + sortedNums[j].val < target) {
            i++; // ��������
        }
        else if (sortedNums[i].val + sortedNums[j].val > target) {
            j--; //
        }
        else {
            ret[0] = sortedNums[i].index;
            ret[1] = sortedNums[j].index;
            *returnSize = 2; // ���Ҫ�з���ֵ��С����Ȼret���鲻֪��������ٸ�
            return ret;
        }
    }
    return ret; // Ϊ���Ϲ淶���ú���ĩβ�з���ֵ����ʵԤ����������������£��������и����
}



