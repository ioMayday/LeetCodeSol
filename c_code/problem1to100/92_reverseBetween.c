struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if (head == NULL) return NULL;  // left/rightֵ��Ŀ�����޶���Ĭ������ȷ��

    // ���left=1,ֱ�������
    if (left == 1) {
        return reverseN(head, right);  // left����1ʱ��right��С����n����
    }
    // �����ƶ�����Ӧ���
    head->next = reverseBetween(head->next, left - 1, right - 1); // ���ط�תƬ���µĵص�
    return head;
}
