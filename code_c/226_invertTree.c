/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// ǰ�����
struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) return NULL;

    // �Ƚ���
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    // �ٵݹ齻��
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// ��������
// struct TreeNode* invertTree(struct TreeNode* root) {
//     if (root == NULL) return NULL;

//     invertTree(root->left);
//     invertTree(root->right);

//     struct TreeNode* tmp = root->left;
//     root->left = root->right;
//     root->right = tmp;
//     return root;
// }

// // Test�����������Ч��
// // ԭ�򣺽��൱��ֻ�����˸��ڵ�����һ��ڵ㣬����һ��ʱ�����ν��������²��൱��û��
// struct TreeNode* invertTree(struct TreeNode* root) {
//     if (root == NULL) return NULL;

//     invertTree(root->left);
//     struct TreeNode* tmp = root->left;
//     root->left = root->right;
//     root->right = tmp;  // right�����ԭleftָ��
//     invertTree(root->right); // ���ʻ���root->left����һ�㱻����
//     return root;
// }