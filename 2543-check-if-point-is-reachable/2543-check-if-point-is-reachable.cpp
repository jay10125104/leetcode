class Solution {
public:
    bool isReachable(int x, int y) {
        while(((x%2)==0)){
            x=x/2;
        }
        while(((y%2)==0)){
            y=y/2;
        }
        return gcd(x,y)==1;
    }
};