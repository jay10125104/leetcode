class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char target) {
        int n = v.size();
        
        int start =0;
        int end =n-1;
        while(start<=end){
            int middle = (start+end)/2;
          
            if(target<v[middle]){
                end = middle-1;
            }
            else{
                start = middle+1;
            }
        }
        return v[start%n];
    }
};