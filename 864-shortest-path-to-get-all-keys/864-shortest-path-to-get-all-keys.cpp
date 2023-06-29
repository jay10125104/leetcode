class Solution {
public:
    int shortestPathAllKeys(vector<string>& v) {
        int startx=-1;
        int starty=-1;
        int count=0;
        map<int,int>m;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]=='@'){
                    startx=i;
                    starty=j;
                }
                if(v[i][j]>='a'  && v[i][j]<='f'){
                    m[v[i][j]-'a']=count;
                    count++;
                }
            }
        }
        map<vector<int>,int>visited;
        int k=count;
        // int ans = dfs(v,startx,starty,0,k);
        queue<vector<int>>q;
        q.push({startx,starty,0});
        int ans=0;
        if(k==0){
            return 0;
        }
        vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        while(q.size()){
            int x=q.size();
            while(x--){
                vector<int>t=q.front();
                q.pop();
                int val = t[2];
                int i=t[0];
                int j=t[1];
                if(v[i][j]=='#'){
                    continue;
                }
                if(v[i][j]>='a' && v[i][j]<='z'){
                    val|=(1<<m[v[i][j]-'a']);
                }
                if(v[i][j]>='A' && v[i][j]<='Z'){
                    if((val&(1<<m[v[i][j]-'A']))==0){
                        continue;
                    }
                }
                if(visited[{i,j,val}]){
                    continue;
                }
                visited[{i,j,val}]=1;
                int bit=__builtin_popcount(val);
                if(bit==k){
                    return ans;
                }
                for(auto &it:dir){
                    int newx = t[0]+it[0];   
                    int newy = t[1]+it[1];
                    if(newx>=0 && newx<v.size() && newy>=0 && newy<v[0].size()){
                        q.push({newx,newy,val});
                    }
                    
                }
            }
            ans++;
        }
        return -1;
    }
};