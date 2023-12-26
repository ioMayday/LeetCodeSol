/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
// Good Job����⵽λ��һ��д�ԣ�����
// ���ݺ�������򣬹���һ��������
// ���ϸ�105������ϣ���д�±꣬8min�㶨

struct TreeNode* build(int* inorder, int inStart, int inEnd, int* postorder, int postStart, int postEnd)
{
    // base case
    if (inStart > inEnd) return NULL; // Ҷ�ӽڵ�

    // root operation
    struct TreeNode* root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    // ����������
    root->val = postorder[postEnd];
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
    root->left = build(inorder, inStart, idx - 1,
                      postorder, postStart, postStart + leftSize - 1);
    root->right = build(inorder, idx + 1, inEnd,
                      postorder, postStart + leftSize, postEnd - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if (postorder == NULL || inorder == NULL) return NULL;

    return build(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}