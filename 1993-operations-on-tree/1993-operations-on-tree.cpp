class LockingTree {
public:
    int locked[2001];
    vector<int>adj[2001];
    int n;
    vector<int>v;
    void dfs(int src,int parent,int &ans){
        
        for(auto &i:adj[src]){
            if(i!=parent){
                if(locked[i]!=-1){
                    ans++;
                }
                locked[i]=-1;
                dfs(i,src,ans);
            }
        }
    }
    LockingTree(vector<int>& parent) {
        n=parent.size();
        v=parent;
        memset(locked,-1,sizeof(locked));
        for(int i=1;i<parent.size();i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(locked[num]==-1){
            locked[num]=user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(locked[num]!=user){
            return false;
        }
        else{
            locked[num]=-1;
            return true;
        }
    }
    
    bool upgrade(int num, int user) {
        int parents=num;
        while(parents!=-1){
            if(locked[parents]!=-1){
                return false;
            }
            parents=v[parents];
        }
        
        int ans=0;
        dfs(num,v[num],ans);
        if(ans){
            locked[num]=user;
        }
        return ans;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */