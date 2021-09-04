/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/*
    �������ȶ���/�ѵȸ��ӽṹ������˫ָ��˼·
    ���ģ�
        1��������һ�����飬��¼nums1[i]��nums2[]�����ϵ���ʼλ��
        2��ÿ����1����Сֵ������nums1��forѭ��ƥ��һ����С�ģ���steps[i]����㿪ʼ
*/
int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes)
{
    long long tmp = (long long)nums1Size * nums2Size;
    k = (k > tmp) ? tmp : k;
    int *steps = (int*)malloc(nums1Size * sizeof(int));
    if (steps == NULL) {
        return NULL;
    }
    memset(steps, 0, nums1Size * sizeof(int));

    // ���뷵���ڴ�
    int **returnArr = (int**)malloc(k * sizeof(int*) + 100); // ����ÿ�е�����
    if (returnArr == NULL) {
        return NULL;
    }
    *returnColumnSizes = (int*)malloc(k * sizeof(int) + 100); // ����ÿ�е�����
    if (*returnColumnSizes == NULL) {
        return NULL;
    }
    // printf("k = %d\n", k);

    int n1MinIdx = 0;
    int i;
    for (i = 0; i < k; i++) {
        int min = INT_MAX; // minҪ����ÿһ�ֲ���ǰ��ʼ�����������һ�ֵ�min
        for (int j = 0; j < nums1Size; j++) { // ��һ������ƥ�����Сֵ
            if (steps[j] < nums2Size && nums1[j] + nums2[steps[j]] < min) {
                min = nums1[j] + nums2[steps[j]];
                n1MinIdx = j;
            }
        }
        // ���յõ���Сֵ��Ӧ��nums1��idx���Լ���Ӧ��nums2[]�±�steps[idx]
        int *p = (int*)malloc(2 * sizeof(int));
        if (p == NULL) {
            return NULL;
        }
        // printf("n1MinIdx = %d\n", n1MinIdx);
        p[0] = nums1[n1MinIdx];
        p[1] = nums2[steps[n1MinIdx]];
        // printf("n1MinIdx = %d\n", n1MinIdx);
        steps[n1MinIdx] += 1; // n1MindIdx��Ӧnums2�±�ֵ����һλ
        returnArr[i] = p;
        returnColumnSizes[0][i] = 2; // ÿ�е�����Ϊ2
        // printf("returnColumnSizes[0][%d] = %d\n", i, returnColumnSizes[0][i]);
    }
    *returnSize = k;
    return returnArr;
}

/*
    ��л�����У�cnwsssss�ṩ��˼·

    ˼·��
    ��֮ǰ������Ŀ˼�������һ����������¼num1��ÿ��Ԫ����nums2�����˶�Զ�Ϳ��ԣ�ÿ��ѭ������nums1��nums2��������С��nums1��ǰ��һ��

    JS���룺
var kSmallestPairs = function(nums1, nums2, k) {
    if (k > nums1.length * nums2.length ) {
        k = nums1.length * nums2.length
    }
    if (nums1.length == 0 || nums2.length == 0) {
        return [];
    }
    let steps = new Array(nums1.length);
    for (let i = 0; i < steps.length; i++) {
        steps[i] = 0;
    }
    let results = [];
    for (let i = 0; i < k; i++) {
        let min = Number.MAX_VALUE;
        let minStepIndex = 0;
        for (let j = 0; j < nums1.length; j++) {
            if (steps[j] < nums2.length && nums2[steps[j]] + nums1[j] < min) {
                min = nums2[steps[j]] + nums1[j];
                minStepIndex = j;
            }
        }
        results.push([nums1[minStepIndex], nums2[steps[minStepIndex]]]);
        steps[minStepIndex]++;
    }
    
    return results;
};

*/