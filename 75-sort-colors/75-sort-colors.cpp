class Solution {
public:
    void sortColors(vector<int>& v) {
        //DUTCH WALI PUBLIC BOLENGHE
        int low=0;
        int n=v.size();
        int high=n-1;
        int mid=0;
        while(mid<=high){
            if(v[mid]==0){
                swap(v[mid++],v[low++]);
            }
            else if(v[mid]==1){
                mid++;
            }
            else{
                swap(v[mid],v[high--]);
            }
        }
        
    }
};