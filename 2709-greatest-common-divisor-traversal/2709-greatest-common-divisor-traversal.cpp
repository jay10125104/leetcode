class Solution {
public:
struct unionfind{
    int n;
    vector<int>rank;
    vector<int>parent;
    unionfind(int n){
        rank.resize(n);
        fill(rank.begin(),rank.end(),0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int node){
        if(node==parent[node]){
            return node;
        }
        else{
            return parent[node] = find(parent[node]);
        }
    }
    bool Union(int u,int v){
        u = find(u);
        v = find(v);
        if(u==v){
            return false;
        }
        if(rank[u]<rank[v]){
            parent[u] = v;
        }
        else if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
        return true;
    }
};
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        unionfind u = unionfind(n);
        map<int,int>m;
        for(int i=0;i<n;i++){
            int x=nums[i];
            for(int j=2;j<=sqrt(nums[i]);j++){
                int flag=0;
                while(((x%j)==0)){
                    x/=j;
                    flag=1;
                }
                if(flag==0){
                    continue;
                }
                if(m.find(j)!=m.end()){
                    u.Union(i,m[j]);
                }
                else{
                    m[j]=i;
                }
            }
            if(x>1){
                if(m.find(x)!=m.end()){
                    u.Union(i,m[x]);
                }
                else{
                    m[x]=i;
                }
            }
        }
        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(u.find(i));
        }
        return s.size()==1;
    }
};