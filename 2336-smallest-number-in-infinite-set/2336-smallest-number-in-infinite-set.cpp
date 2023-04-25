class SmallestInfiniteSet {
public:
    map<int,int>m;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++){
            m[i]++;
        }
    }
    
    int popSmallest() {
        for(auto i:m){
            if(i.second!=0){
                m[i.first]=0;
                return i.first;
            }
        }
        return 0;
    }
    
    void addBack(int num) {
        m[num]=1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */