class Solution {
public:
    int takeCharacters(string s, int k) {
        int a=0;
        int b=0;
        int c=0;
        for(auto &i:s){
            a+=(i=='a');
            b+=(i=='b');
            c+=(i=='c');
        }
        if(k==0){
            return 0;
        }
        if(a<k || b<k || c<k){
            return -1;
        }
        else{
            int A=0;
            int B=0;
            int C=0;
            int n=s.size();
            int i=0;
            while(A<k || B<k || C<k){
            A+=(s[i]=='a');
            B+=(s[i]=='b');
            C+=(s[i]=='c');
            i++;
            }
            int sol = i;
            i--;
            int j=n-1;
            // int j=n-1;
            while(i>=0){
            A-=(s[i]=='a');
            B-=(s[i]=='b');
            C-=(s[i]=='c');
                while((A<k || B<k || C<k) && j>=i){
                    A+=(s[j]=='a');
                    B+=(s[j]=='b');
                    C+=(s[j]=='c');
                    j--;
                }
                int tt = i+n-1-j;
                if(A>=k && B>=k && C>=k){
                sol = min(sol,tt);
                }
                i--;
            }
        return sol;
            
        }
    
    }
};