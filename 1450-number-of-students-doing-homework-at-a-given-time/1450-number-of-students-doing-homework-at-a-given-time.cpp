class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int k) {
        int n=startTime.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(startTime[i]<=k && endTime[i]>=k){
                ans++;
            }
        }
        return ans;
    }
};