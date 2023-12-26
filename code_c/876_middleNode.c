// ����ָ��Ӧ��
struct ListNode* middleNode(struct ListNode* head)
{
    if (head == NULL) return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) { // һ��Ҫ�������жϲ��ܽ�����λ
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;  // �ڵ�Ϊż��ʱ�������м俿�Ҳ�ֵ
}
