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

    int minimumDeviation(vector<int>& nums) {
        data_struct d = data_struct();
        for(auto &i:nums){
            if(i%2){
                d.insert(i*2);
            }
            else{
                d.insert(i);
            }
        }
        int ans = INT_MAX;
        while(d.size()){
            int x = d.max();
            int mn=d.min();
                ans = min(ans,x-mn);
            if(x%2){
                break;
            }
            else{
                
                d.erase(x);
                d.insert(x/2);
            }
        }
        return ans;
    }
};