int lengthOfLongestSubstring(char * s){
    int len_s = strlen(s);
    if (len_s == 0 || len_s == 1) {
        return len_s;
    }

    int curIdx = 0;
    int maxLen = 1;
    int i,j;
    for (i = 1; i < len_s; i++) { //��ǰ���������Ӵ�
        for (j = i- 1; j >= curIdx; --j) { //ÿ����һ��s[i]�����Ե�ǰ�Ӵ������ж��Ƿ���ֹ����ַ�
            if (s[i] == s[j]) { //�ж��³��ֵ�s[i]�Ƿ��ǰ���һ��
                curIdx = j + 1; //���Ӵ�ֻ��������
                break; //�����ڲ�forѭ��
            } 
            
            if (maxLen < i - j + 1) {
                maxLen = i - j + 1; //��ǰ���Ӵ����ȸ���
            }
        }
    }
    return maxLen;
}