/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
˼·��
������������һ����Ҫ�������ǣ���������Ľ����һ����С�����������
�ۼ����������������ǴӴ�С����������

ת���ķ�ʽ��
��Ȼ���������
ֻ���ȱ���������
�Ӷ��ȵõ���Сֵ
Ȼ��������λ�ô����ϵݹ��ۼ�ǰһ������������
*/

struct TreeNode* preNode;
void inorderTraverse(struct TreeNode* root)
{
    // ��ֹ����
    if (root == NULL) { // ��Ҷ�ڵ���ӽڵ�����Ҳ�Ҷ�ڵ�ʱֱ�ӷ���
        return;
    }

    inorderTraverse(root->right);

    // ����ǰ�ڵ㣬��ǰһ���ڵ��ֵ���
    if (preNode != NULL) { // ����NULLʱ������ʾ���Ҳ�Ҷ�ڵ㣬��ǰ�̽ڵ㣬�򲻲���val
        root->val += preNode->val;
    }
    preNode = root; // ��¼�������ʱ����ǰ�ڵ��ǰһ���ڵ�

    inorderTraverse(root->left);

    return;
}

struct TreeNode* convertBST(struct TreeNode* root)
{
    preNode = NULL;
    inorderTraverse(root);
    return root;
}