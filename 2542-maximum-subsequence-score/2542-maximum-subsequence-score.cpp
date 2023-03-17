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
        long long int sum=0;
        vector<long long int>ans(n);
        for(int i=n-1;i>=0;i--){
            q.push(v[i].second);
            sum+=v[i].second;
            ans[i]=sum;
            
            if(q.size()>=k){
                sum-=q.top();
                q.pop();
            }
            // cout<<ans[i]<<" ";
            
        }
        long long int sol=0;
        for(int i=0;i<v.size()-k+1;i++){
            sol = max(sol,(long long int)v[i].first*(ans[i]));
            // cout<<sol<<" ";
        }
        // cout<<endl;
        return sol;
        
    }
};