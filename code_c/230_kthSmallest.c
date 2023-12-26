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
���Լ�¼��k����СԪ�صķ�ʽ���ǣ�
���������Ȼ��ȫ�ֱ�����¼���������������kֵ��ͬ��ʱ���˳����������ض�Ӧ��ֵ
*/

int g_cnt;
int g_val;
void inorderTraverse(struct TreeNode* root, int k)
{
    // ��ֹ����
    if (root == NULL) {
        return;
    }

    inorderTraverse(root->left, k);

    // ���������
    g_cnt++; // ��¼�����������
    if (g_cnt == k) {
        g_val = root->val;
        return; // ֮���ٱ���
    }

    inorderTraverse(root->right, k);
}

int kthSmallest(struct TreeNode* root, int k)
{
    g_cnt = 0;
    g_val = -1;
    inorderTraverse(root, k);
    return g_val;
}