/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5};    // No duplicates
    vector<int> nums2 = {1, 2, 2, 3, 4, 5}; // Contains duplicates
    vector<int> nums3 = {1, 2, 3, 3, 4, 5}; // Contains duplicates

    Solution solution;

    cout << "nums1 contains duplicates? " << (solution.containsDuplicate(nums1) ? "Yes" : "No") << endl;
    cout << "nums2 contains duplicates? " << (solution.containsDuplicate(nums2) ? "Yes" : "No") << endl;
    cout << "nums3 contains duplicates? " << (solution.containsDuplicate(nums3) ? "Yes" : "No") << endl;

    return 0;
}

// @lc code=end
