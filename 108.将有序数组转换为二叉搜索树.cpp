/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    TreeNode *sortedArrayToBST(vector<int> &nums, int start, int end)
    {
        if (end <= start)
            return NULL;
        int midIdx = (end + start) / 2;
        TreeNode *root = new TreeNode(nums[midIdx]);
        root->left = sortedArrayToBST(nums, start, midIdx);
        root->right = sortedArrayToBST(nums, midIdx + 1, end);
        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST(nums, 0, nums.size());
    }
};

// @lc code=end

int main()
{
    Solution solution;

    // 创建一个有序数组
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    // 将有序数组转换为二叉搜索树
    TreeNode *root = solution.sortedArrayToBST(nums);
}
