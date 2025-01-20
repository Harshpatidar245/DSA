isme array ke andar se ek sigle element hai usko dhundna hai or isme dusre elements sare duble hai or ek hi single hai


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases:
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];
        
        // Binary search:
        int low = 0;
        int high = n - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;

            // Check if `mid` is the single element:
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // Decide which half to search:
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || 
                (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                low = mid + 1; // Single element is in the right half
            } else {
                high = mid - 1; // Single element is in the left half
            }
        }
        
        return nums[low]; // `low` points to the single element
    }
};
