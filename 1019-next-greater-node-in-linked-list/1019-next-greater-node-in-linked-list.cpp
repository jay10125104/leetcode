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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<ListNode*,int>>s;
        vector<int>ans;
        int count=0;
        ListNode*temp = head;
        while(temp){
            ans.push_back(0);
            int x=temp->val;
            while(s.size() && s.top().first->val<x){
                ans[s.top().second] = x;
                s.pop();
            }
            s.push({temp,count});
            count++;
            temp =temp->next;
        }
        return ans;
    }
};