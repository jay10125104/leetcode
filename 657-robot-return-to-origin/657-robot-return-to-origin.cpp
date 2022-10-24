class Solution {
public:
    bool judgeCircle(string s) {
        int x=0,y=0;
        for(auto i:s){
            if(i=='R'){
                x++;
                }
            else if(i=='L'){
                x--;
            }
            else if(i=='U'){
                y++;
            }
            else{
                y--;
            }
            
        }
        return x==0 && y==0;
    }
};