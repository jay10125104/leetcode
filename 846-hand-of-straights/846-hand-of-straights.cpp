class Solution {
public:
    bool isNStraightHand(vector<int>& v, int k) {
        int n= v.size();
        int count=0;
        if(n%k){
            return false;
        }
        else{
            map<int,int>m;
            for(auto &i:v){
                m[i]++;
            }
            for(auto &i:m){
                // cout<<"df";
                 
                int x = i.first;
                int y = i.second;
                // cout<<x<<"\n";
                if(!y){
                    continue;
                }
                // cout<<x<<" "<<(x+k-1)<<endl;
                for(int j=x;j<=(x+k-1);j++){
                    // cout<<j<<" ";
                    int t = m[j];
                    if(t<y){
                        return false;
                    }
                    else{
                        m[j]-=y;
                    }
                }
                // cout<<endl;
            }
                return true;
        }
        
    }
};