class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int n=nums.size();
            int ele=0;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(cnt==0){
                    ele=nums[i];
                    cnt++;
                }
                else if(ele!=nums[i]){
                    cnt--;
                }
                else{
                    cnt++;
                }
            }
            if(cnt==0) return -1;
            return ele;
        }
    };