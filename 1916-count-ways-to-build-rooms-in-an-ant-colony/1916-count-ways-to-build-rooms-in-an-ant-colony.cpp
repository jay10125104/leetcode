class Solution {
public:
    int m=1000000007;
    int fact[100001];
    long long int op2(long long int a, long long int b, long long int m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

long long int binaryexpo(long long int a,long long int b){
    long long int ans=1;
    while(b){
        if(b&1){
            ans = (ans*a)%m;
        }
        a = (a*a)%m;
        b=b/2;
    }
    return ans;
}
void factorial(){
    long long int ans=1;
    fact[0]=1;
    for(int i=1;i<=100000;i++){
        ans = ans*i;
        ans=ans%m;
        fact[i]=ans;
    }
}
long long int ans(int n,int r){
    if(n<r){
        return 1;
    }
    long long int n_r=n-r;
    long long int n_r_inverse = binaryexpo(fact[n_r],m-2);
    long long int r_inverse = binaryexpo(fact[r],m-2);
    long long int sol = ((fact[n]%m)*(n_r_inverse%m))%m;
    sol = ((sol%m)*(r_inverse%m))%m;
    return sol;
}
    int ways[100001];
    int sz[100001];
    void dfs(vector<int>adj[],int src,int parent){
        int total=0;
        ways[src]=1;
        for(auto &i:adj[src]){
            if(i!=parent){
                dfs(adj,i,src);
                total+=sz[i];
                ways[src] = op2(ways[src],ways[i],m);
                ways[src] = op2(ways[src],ans(total,sz[i]),m);
                // ways[src] = ways[src]*ways[i]*);
            }
        }
        sz[src]=total+1;    
    }
    int waysToBuildRooms(vector<int>& v) {
        factorial();
        int n=v.size();
        vector<int>adj[n];
        memset(sz,0,sizeof(sz));
        for(int i=1;i<n;i++){
            adj[v[i]].push_back(i);
            adj[i].push_back(v[i]);
        }
        dfs(adj,0,-1);
        return ways[0];
        
    }
};