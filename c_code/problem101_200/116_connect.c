/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

// �ο�: ���ⲻ�죬��Ҫ����
// https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/shou-ba-shou-shua-er-cha-shu-xun-lian-di-gui-si-wei/er-cha-shu-xi-lie-1

void connectTwoNodes(struct Node* node1, struct Node* node2) 
{
    if (node1 == NULL || node2 == NULL) return;

    // �������������ڵ�
    node1->next = node2;

    // ����ͬһ���ڵ��������ڵ�
    connectTwoNodes(node1->left, node1->right);
    connectTwoNodes(node2->left, node2->right);
    // ���Ӳ�ͬ���ڵ����������ڽڵ�
    connectTwoNodes(node1->right, node2->left);
}

struct Node* connect(struct Node* root) {
	if (root == NULL) return root;

    connectTwoNodes(root->left, root->right);

    return root;
}