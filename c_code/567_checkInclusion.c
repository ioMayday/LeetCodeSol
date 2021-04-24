// 
// "abcdxabcde"
// "abcdeabcdx" 
// output: true
#define MAX_LEN 128 // 26��Сд��ĸ
bool checkInclusion(char * s1, char * s2) 
{
    int hash[MAX_LEN] = {0}; // ����ֻΪСд��ĸ
    int lenS2 = strlen(s2);
    int i;
    for (i = 0; s1[i]; i++) {
        hash[s1[i] - 'a']++;
    }
    int lenS1 = i;

    int left = 0;
    int right = 0;

    int notFitNum = lenS1;
    // O(n)������rightŲ����ĩβ����
    while (right < lenS2) { // ����������ҿ�
        // ���ҷ���������������right
        if (hash[s2[right] - 'a'] > 0) {
            notFitNum--;
        }
        hash[s2[right] - 'a']--;  // ��ָ�뾭��ʱ������ƥ��ļ�����������ƥ��ļ���0
        right++;

        // �������Ž⣬����left
        if (notFitNum == 0) { // ��ǰ��Χ��������
            // �ص��ص�
            while (hash[s2[left] - 'a'] < 0) { //�ƶ�ָ�뵽��һ��������ַ�
                hash[s2[left] - 'a']++;
                left++;
            }
            // ��ʼ�ж�������
            // while (hash[s2[left] - 'a'] == 0 && left < right) { // ��ҪԽ��
            while (left < right && hash[s2[left] - 'a'] == 0) { // �����±����з�Χ������
                hash[s2[left] - 'a']++;
                left++;
                notFitNum++;
            }
            if (notFitNum == lenS1) {
                return true;
            }
            left = right;
        }

    }
    return false;
}