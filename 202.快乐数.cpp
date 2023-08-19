/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include <iostream>

class Solution
{
public:
    // Detect Cycle using Floyd Cycle detection Algorithm (using 2 pointers: slow & fast pointer)
    // If we detect a cycle, then it is not a happy number; otherwise, it is
    int solve(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int r = n % 10;
            sum += r * r;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n, fast = n;
        do
        {
            slow = solve(slow);
            fast = solve(solve(fast));
            if (fast == 1)
                return true;
        } while (slow != fast);
        return false;
    }
};

int main()
{
    int num;
    std::cout << "Enter an integer to check if it is a happy number: ";
    std::cin >> num;

    Solution solution;
    bool isHappyNumber = solution.isHappy(num);

    if (isHappyNumber)
    {
        std::cout << num << " is a happy number!" << std::endl;
    }
    else
    {
        std::cout << num << " is not a happy number." << std::endl;
    }

    return 0;
}

// @lc code=end
