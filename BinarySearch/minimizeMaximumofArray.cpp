class Solution {
public:

    bool possible(int mid, int size, vector<int> nums) {
        if(mid<nums[0]) {
            return false;
        }
        long long sum = nums[size-1];
        for(int i = size-1; i>0; i--) {
            if(sum > mid) {
                long long dif = sum - mid;
                sum = (long long)(nums[i-1])+dif; 
            }
            else {
                sum = nums[i-1];
            }
        }
        if(sum > mid) {
            return false;
        }
        return true;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int s = INT_MAX, e = INT_MIN;
        int size = nums.size();
        for(int i = 0; i<size; i++) {
            s = min(nums[i],s);
            e = max(nums[i],e);
        }
        int mid = s+(e-s)/2;
        while(s<e) {
            if(possible(mid,size,nums)) {
                e = mid;
            }
            else {
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return mid;
    }
};