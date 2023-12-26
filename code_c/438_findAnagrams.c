/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//// ��ƪ�ⷨ�ο���labuladong��C++����ģ�壬������C����ת��
//// https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/shou-ba-shou-shua-shu-zu-ti-mu/hua-dong-chuang-kou-ji-qiao-jin-jie
#define MAX_LEN 128 // 26��Сд��ĸ
#define MAX_SIZE 20100
int* findAnagrams(char * s, char * t, int* returnSize)
{
    if (s == NULL) return NULL;
    int hashNeed[MAX_LEN] = {0};  // �ڱ�����û�и������
    int hashWindow[MAX_LEN] = {0};
    int start = 0;
    int end = 0;
    int minStart = 0;
    int minLen = INT_MAX;
    int lenS = strlen(s);
    int i, lenT = 0;
    int valid = 0;
    int keyNum = 0;

    int *resArray = (int*)malloc(MAX_SIZE * sizeof(int));
    if (resArray == NULL) return NULL;
    int returnNum = 0;

    for (i = 0; t[i]; i++) {
        hashNeed[t[i]]++;
    }
    lenT = i;  // ԭ��ﳤ��
    for (i = 0; i < MAX_LEN; i++) {
        if (hashNeed[i] != 0) { keyNum++; } // �ĳɱ���Ԫ�ظ���
    }

    // ��¼��С�����Ӵ�����ʼ����������
    while (end < lenS) {
        // c �ǽ����봰�ڵ��ַ�
        char c = s[end];
        // ���ƴ���
        end++;
        // ���д��������ݵ�һϵ�и���
        if (hashNeed[c]) { // count�����ǲ��Ҹ�ֵ�Ƿ����
            hashWindow[c]++;
            if (hashWindow[c] == hashNeed[c]) // ԭ����
                valid++;
        }

        // �ж���ര���Ƿ�Ҫ����
        while (end - start >= lenT) {       // ��ǰ��������t�ĳ���ʱ����Ҫ����left����Ϊ�����ǹ̶���lenT
            // �����������С�����Ӵ�
            if (valid == keyNum) { // ���ĸ���
                 // ����ƥ����ַ���
                 resArray[returnNum++] = start;
            }
            // d �ǽ��Ƴ����ڵ��ַ�
            char d = s[start];
            // ���ƴ���
            start++;
            // ���д��������ݵ�һϵ�и���
            if (hashNeed[d]) {
                if (hashWindow[d] == hashNeed[d])
                    valid--; // ƥ������1
                hashWindow[d]--; // ��ǰ���ں��еļ�ֵ����
            }
        }
    }

    // �����귵����������͸���
    *returnSize = returnNum;
    return resArray;
}