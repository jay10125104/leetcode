class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
      int req=0;
        int ans=0;
        map<int,int>m;
        for(int i=0;i<v.size();i++){
            
            m[v[i]]++;
            while(m.find(req)!=m.end()){
                req++;
            }
            if((i+1)==req){
                ans++;
            }
        }
        return ans;
    }
};