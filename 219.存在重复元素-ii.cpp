/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (mp.count(nums[i]))
            {
                if (abs(i - mp[nums[i]]) <= k)
                    return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 0, 1, 1};
    int k = 2;
    cout << solution.containsNearbyDuplicate(nums, k) << endl;

    return 0;
}

// @lc code=end
