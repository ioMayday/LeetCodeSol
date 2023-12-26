// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


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

int main(void)
{
    struct ListNode head, p2, p3, p4, p5;
    head.val = 1;
    head.next = &p2;
    p2.val = 2;
    p2.next = &p3;
    p3.val = 3;
    p3.next = &p4;
    p4.val = 4;
    p4.next = &p5;
    p5.val = 5;
    p5.next = NULL;

    // ��ʼ���������ʾ
    struct ListNode *cur, *pre, *nxt;
    cur = &head;
    while (cur != NULL) {
        printf("%d ",cur->val);
        cur = cur->next;
    }
    printf("\n");


    // ��ת�������ʾ
//    struct ListNode* newHead = reverse(&head);
//    struct ListNode* newHead = reverseInterval(&p2, &p5);
    struct ListNode* newHead = reverseKGroup(&head, 2);

    cur = newHead;
    while (cur != NULL) {
        printf("%d ",cur->val);
        cur = cur->next;
    }
    printf("\n");

    return 0;
}
