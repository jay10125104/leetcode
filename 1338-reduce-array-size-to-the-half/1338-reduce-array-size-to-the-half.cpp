class Solution {
public:
    int minSetSize(vector<int>& arr) {
      int n=arr.size();
        // int ans=n;
        map<int,int>m;
        for(auto &i:arr){
            m[i]++;
        }
        int ans=0;
        vector<int>v;
        for(auto &i:m){
            v.push_back(i.second);
        }
        int count=0;
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--){
            ans+=v[i];
            count++;
            if(ans>=(n/2)){
                return count;
            }
        }
        return -1;
    }
};