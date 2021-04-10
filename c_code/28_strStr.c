// 2020��9��14�� 08:01:59

//����1
int strStr(char * haystack, char * needle){
    if (!*needle) return 0;
    int lens_hay = strlen(haystack);
    int lens_ned = strlen(needle);
    if (lens_hay == 0 || lens_hay < lens_ned) {
        return -1;
    }

    int idx = -1;
    char *p1;
    char *p2;
    char *p1_advance = &haystack[lens_ned - 1]; //�Ӵ�����
    for (p1 = haystack; *p1_advance; p1_advance++) {
        char *p1_old = p1;
        p2 = needle;
        while (*p1 == *p2 && *p2) { //��ǰfor��p1��ʼλƥ��
            p1++;
            p2++;
        }
        if (!*p2) { //whileѭ��ƥ����ɣ���*p2Ϊ0�����˳�
            idx = p1_old - haystack;
            return idx;
        }
        p1 = p1_old + 1; //Ŀ���ִ�����һλ
    }

    return idx;
}

// ����2
int strStr(char * haystack, char * needle){
    if (!*needle) return 0;
    
    char *p1;
    char *p2;
    char *p1_advance;
    int idx = -1;
    for (p1_advance = haystack, p2 = &needle[1]; *p2; p2++) { //��һ���Ѿ��жϹ�needle[0]�ǿ�
        p1_advance++;
        if (!*p1_advance) {
            return idx; //needle���ȱ�haystack������ƥ��
        }
    } //p1_advance�ĵ�ַͣ����needleĩβ�ĳ���

    for (p1 = haystack; *p1_advance; p1_advance++) {
        char *p1_old = p1;
        p2 = needle;
        while (*p1 == *p2 && *p2) {
            p1++;
            p2++;
        }
        if (!*p2) {
            idx = p1_old - haystack;
            return idx;
        }
        p1 = p1_old + 1;
    }

    return idx; //��������ƥ��
}


//�ο�����
char *strstr(const char *haystack, const char *needle) {
// if needle is empty return the full string
if (!*needle) return (char*) haystack;
const char *p1;
const char *p2;
const char *p1_advance = haystack;
for (p2 = &needle[1]; *p2; ++p2) {
p1_advance++; // advance p1_advance M-1 times
}
for (p1 = haystack; *p1_advance; p1_advance++) {
char *p1_old = (char*) p1;
p2 = needle;
while (*p1 && *p2 && *p1 == *p2) {
p1++;
p2++;
}
if (!*p2) return p1_old;
p1 = p1_old + 1;
}
return NULL;
}