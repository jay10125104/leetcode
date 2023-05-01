class Solution {
public:
    double average(vector<int>& v) {
        sort(v.begin(),v.end());
     double sum=0;
        
        // int j=v.size()-1;
        for(int i=1;i<v.size()-1;i++){
            sum=sum+v[i];
        }
        return (double)(sum/(float)(v.size()-2));
    }
};