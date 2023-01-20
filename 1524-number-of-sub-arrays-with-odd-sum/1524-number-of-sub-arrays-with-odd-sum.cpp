class Solution {
public:
    int mod = 1000000007;
    int numOfSubarrays(vector<int>& arr) {
        int sum=0;
        long long int ans=0;
        int x=0;
        int y=1;
        for(int i=0;i<arr.size();i++){
           sum+=arr[i];
            if(sum%2){
                x++;
                ans+=y;
            }
            else{
                y++;
                ans+=x;
            }
            
            
        }
        return (ans%mod+mod)%mod;
    }
};