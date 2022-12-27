class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int add) {
        int idx=0;
        for(auto i:c){
            r[idx] = i - r[idx];
            idx++;
        }
        int count=0;
        sort(r.begin(),r.end());
        for(auto i:r){
            if(i==0){
                count++;
            }
            else if(add>=i)
            {
                add-=i;
                count++;
                
                
            }
            else{
                break;
            }
            
        }
        return count;
    }
};