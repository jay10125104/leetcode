class Solution {
public:
    struct data_struct{
    multiset<int>m;
    data_struct(){

    }
    void insert(int x){
        m.insert(x);
    }
    void remove(int x){
        m.erase(m.find(x));
    }
    void erase(int x){
        m.erase(x);
    }
    bool count(int x){
        return m.count(x);
    }
    int size(){
        return m.size();
    }
    int lower_bound(int x){
        auto it =  m.lower_bound(x);
        if(it==m.end()){
            return -1;
        }
        else{
            return *it;
        }
    }
    auto upper_bound(int x){
        auto it =  m.upper_bound(x);
        if(it==m.end()){
            return -1;
        }
        else{
            return *it;
        }
    }
    int max(){
        return *(--m.end());
    }
    int min(){
        return *(m.begin());
    }
};
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0;
        data_struct d = data_struct();
        int j=0;
        int ans=0;
        while(i<nums.size()){
            d.insert(nums[i]);
            int mx = d.max();
            int mn = d.min();
            while((mx-mn)>limit){
                // cout<<mx<<" "<<mn<<endl;
                d.remove(nums[j++]);
                mx=d.max();
                mn=d.min();
            }
            // cout<<i<<"*"<<j<<endl;
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};