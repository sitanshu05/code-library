 int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;

        if(target > nums[r])
            return nums.size();
        else if(target <= nums[l])
            return 0;

        while(r-l>0){
            mid = (r + l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[l]==target)
                return l;
            else if(nums[r]==target)
                return r;
            else if(nums[mid]>target)
                r = mid - 1;
            else 
                l = mid + 1;
        }

        if(nums[l] > target)
            return l;
        else 
            return l +1;
    }
