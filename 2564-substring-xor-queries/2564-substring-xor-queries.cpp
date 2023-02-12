class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& q) {
        map<string,int>m;
        for(int i=0;i<s.size();i++){
            for(int j=1;j<=32;j++){
                if((i+j)<=s.size()){
                    string mid = s.substr(i,j);
                    if(m.find(mid)==m.end()){
                        m[mid]=i;
                    }
                }
                else{
                    break;
                }
            }
        }
        vector<vector<int>>sol;
        for(auto &i:q){
            int x = i[0]^i[1];
            string ans="";
            if(x==0){
                ans="0";
            }
            while(x){
                if(x&1){
                    ans+='1';
                }
                else{
                    ans+='0';
                }
                x = x/2;
            }
            reverse(ans.begin(),ans.end());
            if(m.find(ans)==m.end()){
                sol.push_back({-1,-1});
            }
            else{
                sol.push_back({(int)m[ans],m[ans]+(int)ans.size()-1});
            }
        }
        return sol;
    }
};