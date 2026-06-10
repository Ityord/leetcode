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
        auto lambda = [](ListNode* a, ListNode*b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(lambda)> pq(lambda);
        for (auto node : lists){
            if (node != NULL){
                pq.push(node);
            }
        }

        if (pq.empty()){
            return NULL;
        }
        ListNode* ans = pq.top();
        ListNode* tail = ans;
        pq.pop();
        if (ans->next != NULL){
            pq.push(ans->next);
        }
        while (!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            tail->next = curr;
            tail = tail->next;
            if (curr->next != NULL){
                pq.push(curr->next);
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna