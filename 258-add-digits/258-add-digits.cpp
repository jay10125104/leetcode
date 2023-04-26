class Solution {
public:
    int addDigits(int num) {
        
        int ans=0;
        while(num){
            
            if(num>=0 && num<=9){
                return num;
            }
            ans = 0;
            
            while(num){
                ans = ans + (num%10);
                num = num/10;
            }
            num = ans;
        }
        return 0;
    }
};