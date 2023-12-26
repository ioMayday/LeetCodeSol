// ����˼·������������׳����ر��ǽ�λҪ����
char *multiply(char *num1, char *num2)
{
    if (num1 == NULL || num2 == NULL) { return NULL; }

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int* resNum = (int*)malloc((len1 + len2) * sizeof(int));
    if (resNum == NULL) { return NULL; }
    memset(resNum, 0, (len1 + len2) * sizeof(int));

    int i;
    int j;
    for (i = len1 - 1; i >= 0; i--) {
        int tmpNum = (int)(num1[i] - '0');
        for (j = len2 - 1; j >= 0; j--) {
            int res = tmpNum * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;

            // ���ӵ�res
            int sum = res + resNum[p2];
            resNum[p1] += sum / 10; // ע���λ��+=
            resNum[p2] = sum % 10;  // sum������p2λ�õ�ֵ
        }
    }

    // ���ת�����ַ���
    i = 0;
    while (i < len1 + len2 && resNum[i] == 0) {
        i++;
    }
    if (i == len1 + len2) { return "0"; } // ��� ��0�� ��0�������ȫ��

    // ת�����ַ���
    char *resChar = (char*)malloc((len1 + len2 - i + 1) * sizeof(char)); // +1�Ǹ�ĩβ������\0
    if (resChar == NULL) { return NULL; }
    j = 0;
    for (; i < len1 + len2; i++) {
        printf("resNum[%d] %d\n", i, resNum[i]);
        resChar[j++] = resNum[i] + '0';
    }
    resChar[j] = '\0';

    free(resNum);
    return resChar;
}