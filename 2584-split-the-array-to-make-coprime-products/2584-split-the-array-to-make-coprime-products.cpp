class Solution {
public:
    int findValidSplit(vector<int>& v) {
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        int n=v.size();
        int count1=0;
        for(auto &i:v){
            int x = i;
            for(int j=2;j<=sqrt(i);j++){
                while(x && ((x%j)==0)){
                    x = x/j;
                    m2[j]++;
                }
            }
            if(x>1){
                m2[x]++;
            }
        }
        for(int i=0;i<n-1;i++){
            int x = v[i];
            for(int j=2;j<=sqrt(x);j++){
                while(x && ((x%j))==0){
                    x=x/j;
                    m1[j]++;
                    m2[j]--;
                    if(m2[j]==0){
                        count1++;
                    }
                }
            }
            if(x>1){
                m1[x]++;
                m2[x]--;
                if(m2[x]==0){
                        count1++;
                    }
            }
            
            if(count1==m1.size()){
                return i;
            }
            
        }
        return -1;
    }
};