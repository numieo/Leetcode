/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start

// Definition for singly-linked list.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;

        // This is for the case when a linked list is like this: 
        // 1->1->2->null , val = 1
        // 1->1->1->null , val = 1
        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;
                // After doing the above step, I am not updating "curr" because of these types of test cases:
                // 1->2->3->6->6->6->5->null  val = 6
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};

void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "null" << std::endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 6 -> 3 -> 6 -> 6 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(5);

    int valToRemove = 6;

    Solution solution;
    ListNode* modifiedHead = solution.removeElements(head, valToRemove);

    std::cout << "Modified Linked List: ";
    printLinkedList(modifiedHead);

    // Free memory (optional, but good practice)
    ListNode* curr = modifiedHead;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}

// @lc code=end

