#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    data_struct;
class Solution {
public:

    vector<int> resultArray(vector<int>& nums) {
        data_struct o1,o2;
        o1.insert(nums[0]);
        o2.insert(nums[1]);
        vector<int>one;
        vector<int>two;
        one.push_back(nums[0]);
        two.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            int x = o1.size()-o1.order_of_key(nums[i]+1);
            int y = o2.size()-o2.order_of_key(nums[i]+1);
            if(x>y){
                one.push_back(nums[i]);
                o1.insert(nums[i]);
            }
            else if(x<y){
                two.push_back(nums[i]);
                o2.insert(nums[i]);
            }
            else{
                if(one.size()<=two.size()){
                    one.push_back(nums[i]);
                    o1.insert(nums[i]);
                }
                else{
                    two.push_back(nums[i]);
                    o2.insert(nums[i]);
                }
            }
        }
        for(auto &i:two){
            one.push_back(i);
        }
        return one;
    }
    
};