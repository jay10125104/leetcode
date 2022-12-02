class Solution {
public:
    int minimumBuckets(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='H'){
                int flag1=0;
                int flag2=0;
                if(i-1>=0 && s[i-1]!='H'){
                    flag1=1;
                }
                if((i+1)<n && s[i+1]!='H'){
                    flag2=1;
                }
                if((flag1+flag2)==0){
                    return -1;
                }
                else{
                    if(flag1 && s[i-1]=='C'){
                        continue;
                    }
                    if(flag1 && flag2){
                        ans++;
                        s[i+1]='C';
                    }
                    
                    else if(flag1 && flag2==0){
                        s[i-1]='C';
                        ans++;
                    }
                    else if(flag1==0 && flag2){
                        s[i+1]='C';
                        ans++;
                    }
                }
        }
        // cout<<s<<endl;
            
        }
        return ans;
    }
};