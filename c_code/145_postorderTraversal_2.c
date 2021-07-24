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
 ����д��
 */

#define MAX_NODE_NUM 101

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int i = 0;
    int top = 0; // top��¼��ջ��Ԫ�ظ���
    int *resArr = (int*)malloc(MAX_NODE_NUM * sizeof(int));
    struct TreeNode** stkNodeArr = (struct TreeNode**)malloc(MAX_NODE_NUM * sizeof(struct TreeNode*));
    struct TreeNode* pre = NULL;

    while (root != NULL || top > 0) { // ��������Ϊ��ĩβ�ڵ�ײ����ұ����ڵ�ջ�ж��ѳ�ջ
        while (root != NULL) { // �ȸ��ڵ��������
            stkNodeArr[top++] = root; // ��ջ��¼���̽ڵ�
            root = root->left;
        } // �������Ҷ�ڵ��NULL

        // ȡջ���ڵ㣬Ҳ��Ҷ�ڵ�
        root = stkNodeArr[--top];
        printf("%d ", root->val);
        // right ΪNULLʱ��˵���������Ѿ�������
        // right Ϊpreʱ��˵�����򵽸��ڵ㴦�����������������������ڵ�
        if (root->right == NULL || root->right == pre) { // �������  
            resArr[i++] = root->val;
            pre = root; // �����������������root��1ʱ����һ������ı�Ȼ�ǵ�ǰ�����ҽڵ�
            root = NULL;
        } else { // root->right != NULL && root->right != pre
            // ���������ȡҶ�ڵ��Ҳ�����,��ѹջ
            stkNodeArr[top++] = root; // ���������������ְ�rootѹջ��ȥ
            root = root->right;
        }
    }

    *returnSize = i;
    free(stkNodeArr);

    return resArr;  
}