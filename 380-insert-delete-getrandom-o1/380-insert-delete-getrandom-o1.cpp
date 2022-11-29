class RandomizedSet {
public:
    map<int,int>m;
    vector<int>v;
    int idx=0;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end()){
            return false;
        }
        else{
            v.push_back(val);
            m[val] = idx;
            idx++;
            return true;
        }
    }
    
    bool remove(int val) {
        if(m.find(val)!=m.end()){
            v[m[val]] = v[v.size()-1];
            m[v[v.size()-1]] = m[val];
            m.erase(val);
            v.pop_back();
            idx--;
            return true;
        }
        else{
            return false;
        }
        
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */