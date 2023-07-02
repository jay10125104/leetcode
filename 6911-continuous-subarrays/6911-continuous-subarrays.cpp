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
    long long continuousSubarrays(vector<int>& nums) {
        int i=0;
        int j=0;
        long long int ans=0;
        data_struct d = data_struct();
        while(i<nums.size()){
            d.insert(nums[i]);
            int mn = nums[i]-2;
            int mx=nums[i]+2;
            while(!(d.max()<=mx && d.min()>=mn)){
                d.remove(nums[j]);
                j++;
            }
            ans+=(i-j+1);
            i++;
        }
        return ans;
    }
};