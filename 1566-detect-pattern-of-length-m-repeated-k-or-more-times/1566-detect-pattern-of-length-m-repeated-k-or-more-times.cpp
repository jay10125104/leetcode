#include<bits/stdc++.h>
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n=arr.size();
        for(int i=0;i<=n-m;i++){
            vector<int>t(m);
            copy(arr.begin()+i,arr.begin()+i+m,t.begin());
            int j=i+m;
            int count=1;
            while((j+m)<=n){
                vector<int>mid(m);
            copy(arr.begin()+j,arr.begin()+j+m,mid.begin());
                if(mid==t){
                    count++;
                }
                else{
                    break;
                }
                j+=m;
            }
            if(count>=k){
                return true;
            }
        }
        return false;
    }
};