class Solution {
public:
    void nextPermutation(vector<int>& v) {
       int idx=-1;
        int n=v.size();
        for(int i=n-2;i>=0;i--){
            if(v[i]<v[i+1]){
                idx=i;
                break;
            }
        }
        // cout<<idx<<endl;
        if(idx==-1){
            sort(v.begin(),v.end());
            return;
        }
        for(int i=n-1;i>idx;i--){
            if(v[i]>v[idx]){
                swap(v[i],v[idx]);
                break;
            }
        }
        int i=idx+1;
        int j=n-1;
        while(i<j){
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
};