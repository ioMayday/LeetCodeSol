// �ȵ�����ʵ��һ����������
struct ListNode* reverse(struct ListNode* head)
{
    if (head == NULL) return NULL;

    struct ListNode *pre, *cur, *nxt;
    pre = NULL;
    cur = head;
    while (cur != NULL) {
        nxt = cur->next;
        // ��תһ���ڵ�
        cur->next = pre;
        pre = cur; // ָ����λ
        cur = nxt;
    }

    return pre;
}

// ������ʵ��������������� [a, b)
struct ListNode* reverseInterval(struct ListNode* a, struct ListNode* b)
{
    if (a == NULL) return NULL;

    struct ListNode *pre, *cur, *nxt;
    pre = NULL;
    cur = a;
    while (cur != b) {
        nxt = cur->next;
        // ��תһ���ڵ�
        cur->next = pre;
        pre = cur; // ָ����λ
        cur = nxt;
    }

    return pre;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if (head == NULL) return NULL;

    // ���ƶ�k��ָ��
    int i;
    struct ListNode *a, *b;
    a = b = head;
    for (i = 0; i < k; i++) {
        if (b == NULL) return head; // base case������k����ֱ�ӷ���head��������
        b = b->next;
    }

    // ����ǰk��
    struct ListNode* newHead = reverseInterval(a, b); // ע����������ҿ���[a, b)

    // �ݹ����KGroup��������
    head = reverseKGroup(b, k); // ��b��ʼ����Ϊ������ݹ����

    // ��������������
    a->next = head;

    return newHead;
}