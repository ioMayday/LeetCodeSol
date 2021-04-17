/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// ����ָ��
bool hasCycle(struct ListNode *head) {
    if (head == NULL) return false;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) { // �޻�ʱ��ĩβNULL�ڵ��˳�
        fast = fast->next->next;   // ����2
        slow = slow->next;         // ����1
        if (slow == fast) return true; // �л�
    }
    return false;
}