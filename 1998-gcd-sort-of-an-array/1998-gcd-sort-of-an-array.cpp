class Solution {
public:
    struct unionfind{
      vector<int>parent;
        unionfind(int n){
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
            
        }
        int find(int node){
            if(parent[node]==node){
                return node;
            }
            else{
                return parent[node] = find(parent[node]);
            }
        }
        bool Union(int u,int v){
            u = find(u);
            v = find(v);
            if(u!=v){
                parent[v] = u;
                return false;
            }
            return true;
        }
    };
    bool gcdSort(vector<int>& v) {
        
        unionfind u = unionfind(100001);
        for(auto &j:v){
            int n=j;
            if(n%2==0){
                u.Union(j,2);
            }
            while (n % 2 == 0)
    {
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        
        if(n%i==0){
            u.Union(j,i);
        }
        while (n % i == 0)
        {
           
            n = n/i;
        }
    }
    if (n > 2){
        u.Union(j,n);
    }
        }
    
        vector<pair<int,int>>p;
        for(int i=0;i<v.size();i++){
            p.push_back({v[i],i});
        }
        sort(p.begin(),p.end());
        for(int i=0;i<v.size();i++){
            int first = p[i].first;
            int second = v[i];
            if(u.find(first)!=u.find(second)){
                // cout<<first<<" "<<second<<endl;
                return false;
            }
        }
        return true;
    }
};