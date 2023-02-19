struct unionfind
{
    int n;
    // vector<int> rank;
    vector<int> parent;
    unionfind(int n)
    {
        
        // fill(rank.begin(), rank.end(), 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        else
        {
            return parent[node] = find(parent[node]);
        }
    }
    bool Union(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
        {
            return false;
        }
        
        parent[v] = u;
        return true;
    }
};
class Solution {
public:
    string findTheString(vector<vector<int>>& v) {
        int n=v.size();
        unionfind u = unionfind(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]){
                    u.Union(i,j);
                }
            }
        }
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(u.find(i)==u.find(j)){
                    dp[i][j]=1;
                    if(i+1<n && j+1<n){
                        dp[i][j] = dp[i+1][j+1]+1;
                    }
                }
                if(dp[i][j]!=v[i][j]){
                    return "";
                }
            }
        }
        // cout<<1;
        char x = 'a'-1;
        string s="";
        map<char,int>m;
        for(int i=0;i<n;i++){
            if(m.find(u.find(i))!=m.end()){
                s+=m[u.find(i)];
            }
            else{
                x++;
                m[u.find(i)]=x;
                s+=x;
            }
        }
        if(x>'z'){
            return "";
        }
        return s;
    }
};