bool cmp(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
    return a.first<b.first;
}
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
    vector<int> maximizeXor(vector<int>& v, vector<vector<int>>& q) {
        vector<pair<int,pair<int,int>>>vi;
        for(int i=0;i<q.size();i++){
            vi.push_back({q[i][1],{q[i][0],i}});
        }
        sort(v.begin(),v.end());
        sort(vi.begin(),vi.end(),cmp);
        int idx=0;
        vector<int>sol(q.size());
        Trie *t = new Trie();
        int flag=0;
        for(int i=0;i<vi.size();i++){
            while(idx<v.size() && v[idx]<=vi[i].first){
                t->insert(v[idx]);
                flag=1;
                idx++;
            }
            if(flag==0){
                sol[vi[i].second.second] = -1;
               
            }
            else{
            int ans=0;
            int x = vi[i].second.first;
            int mask = INT_MAX;
            int req = x^mask;
            sol[vi[i].second.second] = (t->query(req)^x);
            }
        }
        return sol;
    }
};