/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// �ݹ�д��
void flatten(struct TreeNode* root)
{
    if (root == NULL) return;

    // �ȵõ�����flatten�����������
    flatten(root->left);
    flatten(root->right);

    // ���½�����������
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;

    // ����������
    root->left = NULL;
    root->right = left;

    // �ҵ�ԭ������flatteng��ĩβ�ڵ�
    struct TreeNode* p = root;  //ֱ�Ӵ�root��ʼ��ֵ,��root->right��ֵҪ��,ʡȥһ��NULL�ж�
    while (p->right != NULL) { 
        p = p->right;
    }
    // ����ԭ������
    p->right = right; 

    return;
}