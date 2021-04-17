int SplitStr(char *version, const char *split, int *verNum, int len)
{
    char *p = strtok(version, split);
    while (p) {
        verNum[len++] = atoi(p);
        p = strtok(NULL, split);
    }
    return len;
}

int compareVersion(char * version1, char * version2)
{
    // �и�ver1��ver2���ŵ����飬����¼����
    int ver1[500] = {0};
    int ver2[500] = {0};
    int lenVer1 = 0, lenVer2 = 0;
    char *p;
    const *split = ".";
    lenVer1 = SplitStr(version1, split, ver1, lenVer1);
    lenVer2 = SplitStr(version2, split, ver2, lenVer2);
    
    // �Ƚ�����
    int minLen = lenVer1 < lenVer2 ? lenVer1 : lenVer2;
    int i;
    for (i = 0; i < minLen; i++) {
        if (ver1[i] > ver2[i]) {
            return 1;
        } else if (ver1[i] < ver2[i]) {
            return -1;
        }
    }
    // �����������
    // "1.0"
    // "1.0.0"
    // �жϳ��汾�ţ������Ƿ�Ϊ0
    if (minLen == lenVer1) { // ������lenVer2
        for (i = lenVer1; i < lenVer2; i++) {
            if (ver2[i] != 0) {
                break;
            }
        }
        if (i == lenVer2) { // ���汾�ź���ȫΪ0
            return 0;
        }
    } else {
        for (i = lenVer2; i < lenVer1; i++) {
            if (ver1[i] != 0) {
                break;
            }
        }
        if (i == lenVer1) { // ���汾�ź���ȫΪ0
            return 0;
        }
    }

    // ��С���������˳���ǰ��break
    // ��ÿ���Ŷ���ͬ�ҳ��汾�ź�����ȫΪ0
    // �Ƚ϶���
    if (lenVer1 > lenVer2) {
        return 1;
    } else if (lenVer1 < lenVer2) {
        return -1;
    }
    // lenVer1 == lenVer2)
    return 0;  // �������
}