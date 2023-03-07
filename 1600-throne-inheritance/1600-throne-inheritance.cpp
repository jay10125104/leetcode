class ThroneInheritance {
public:
    map<string,int>m;
    map<int,string>m1;
   
    vector<string>ans;
    int timer=1;
    vector<int>adj[200001];
    int visited[200001];
    
    ThroneInheritance(string kingName) {
    m[kingName]=0;
    m1[0]=kingName;
        memset(visited,0,sizeof(visited));
    }
    void dfs(int src,int parent){
        string s = m1[src];
        if(visited[src]==0){
            ans.push_back(s);
        }
        for(auto &i:adj[src]){
            if(i!=parent){
                dfs(i,src);
            }
        }
    }
    void birth(string p, string c) {
        int parent = m[p];
        m1[timer]=c;
        m[c]=timer++;
        adj[parent].push_back(m[c]);
    }
    
    void death(string name) {
        visited[m[name]]=1;
    }
    
    vector<string> getInheritanceOrder() {
        ans.clear();
        dfs(0,-1);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */