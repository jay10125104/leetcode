struct node{
    node* left;
    node* right;
};
class Trie {
public:
    node*root;
    Trie() {
        root = new node();
    }
    
    void insert(int x) {
        node*temp = root;
        int idx = 31;
        while(idx>=0){
            int mask = (1<<idx);
            if(x&mask){
                // cout<<idx<<" ";
                if(temp->right==NULL){
                    temp->right = new node();
                }
                temp = temp->right;
            }
            else{
                if(temp->left==NULL){
                    temp->left = new node();
                }
                temp = temp->left;
            }
            idx--;
        }
        
    }
    int query(int x){
        node*temp = root;
        int idx=31;
        int sol=0;
        while(idx>=0){
            int mask = (1<<idx);
            if((mask&x)){
                // cout<<"jo";
                if(temp->right==NULL){
                    temp = temp->left;
                }
                else{
                    sol|=mask;
                    temp=temp->right;
                }
            }
            else{
                if(temp->left==NULL){
                    sol|=mask;
                    temp = temp->right;
                }
                else{
                    temp=temp->left;
                }
            }
            idx--;
            
        }
        return sol;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *t = new Trie();
        // int mx=0;
        // t->insert(10);
        for(auto i:nums){
            t->insert(i);
        }
        int mx = 0;
        int res = t->query(INT_MAX);
        // cout<<res;
        for(auto i:nums){
            int mask = INT_MAX;
            int req = mask^i;
            int res = t->query(req);
            // cout<<res<<" ";
            mx = max(mx,res^i);
        }
        return mx;
    }
};