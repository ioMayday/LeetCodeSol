/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 // ������ [left, right]
struct TreeNode* buildMaxTree(int* nums, int left, int right) 
{
    // base case
    if (left > right) return NULL;

    struct TreeNode* root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    // �ҵ����ֵ����ǰ�ĸ��ڵ�
	// debug code
    // int i, idx, maxVal = nums[left];
    // for (i = left + 1; i <= right; i++) { // �ᱨ�ڴ�Խ�磬���鿴bug;  =>��ͬ����ʼ��idx=left
	// right code
	// int i, idx = left, maxVal = nums[left]; // ��ͬ����ʼ��idx=left
    // for (i = left + 1; i <= right; i++) {   // ����ᱨ�ڴ�Խ�� 

    int i, idx, maxVal = INT_MIN;
    for (i = left; i <= right; i++) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
            idx = i;
        }
    }
    root->val = maxVal;

    // �ݹ����������������
    root->left = buildMaxTree(nums, left, idx - 1);
    root->right = buildMaxTree(nums, idx + 1, right);

    return root;
}


struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    if (nums == NULL) return NULL;

    return buildMaxTree(nums, 0, numsSize - 1);

}