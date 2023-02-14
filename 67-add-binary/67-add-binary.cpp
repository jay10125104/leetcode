class Solution {
public:
    string addBinary(string a, string b) {
        if(b.size()>a.size()){
            swap(a,b);
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0;
        int c=0;
        // cout<<a<<" ";
        while(i<b.size()){
            int mid = c + a[i]-'0' + b[i]-'0';
            a[i] = (char)(mid%2+'0');
            c = mid/2;
            i++;
        // cout<<a<<" ";
            
        }
        if(c){
            
            while(i<a.size()){
            int mid = c + a[i]-'0';
            a[i] =(char)(mid%2+'0');
            c = mid/2;
            i++;
                // cout<<a<<" ";
            }
            if(c){
                a+="1";
            }
        }
        reverse(begin(a),end(a));
        return a;
    }
};