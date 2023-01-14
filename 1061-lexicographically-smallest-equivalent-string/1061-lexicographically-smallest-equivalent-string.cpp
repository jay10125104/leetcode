class Solution {
public:
    struct Unionfind{
        vector<int>parent;
        Unionfind(int n){
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
        void Union(int u,int v){
            u = find(u);
            v = find(v);
            if(u!=v){
                if(u<v)
                parent[v]=u;
                else
                parent[u] = v;
            }
        }
    };
    string smallestEquivalentString(string s, string t, string str) {
        int n=s.size();
        Unionfind u = Unionfind(26);
        for(int i=0;i<n;i++){
            int a = s[i]-'a';
            int b = t[i]-'a';
            u.Union(a,b);
        }

        // cout<<"df";
        string ans="";
        for(int i=0;i<str.size();i++){
            int x = u.find(str[i]-'a');
            char ti = 'a'+x;
            ans+=ti;
        }
        return ans;
    }
};