/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// ��������ṹ�� BFS�汾
typedef struct QueNode {
    int depth;
    struct TreeNode *node;
    struct QueNode *next;
} QueNodeStru, *pQueNodeStru;

void init(QueNodeStru **handle, int depth, struct TreeNode *node)
{
    (*handle) = (pQueNodeStru)malloc(sizeof(QueNodeStru));
    (*handle)->depth = depth;
    (*handle)->node = node;
    (*handle)->next = NULL;
    return;
}

// BFS�����ѽڵ�һ��һ�������������ṹ������
int minDepth(struct TreeNode* root)
{
    if (root == NULL) {
        return 0;
    }
    // ���нڵ��ʼ��
    pQueNodeStru queList, queLevelStart;
    init(&queList, 1, root); // root ���Ϊ1
    queLevelStart = queList;

    // һ�߲��������һ����ӣ�ͬʱ�����Ƿ񵽴�Ҷ�ڵ�õ���С���
    while (queList != NULL) {
        struct TreeNode *node = queList->node;
        if (node->left == NULL && node->right == NULL) {
            return queList->depth;
        }

        if (node->left != NULL) {
            init(&queLevelStart->next, queList->depth + 1, node->left);
            queLevelStart = queLevelStart->next; // �����¼ÿһ������
        }
        if (node->right != NULL) {
            init(&queLevelStart->next, queList->depth + 1, node->right);
            queLevelStart = queLevelStart->next;
        }
        queList = queList->next; // �����¼���е��������
    }

    return -1; // false
}