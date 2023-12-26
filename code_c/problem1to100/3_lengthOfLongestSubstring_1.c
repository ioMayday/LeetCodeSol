/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//// ��ƪ�ⷨ�ο���labuladong��C++����ģ�壬������C����ת��
//// https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/shou-ba-shou-shua-shu-zu-ti-mu/hua-dong-chuang-kou-ji-qiao-jin-jie
#define MAX_LEN 128 // 26��Сд��ĸ
#define max(a, b) ((a > b) ? (a) : (b))
int lengthOfLongestSubstring(char * s)
{
    if (s == NULL) return 0;

    int hashWindow[MAX_LEN] = {0};
    int start = 0;
    int end = 0;
    int lenS = strlen(s);
    int res = 0;

    // ��¼��С�����Ӵ�����ʼ����������
    while (end < lenS) {
        // c �ǽ����봰�ڵ��ַ�
        char c = s[end];
        // ���´�������
        hashWindow[c]++;
        // ���ƴ���
        end++;

        // ��ര������
        while (hashWindow[c] > 1) {   // ��ǰ���ڴ����ظ�Ԫ�أ��ظ����ƣ�ֱ���Ƴ��Ǹ��ظ�Ԫ�ص�ֵ������
            // d �ǽ��Ƴ����ڵ��ַ�
            char d = s[start];
            // ���ƴ���
            start++;
            // ���д��������ݵ�һϵ�и���
            hashWindow[d]--; // ��ǰ���ں��еļ�ֵ����
        }
        // ������õ���ǰ���ظ��Ӵ��ĳ��ȣ��ȽϺ����
        res = max(res, end - start);
    }

    // �����귵�س���
    return res;
}