bool cmp(vector<int>&a,vector<int>&b){
    return a[0]>b[0];
}
struct unionfind{
    vector<int>parent;
    vector<int>rank;
    unionfind(int n){
        vector<int>p(n);
        parent = p;
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
        vector<int>r(n);
        rank = r;
    }
    int find(int node){
        if(parent[node]==node){
            return node;
        }
        else{
            return parent[node] = find(parent[node]);
        }
    }
    bool unionthem(int u,int v){
        int x = find(u);
        int y = find(v);
        if(x==y){
            return false;
        }
        else if(x<y){
            parent[x] = y;
            
        }
        else{
            parent[y] = x;
        }
        return true; 
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),cmp);
        unionfind u1 = unionfind(n+1);
        int ans=0;
        unionfind u2 = unionfind(n+1);
        int counta=0;
        int countb=0;
        for(auto i:edges){
            if(i[0]==3){
                bool flag1 = u1.unionthem(i[1],i[2]);
                bool flag2 = u2.unionthem(i[1],i[2]);
                if(flag1){
                    counta++;
                }
                if(flag2){
                    countb++;
                }
                if(flag1==0 && flag2==0){
                    ans++;
                }
            }
            else if(i[0]==2){
                bool flag2 = u2.unionthem(i[1],i[2]);
                if(flag2){
                    countb++;
                }
                else{
                    ans++;
                }
            }
            else{
                bool flag2 = u1.unionthem(i[1],i[2]);
                if(flag2){
                    counta++;
                }
                else{
                    ans++;
                }
            }
        }
        return (((counta==countb)&&(counta==n-1) )? (ans) : (-1));
    }
};