class Solution {
public:
    int waysToMakeFair(vector<int>& v) {
        int n=v.size();
        int even[n];
        int odd[n];
        if(n==1){
            return 1;
        }
        memset(even,0,sizeof(even));
        memset(odd,0,sizeof(odd));
        int e=0;
        int o=0;
        int sum=0;
        for(int i=n-1;i>=0;i--){
            even[i]=e;
            odd[i]=o;
            if(i%2==0){
                e+=v[i];
            }
            else{
                o+=v[i];
            }
            sum+=v[i];
        }
        // for(auto &i:odd){
        //     cout<<i<<" "; 
        // }
        // cout<<endl;
        // for(auto &i:even){
        //     cout<<i<<" "; 
        // }
        // cout<<endl;
        int ans = ((even[0]==odd[0])?(1):(0));
        e = v[0];
        o=0;
        // cout<<ans<<endl;
        for(int i=1;i<n;i++){
            int nexteven = (odd[i]);
            int nextodd = (even[i]);
            // cout<<e<<" "<<o<<" "<<nexteven<<" "<<nextodd<<" "<<endl;
            if((e+nexteven)==(o+nextodd)){
                ans++;
            }
            if(i%2){
                o+=v[i];
            }
            else{
                e+=v[i];
            }
        }
        return ans;
    }
};