bool cmp(pair<string,int>&a,pair<string,int>&b){
    return a.second<b.second;
}
class TimeMap {
public:
    map<string,vector<pair<string,int>>>m;
    TimeMap() {
        
    }    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value,timestamp});
    }
    
    string get(string key, int t) {
        int start=0;
        int end = m[key].size()-1;
        string s = "";
        while(start<=end){
            int mid=(start+end)/2;
            if(m[key][mid].second<=t){
                start=mid+1;
                s = m[key][mid].first; 
            }
            else{
                end = mid-1;
            }
        }
        return s;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */