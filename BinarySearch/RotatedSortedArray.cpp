class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
        if(nums[m]==target){
            return m;
        }
        if (nums[l] <= nums[m]) {  // nums[l..m] are sorted.
         if (nums[l] <= target && target < nums[m]){
          r = m - 1;}
         else{
          l = m + 1;}
      } 
            else {  // nums[m..n - 1] are sorted.
        if (nums[m] < target && target <= nums[r]){
          l = m + 1;}
        else{
          r = m - 1;}
        }
        }
        return -1;
    }
};