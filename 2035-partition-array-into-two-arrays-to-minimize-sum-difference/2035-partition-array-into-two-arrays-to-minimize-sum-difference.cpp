class Solution {
public:
    map<int,vector<int>>ans(vector<int>&v){
        int n=v.size();
        map<int,vector<int>>m;
        for(int i=1;i<=((1<<n)-1);i++){
            int sum=0;
            int bits = __builtin_popcount(i);
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    sum+=v[j];
                }
            }
            m[bits].push_back(sum);
        }
        return m;
    }
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>v1;
        vector<int>v2;
        int sum=0;
        for(int i=0;i<n/2;i++){
            v1.push_back(nums[i]);
            sum+=nums[i];
        }
        int solution = INT_MAX;
        for(int i=n/2;i<n;i++){
            v2.push_back(nums[i]);
            sum+=nums[i];
        }
        map<int,vector<int>>m1=ans(v1);
        map<int,vector<int>>m2=ans(v2);
        for(auto &i:m1){
            sort(i.second.begin(),i.second.end());
        }
        for(auto &i:m2){
            sort(i.second.begin(),i.second.end());
        }
        int N=n/2;
        int total = sum;
        sum/=2;
        for(int i=1;i<=N;i++){
            int next_size = N-i;
            for(auto &it:m1[i]){
                int req = sum-it;
                int sol=-1;
                int low=0;
                int high = m2[next_size].size()-1;
                while(low<=high){
                    int mid=(low+high)/2;
                    if(m2[next_size][mid]<=req){
                        sol=mid;
                        low=mid+1;
                    }
                    else{
                        high=mid-1;
                    }
                }
                if(sol!=-1){
                    int sum1=it+m2[next_size][sol];
                    int sum2 = total-sum1;
                    // cout<<i<<" "<<it<<" "<<m2[next_size][sol]<<" "<<sum1<<" "<<sum2<<" "<<abs(sum1-sum2)<<endl;
                    solution=min(solution,abs(sum1-sum2));
                }
                else if(i==N){
                    int sum1=it;
                    int sum2 = total-sum1;
                    // cout<<i<<" "<<it<<" "<<" "<<sum1<<" "<<sum2<<" "<<abs(sum1-sum2)<<endl;

                    solution=min(solution,abs(sum1-sum2));
                }
            }
        }
        return solution;
    }
};