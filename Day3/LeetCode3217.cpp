//  3217. Delete Nodes From Linked List Present in Array
//  Definition for singly-linked list.
#include <unordered_set>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        std::unordered_set<int> unique_nums =  std::unordered_set(nums.begin(),nums.end());

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr != nullptr) {
            if(unique_nums.find(curr->val) != unique_nums.end()) { 
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } 
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};