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
    int count(int x){
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

    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int>m;
        for(auto &i:nums){
            m[i]++;
        }
        while(m.size()){
            auto it = m.begin();
            int mn = it->first;
            int freq = it->second;
            // cout<<mn+k<<" "<<freq<<endl;
            for(int i=mn;i<(mn+k);i++){
                if(m.find(i)!=m.end()){
                    if(m[i]<freq){
                        return false;
                    }
                    else{
                        m[i]-=freq;
                        if(m[i]==0){
                            m.erase(i);
                        }
                    }
                    
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};