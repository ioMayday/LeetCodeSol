/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int countNodes(struct TreeNode* root){  // �ɼ�������������ڵ�����(������ȫ������������������)
    if (root == NULL) return 0;
    
    // ��������
    int hl = 1, hr = 1;
    struct TreeNode* l = root->left;
    struct TreeNode* r = root->right;
    while (l != NULL) { // �������߶�
        l = l->left;
        hl++;
    }
    while (r != NULL) { //�������߶�
        r = r->right;
        hr++;
    }
    if (hl == hr) {  // ��Ϊ��������
        return pow(2, hl) - 1; // ���������ڵ���㣺2^depth - 1
    }

    // ��ͨ������
    return 1 + countNodes(root->left) + countNodes(root->right);
}