//// ��һ���ⷨ�ǲο��Ĺٷ����
//// ��ƪ�ⷨ�ο���labuladong��C++����ģ�壬������C����ת��
//// https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/shou-ba-shou-shua-shu-zu-ti-mu/hua-dong-chuang-kou-ji-qiao-jin-jie
#define MAX_LEN 128
char * minWindow(char * s, char * t)
{
    int hashNeed[MAX_LEN] = {0};  // �ڱ�����û�и������
    int hashWindow[MAX_LEN] = {0};
    int start = 0;
    int end = 0;
    int minStart = 0;
    int minLen = INT_MAX;
    int lenS = strlen(s);
    int i, lenT = 0;
    int valid = 0;

    for (i = 0; t[i]; i++) {
        hashNeed[t[i]]++;
    }
    // lenT = i;  // ԭ��ﳤ��
    for (i = 0; i < MAX_LEN; i++) {
        if (hashNeed[i] != 0) { lenT++; } // �ĳɱ���Ԫ�ظ���
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
        // while (valid == need.size()) { // ԭ�����ʾ�ļ������� �� aa, ���ֻ��1����ֵΪ2
        while (valid == lenT) {           // ��lenT��Ϊ aa�ĳ��ȣ�Ϊ2
            // �����������С�����Ӵ�
            if (end - start < minLen) {
                minStart = start;
                minLen = end - start;
            }
            // d �ǽ��Ƴ����ڵ��ַ�
            char d = s[start];
            // ���ƴ���
            start++;
            // ���д��������ݵ�һϵ�и���
            if (hashNeed[d]) {
                if (hashWindow[d] == hashNeed[d])
                    valid--;
                hashWindow[d]--;
            }
        }
    }
    // ������С�����Ӵ�
    if (minLen == INT_MAX) { return ""; }
    s[minStart + minLen] = '\0'; // ����ԭ�ַ������أ�ʡ�ռ�

    return &s[minStart];
}