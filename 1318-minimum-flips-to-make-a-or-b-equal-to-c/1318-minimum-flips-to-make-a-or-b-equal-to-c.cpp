class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0;i<=31;i++){
            int one = ((a&(1<<i))!=0);
            int two = ((b&(1<<i))!=0);
            int three = ((c&(1<<i))!=0);
            int orr = one||two;
            if(orr!=three){
                if(three==0){
                    ans+=one;
                    ans+=two;
                }
                else{
                    ans++;
                }
            }
        }
        return ans;
    }
};