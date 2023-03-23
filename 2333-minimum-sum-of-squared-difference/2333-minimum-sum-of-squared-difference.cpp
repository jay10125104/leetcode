class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long int diff[100001];
        memset(diff,0,sizeof(diff));
        for(int i=0;i<nums1.size();i++){
            diff[abs(nums1[i]-nums2[i])]++;
        }
        long long int k = k1+k2;
        for(int i=100000;i>0;i--){

            if(k>=(diff[i])){
                diff[i-1]+=diff[i];
                k-=diff[i];
                diff[i]=0;
            }
            else{
                diff[i]-=k;
                diff[i-1]+=k;
                k=0;
            }
        }
        long long int ans=0;
        for(long long int i=1;i<100001;i++){
            ans+=diff[i]*(i*i);
        }
        return ans;
    }
};