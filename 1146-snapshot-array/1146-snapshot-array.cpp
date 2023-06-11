class SnapshotArray {
public:
    map<int,vector<vector<int>>>m;
    int count=0;
    SnapshotArray(int length) {
    }
    
    void set(int index, int val) {
        // cout<<m[index].size()<<endl;
        vector<int>mid;
        mid.push_back(count);
        mid.push_back(val);
        m[index].push_back(mid);
    }
    
    int snap() {
        count++;
        return count-1;
    }
    
    int get(int index, int snap_id) {
        int low=0;
        int high=m[index].size()-1;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(m[index][mid][0]<=snap_id){
                low=mid+1;
                ans=m[index][mid][1];
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */