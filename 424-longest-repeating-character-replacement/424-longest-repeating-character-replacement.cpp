class Solution {
public:
    int characterReplacement(string s, int k) {
        int j=0;
        int ans=0;
        map<int,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
            if(m.size()>1){
                int flag=1;
                while(flag){
                    int sum=0;
                    int mx=0;
                    for(auto &i:m){
                        sum+=i.second;
                        mx = max(mx,i.second);
                    }
                    sum-=mx;
                    if(sum<=k){
                        flag=0;
                    }
                    else{
                        m[s[j]]--;
                        j++;
                    }
                }
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};