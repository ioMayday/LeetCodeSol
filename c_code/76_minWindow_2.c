#define MAX_LEN 128 // ascii��ֻ��128��
char * minWindow(char * s, char * t)
{
    int hash[MAX_LEN] = {0}; // ascii��hash��ӳ��
    int left = 0;
    int right = 0;
    int minStart = 0;
    int minLen = INT_MAX;
    int lenS = strlen(s);
    // int lenT = strlen(t);

    int i, lenT;
    for (i = 0; t[i]; i++) {
        hash[t[i]]++;
    }
    lenT = i;

    int notFitNum = lenT;
    // O(n)������rightŲ����ĩβ����
    while (right < lenS) { // ����������ҿ�
        // ���ҷ���������������right
        if (hash[s[right]] > 0) {
            notFitNum--;
        }
        hash[s[right]]--;  // ��ָ�뾭��ʱ������ƥ��ļ�����������ƥ��ļ���0
        right++;

        // �������Ž⣬����left
        while (notFitNum == 0) { // ��ǰ��Χ��������
            if (right - left < minLen) { // �����µ�ǰ����
                minLen = right - left;
                minStart = left;
            }

            // �ص��ص�
            hash[s[left]]++;  // ��ָ���ƶ�ʱ���ְѸ����ӻ���
            if (hash[s[left]] > 0) { // ����left����С����
                notFitNum++;
            }
            left++; // �ҵ��������left++���������¸���
        }

    }
    if (minLen == INT_MAX) { return ""; }
    s[minStart + minLen] = '\0'; // ����ԭ�ַ������أ�ʡ�ռ�

    return &s[minStart];
}

// // Ref Code
//#define LEN 125
//
//char * minWindow(char * s, char * t){
//    int hash[LEN] = {0};    /* �����ϣ�� */
//    int start = 0, end = 0; /* ����ָ�� */
//    int slen = strlen(s), tlen = strlen(t); /* �����ĳ��� */
//    int minstart = 0, minlen = INT_MAX;    /* ��Сƥ�䴮����볤�� */
//
//    for (int i = 0; t[i]; i++) {
//        hash[t[i]]++;   /* ��ͳ�ƴ�t�и�Ԫ�صĹ�ϣֵ */
//    }
//
//    while (end < slen) { /* ��ָ��Ӵ�sͷ�ƶ�����sβ */
//        if (hash[s[end]]-- > 0) {   /* ��s�е�ǰԪ���ڴ�t�г��ֹ� */  // �����ص㣬����ƥ������1��ÿ��if�жϺ󣬲�����ٶ����Լ�
//            tlen--; /* tlen-- */
//        }
//        //hash[s[end]]--; /* ��s�е�ǰԪ�صĹ�ϣֵ��1 */
//        end++;  /* ��ָ�������ƶ� */
//
//        while (tlen == 0) { /* ����ƥ����Ӵ� */
//            if (end - start < minlen) {    /* ������Сƥ�䴮�����ͳ��� */
//                minstart = start;
//                minlen = end - start;
//            }
//            /* ��s��ǰstart�Ĺ�ϣֵ��1��
//             * ������0�����ʾ��ָ��start�ƶ�����ִ�����������
//             * ��С�ڵ���0�����ʾ��ָ��start�ƶ�����ִ����ܷ�������
//             */
//            hash[s[start]]++;
//            if (hash[s[start]] > 0) {
//                tlen++;
//            }
//            start++;
//        }
//    }
//
//    if (minlen != INT_MAX) {   /* �ҵ�����Сƥ���ִ� */
//        char* t = (char*)malloc(sizeof(char)*(minlen+1));
//        *t = '\0';
//        strncat(t, s+minstart, minlen);
//        return t;
//    }
//
//    return ""; /* δ�ҵ���Сƥ���Ӵ�������""���� */
//}
