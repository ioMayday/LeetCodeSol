// �ο����ģ�
// https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/shou-ba-shou-shua-lian-biao-ti-mu-xun-lian-di-gui-si-wei/di-gui-fan-zhuan-lian-biao-de-yi-bu-fen

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// ��ʵ����������ת leetcode��206
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL) return NULL; // ע�⣬Ҫ����head�Ƿ�Ϊ��
    if (head->next == NULL) return head;

    struct ListNode* last = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
}

// ��ʵ��ǰn��Ԫ�ط�ת
struct ListNode* succesor = NULL;
struct ListNode* reverseN(struct ListNode* head, int n)
{
    if (n == 1) {
        succesor = head->next;
        return head;
    }

    struct ListNode* last = reverseN(head->next, n - 1); //ֻ����չ��һ������Ҫѹջ��ջ
    head->next->next = head;
    head->next = succesor;
    return last;
}

// ��ʵ�ִӵ�m��n�������������ķ�ת
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



//����������
int main()
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
//    struct ListNode* newHead = reverseN(&head, 3);
    struct ListNode* newHead = reverseBetween(&head, 2, 5);
    cur = newHead;
    while (cur != NULL) {
        printf("%d ",cur->val);
        cur = cur->next;
    }
    printf("\n");
	
	return 0;

}