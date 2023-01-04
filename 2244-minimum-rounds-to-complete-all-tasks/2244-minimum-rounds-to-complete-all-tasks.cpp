class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>m;
        for(auto i:tasks){
            m[i]++;
        }
        int ans=0;
        for(auto i:m){
            int flag=0;
            cout<<i.second<<" ";
            int div = i.second / 3;
            int rem = i.second%3;
            if(i.second==1){
                return -1;
            }
            else {
            
            if(rem){
                while(i.second%3!=0){
                    i.second-=2;
                    ans++;
                }
                ans+=(i.second/3);
            }
                else{
                    ans+=i.second/3;
                }
            }
        }
        return ans;
        
    }
};