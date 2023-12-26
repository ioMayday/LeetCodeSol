/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// ����˫ָ�������߽��������죬��Ҫ����ϰ
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if (head == NULL) return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    int i;
    for (i = 0; i < n; i++) { // ��Ŀ���뱣֤��nС�ڵ��ڽڵ���
        fast = fast->next;
    }
    if (fast == NULL) return head->next; // ��ʾ�պ�ɾ��˳����һ��ͷ���

    while (fast->next != NULL) { // ����ʱ��slow->nextΪ������n�ڵ�
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next; // ȡ��������n+1���ڵ�ָ��n���ڵ㣬ת��ָ����n-1���ڵ�

    return head;
}