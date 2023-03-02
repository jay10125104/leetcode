class TreeAncestor {
public:
    vector<int>adj[50001];
    int mx = 19;
    int dp[19][50001];
    void build(vector<int>&parent){
    int n=parent.size();
    for(int i=0;i<n;i++){
        dp[0][i] = parent[i];
    }
    for(int i=1;i<mx;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
}
int query(int src,int k){
    for(int i=0;i<mx;i++){
        int mask = (1<<i);
        if(k&mask){
            src = dp[i][src];
        }
    }
    return src;
}
    TreeAncestor(int n, vector<int>& parent) {
        parent.insert(parent.begin(),0);
        for(int i=1;i<=n;i++){
            parent[i]++;
        }
        build(parent);
    }
    
    int getKthAncestor(int node, int k) {
        node++;
        int x = query(node,k);
        return x-1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */