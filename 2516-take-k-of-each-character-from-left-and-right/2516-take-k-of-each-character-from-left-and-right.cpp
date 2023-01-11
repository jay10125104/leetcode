class Solution {
public:
    int takeCharacters(string s, int k) {
        int i=0;
        int a=0;
        int b=0;
        int c=0;
        int n=s.size();
        while(i<n && ((a<k) || (b<k) ||(c<k))){
            a+=(s[i]=='a');
            b+=(s[i]=='b');
            c+=(s[i]=='c');
            i++;
        }
        if((a<k) || (b<k) ||(c<k)){
            return -1;
        }
        else{
        int ans=i;
            int j=n-1;
            i--;
        while(i>=0){
            a-=(s[i]=='a');
            b-=(s[i]=='b');
            c-=(s[i]=='c');
            while((j>=0) && ((a<k) || (b<k) ||(c<k))){
                a+=(s[j]=='a');
                b+=(s[j]=='b');
                c+=(s[j]=='c');
                j--;
            }
            if(a>=k && b>=k && c>=k){
                int mid= (i) + (n-j-1);
                ans = min(ans,mid);
            }
            i--;
                
        }
            
        
        return ans;
        }
    }
};