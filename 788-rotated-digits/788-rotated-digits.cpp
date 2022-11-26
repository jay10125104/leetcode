class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            string mid = to_string(i);
            int flag=1;
            int cnt=0;
            for(auto &i:mid){
                if(i=='3'||i=='4'||i=='7'){
                    flag=0;
                }
                if(i=='0'||i=='1'||i=='8'){
                    cnt++;
                }
            }
            if(cnt!=mid.size())
            ans+=flag;
        }
        return ans;
    }
};