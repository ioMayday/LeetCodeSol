
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int g_curLevelCnt;

typedef struct QueNode { // BFS�ر������������ݽṹ
    int depth;
    struct TreeNode *node;
    struct QueNode *next;
} StruQueNode;

typedef struct LevelNode { // BFS�ر������������ݽṹ
    int depth;
    int cnt;
    struct LevelNode *next;
} StruLevelNode;

void InitQueList(StruQueNode **queList, struct TreeNode* node, int depth)
{
    *queList = (StruQueNode *)malloc(sizeof(StruQueNode));
    if (*queList == NULL) {
        return;
    }
    (*queList)->depth = depth;
    (*queList)->node = node;
    (*queList)->next = NULL;
    g_curLevelCnt++;
    return;
}

void InitLevelList(StruLevelNode **levelList, int depth, int cnt)
{
    *levelList = (StruLevelNode *)malloc(sizeof(StruLevelNode));
    if (*levelList == NULL) {
        return;
    }
    (*levelList)->depth = depth;
    (*levelList)->cnt = cnt;
    (*levelList)->next = NULL;
    return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (root == NULL) {
        *returnSize = 0; // ��֤[]������ʱ���������ֵ��Ϊ0���
        returnColumnSizes = NULL;
        return NULL;
    }

    StruQueNode *queList, *queListHead, *queLastNode;
    InitQueList(&queList, root, 1);
    queLastNode = queList;
    queListHead = queList;
    StruLevelNode *levelList, *levelListHead, *levelLastNode;
    InitLevelList(&levelList, 1, 1);
    levelLastNode = levelList;
    levelListHead = levelList;

    // BFS
    int depth = 1;
    struct TreeNode* node;
    while (queList != NULL) {
        // ��ǰ�����
        g_curLevelCnt = 0;
        while (queList != NULL && depth == queList->depth) {
            node = queList->node;
            if (node->left != NULL) {
                InitQueList(&queLastNode->next, node->left, depth + 1);
                queLastNode = queLastNode->next; // ��¼����Addβ���ڵ�
            }
            
            if (node->right != NULL) {
                InitQueList(&queLastNode->next, node->right, depth + 1);
                queLastNode = queLastNode->next;
            }

            queList = queList->next; // ��ǰ����һ���ڵ�
        }
        if (queList != NULL) {
            depth++; // ����������һ�㣬����queList==NULL�����һ�������û����һ�㣬�����ټ�һ
        }

        // ��¼��ǰ��ڵ���
        InitLevelList(&levelList->next, depth, g_curLevelCnt);
        levelList = levelList->next;
    }
    *returnSize = depth;
    // printf("%d\n", depth);

    // �����Ӧ��С�Ķ�ά���鲢����ռ�
    *returnColumnSizes = (int *)malloc(depth * sizeof(int));
    if (*returnColumnSizes == NULL) {
        return NULL;
    }
    int **resArr = (int **)malloc(depth * sizeof(int*));
    if (resArr == NULL) {
        return NULL;
    }

    // �����������ֵpush�������б���
    int *p;
    int i;
    queList = queListHead;
    levelList = levelListHead;
    depth = 1;
    while (queList != NULL) {
        (*returnColumnSizes)[depth - 1] = levelList->cnt;
        p = (int*)malloc(levelList->cnt * sizeof(int));
        if (p == NULL) {
            return NULL;
        }
        resArr[depth - 1] = p;

        // ��ǰ�����
        for (i = 0; i < levelList->cnt; i++) {
            node = queList->node;
            resArr[depth - 1][i] = node->val;
            queList = queList->next; // ��ǰ����һ���ڵ�
        }
        depth++; // ������һ��
        levelList = levelList->next;
    }

    return resArr;
}