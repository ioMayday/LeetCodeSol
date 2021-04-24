typedef struct PaliInfo {
    int maxLen;
    int start;
    int end;
} PaliInfoStru, *HandlePaliInfoStru;

// �Ե�ǰλ��Ϊ���ģ���ȡ�������ַ��������Ƚϸ���
void GetPalindrome(char *s, int len, int l, int r, HandlePaliInfoStru paliInfoMax)
{
    while (l >= 0 && r < len && s[l] == s[r]) {
        l--;
        r++;
    }
    int start = l + 1;
    int end = r - 1;
    int paliLen = end - start + 1;

    // update
    if (paliInfoMax->maxLen < paliLen) {
        paliInfoMax->maxLen = paliLen;
        paliInfoMax->start = start;
        paliInfoMax->end = end;
    }

    return;
}

char* longestPalindrome(char *s)
{
    if (s == NULL) { return NULL; }

    int len = strlen(s);
    PaliInfoStru paliInfoMax = {INT_MIN, -1, -1};
    int i;
    for (i = 0; i < len; i++) {
        GetPalindrome(s, len, i, i, &paliInfoMax);        // ��������
        GetPalindrome(s, len, i, i + 1, &paliInfoMax);    // ż������
    }

    // ����������Ӵ�
    char *outStr = (char *)malloc(paliInfoMax.maxLen + 1); // ��һ����/0
    if (outStr == NULL) { return NULL; }
    strncpy(outStr, s + paliInfoMax.start, paliInfoMax.maxLen);
    outStr[paliInfoMax.maxLen] = '\0';

    return outStr;
}