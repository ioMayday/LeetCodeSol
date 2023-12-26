/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// ǰ���������д��
// �������������ĵ���������ֻ��Ҫ������ӡ�������λ�ü���
#define MAX_NODE_NUM 101

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int i = 0;
    int top = 0; // top��¼��ջ��Ԫ�ظ���
    int *resArr = (int*)malloc(MAX_NODE_NUM * sizeof(int));
    struct TreeNode** stkNodeArr = (struct TreeNode**)malloc(MAX_NODE_NUM * sizeof(struct TreeNode*));

    while (root != NULL || top > 0) { // ��������Ϊ��ĩβ�ڵ�ײ����ұ����ڵ�ջ�ж��ѳ�ջ
        while (root != NULL) { // �ȸ��ڵ��������
            stkNodeArr[top++] = root; // ��ջ��¼���̽ڵ�
            resArr[i++] = root->val; // ��ջʱ�������¼���൱��ǰ�����
            root = root->left;
        } // �������Ҷ�ڵ��NULL

        // ȡ��ջ���ڵ㣬Ҳ��Ҷ�ڵ�
        root = stkNodeArr[--top];
        // Ҷ�ڵ��Ҳ�����
        root = root->right;
    }

    *returnSize = i;
    free(stkNodeArr);

    return resArr;
}