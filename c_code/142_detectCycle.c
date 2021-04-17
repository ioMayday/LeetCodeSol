/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// ����ָ��
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL) return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) { // �޻�ʱ��ĩβNULL�ڵ��˳�
        fast = fast->next->next;   // ����2
        slow = slow->next;         // ����1
        if (slow == fast) break;   // �л�����
    }
    if (fast == NULL || fast->next == NULL) {
        return NULL; // �޻�
    } 
    // �л�
    fast = head;
    while (slow != fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow; // ���صڶ��������Ľڵ�
}