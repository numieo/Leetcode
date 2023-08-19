/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */
#include <iostream>

char tb[16] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

uint32_t reverseBits(uint32_t n)
{
    int curr = 0;
    uint32_t ret = 0;
    uint32_t msk = 0xF;
    for (int i = 0; i < 8; i++)
    {
        ret = ret << 4;
        curr = msk & n;
        ret |= tb[curr];
        n = n >> 4;
    }
    return ret;
}
// @lc code=end
int main()
{
    uint32_t num;
    std::cout << "Enter a 32-bit unsigned integer: ";
    std::cin >> num;

    uint32_t reversed = reverseBits(num);

    std::cout << "Original number: " << num << std::endl;
    std::cout << "Reversed number: " << reversed << std::endl;

    return 0;
}
