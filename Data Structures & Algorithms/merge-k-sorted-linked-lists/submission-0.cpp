/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;

        while(true) {
            int smallNode = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (!lists[i]) { continue; }

                if (smallNode == -1 or lists[smallNode]->val > lists[i]->val) {
                    smallNode = i;
                }
            }
            if (smallNode == -1) { break; }
            
            cur->next = lists[smallNode];
            lists[smallNode] = lists[smallNode]->next;
            cur = cur->next;
        }

        return res->next;
    }
};





