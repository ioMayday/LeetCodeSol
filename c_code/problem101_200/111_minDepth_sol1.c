/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// DFS�����ȱ������е��ӽڵ㣬��ȡ��Сֵ
int g_minDepth;
void dfsFindMin(struct TreeNode* root, int depth)
{
    if (root->left == NULL && root->right == NULL) {
        g_minDepth = depth < g_minDepth ? depth : g_minDepth;
        return;
    }

    if (root->left != NULL) {
        dfsFindMin(root->left, depth + 1); // ����ֻ��һ����֧ʱԽ�����
    }

    if (root->right != NULL) {
        dfsFindMin(root->right, depth + 1);
    }

    return;
}

int minDepth(struct TreeNode* root)
{
    g_minDepth = INT_MAX;
    if (root == NULL) {
        return 0;
    }
    int depth = 1; // ���Ѿ���һ��
    dfsFindMin(root, depth);
    return g_minDepth;
}