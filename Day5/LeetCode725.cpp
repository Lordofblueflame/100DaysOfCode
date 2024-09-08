#include <vector>

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

    int listSize(ListNode* node) {
        int size = 0;
        while(node != nullptr) {
            size++;
            node = node->next;
        }
        return size;
    }

    std::vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = listSize(head);
        
        int partSize = size / k;
        int remainder = size % k;

        std::vector<ListNode*> retVec(k, nullptr);

        ListNode* current = head;
        for (int i = 0; i < k && current != nullptr; ++i) {
            ListNode* partHead = current;
            int currentPartSize = partSize + (remainder > 0 ? 1 : 0);  

            for (int j = 1; j < currentPartSize; ++j) {
                if (current != nullptr) {
                    current = current->next;
                }
            }
            
            if (current != nullptr) {
                ListNode* nextPartHead = current->next;
                current->next = nullptr;
                current = nextPartHead;
            }
            
            retVec[i] = partHead;
            remainder--; 
        }

        return retVec;
    }
};