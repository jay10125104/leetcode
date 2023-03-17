class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<int,vector<int>,greater<int>>q;
        vector<pair<int,int>>v;
        int n=nums1.size();
        vector<int>t(n);
        for(int i=0;i<nums1.size();i++){
            v.push_back({nums2[i],nums1[i]});
            
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            t[i] = v[i].second;
        }
        int ti = k-1;
        int i=n-1;
        long long int sum=0;
        vector<long long int>ans(n);
        for(int i=n-1;i>=0;i--){
            q.push(t[i]);
            ans[i]=sum;
            sum+=t[i];
            if(q.size()>=k){
                sum-=q.top();
                q.pop();
            }
            // cout<<ans[i]<<" ";
            
        }
        long long int sol=0;
        for(int i=0;i<v.size();i++){
            sol = max(sol,(long long int)v[i].first*(v[i].second+ans[i]));
            // cout<<sol<<" ";
        }
        // cout<<endl;
        return sol;
        
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        return maxScore(speed,efficiency,k)%1000000007;
    }
};