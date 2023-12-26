void reverseString(char* s, int sSize){
    if (s == NULL) { return; }

    // ��������ָ�룬�б����м俿���໥����
    char tmp;
    int left = 0;
    int right = sSize - 1;
    while (left < right) {
        tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
    return;
}