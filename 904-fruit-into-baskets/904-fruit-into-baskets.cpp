class Solution {
public:
    int totalFruit(vector<int>& v) {
        map<int,int>m;
        int j=0;
        int ans=0;
        for(int i=0;i<v.size();i++){
            m[v[i]]++;
            
                while(m.size()>=3){
                    m[v[j]]--;
                    if(m[v[j]]==0){
                        m.erase(v[j]);
                    }
                    j++;
                }
            
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};