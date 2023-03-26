class Solution {
public:
    vector< int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

    bool primeSubOperation(vector<int>& nums) {
        vector<int>v = sieve(1000);
        int prev=0;
        // for(auto &i:v){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<nums.size();i++){
            int k=-1;
            int neww=nums[i];
            for(int j=0;j<v.size();j++){
                if(v[j]<nums[i] && (nums[i]-v[j])>prev){
                    neww=nums[i]-v[j];
                }
            }
            nums[i]=neww;
            if(prev>=nums[i]){
                return false;
            }
            prev=nums[i];
            // cout<<nums[i]<<" "<<prev<<" ";
        }
        
        vector<int>t = nums;
        sort(t.begin(),t.end());
        return t==nums;
    }
};