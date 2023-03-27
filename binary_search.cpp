int search(vector<int>& nums, int target) {

        int l = 0,r = nums.size()-1;
        int mid;

        while(r-l>=0){
            mid = (l+r)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[r]==target)
                return r;
            else if(nums[l]==target)
                return l;
            else if(nums[mid]>target)
                r = mid -1;
            else 
                l = mid + 1;
        }

        return -1;
        
    }

void main(){
  
  
}
