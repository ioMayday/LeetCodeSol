/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Good Job����⵽λ��һ��д�ԣ�����
// ����ǰ������򣬹���һ��������
struct TreeNode* build(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd)
{
    // base case
    if (inStart > inEnd) return NULL; // Ҷ�ӽڵ�

    // root operation
    struct TreeNode* root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    // ǰ��������
    root->val = preorder[preStart];
    // ����������ֽ�
    int i, idx = -1;
    for (i = inStart; i <= inEnd; i++) {
        if(inorder[i] == root->val) {
            idx = i;
            break;
        }
    }

    // �ݹ�������������
    int leftSize = idx - inStart;
    root->left = build(preorder, preStart + 1, preStart + leftSize,
                      inorder, inStart, idx - 1);
    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                      inorder, idx + 1, inEnd);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorder == NULL || inorder == NULL) return NULL;

    return build(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}