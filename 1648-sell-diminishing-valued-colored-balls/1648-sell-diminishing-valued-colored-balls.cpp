class Solution {
public:
    int maxProfit(vector<int>& inventory, int k) {
        priority_queue<long long int>q;
        q.push(0);
        long long int level=0;
        for(auto &i:inventory){
            q.push(i);
        }
        int mod = 1000000007;
        long long int ans=0;
        while(q.size()){
            level++;
            long long int x = q.top();
            if(x==0){
                break;
            }
            else{
                q.pop();
                long long int y = q.top();
                if(x==y){
                    continue;
                }
                long long int diff = x-y;
                long long int canmade = (diff)*level;
                // int div = 
                // cout<<canmade<<endl;
                if(canmade>=k){
                    long long int div = k/level;
                    long long int rem = k%level;
                    long long int newval = x-div;
                    // cout<<div<<" "<<rem<<" "<<newval<<" "<<level<<endl;
                    ans+=((((div*(2*x-div+1)))/2)*level);
                    ans+=(rem*newval);
                    k=0;
                    
                }
                else{
                    k-=canmade;
                    // cout<<canmade<<" "<<(((diff)*(x+y+1))/2)*level<<endl;            
                    ans+=(((diff)*(x+y+1))/2)*level;
                }
            }
        }
        return ((ans%mod + mod)%mod)%mod;
        
    }
};