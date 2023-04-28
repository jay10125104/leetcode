class Solution {
public:
    struct Unionfind{
        vector<int>parent;
        Unionfind(int n){
            vector<int>v(n);
            for(int i=0;i<n;i++){
                v[i]=i;
            }
            parent=v;
        }
        int find(int node){
            if(parent[node]==node){
                return node;
            }
            else{
                return parent[node] = find(parent[node]);
            }
        }
        void unionthem(int u,int v){
            u=find(u);
            v=find(v);
            parent[u]=v;
        }
    };
    int numSimilarGroups(vector<string>& s) {
        set<int>st;
        int n=s.size();
        Unionfind u = Unionfind(n);
        // cout<<"sdf";
        for(int i=0;i<s.size();i++){
            for(int j=i-1;j>=0;j--){
                // cout<<"Sdf2";''
                int count=0;
                for(int k=0;k<s[i].size();k++){
                    if(s[i][k]!=s[j][k]){
                        count++;
                    }
                }
                if(count<=2){
                    u.unionthem(i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            st.insert(u.find(i));
        }
        return st.size();
        // return s.size();
    }
};