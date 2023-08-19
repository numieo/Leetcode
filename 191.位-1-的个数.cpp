/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
    
        while (n) {
            n &= (n - 1);
            count++;
        }
    
        return count;
    }
};

int main() {
    uint32_t num;
    std::cout << "Enter a 32-bit unsigned integer: ";
    std::cin >> num;

    Solution solution;
    int numBits = solution.hammingWeight(num);

    std::cout << "Number of 1 bits (Hamming weight): " << numBits << std::endl;

    return 0;
}

// @lc code=end

