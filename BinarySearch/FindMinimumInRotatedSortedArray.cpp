class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=INT_MAX;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[l]<=nums[m]){
                int leftMost=nums[l];
                ans=min(ans,leftMost);
                l=m+1;
            }
            else {
                int leftMost=nums[m];
                ans=min(ans,leftMost);
                r=m-1;
            }
        }
        return ans;
    }
};