#include <numeric>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr) 
            return head;
    
        ListNode* current = head;
    
        while (current->next != nullptr) {
            int gcd = std::gcd(current->val, current->next->val);
            
            ListNode* newNode = new ListNode(gcd);
            
            newNode->next = current->next;
            current->next = newNode;
            
            current = newNode->next;
        }

        return head;
    }
};