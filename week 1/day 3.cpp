QUES 1 MOVE ZEROES
class Solution {
public:
    void moveZeroes(vector<int>& nums) { int j=-1;
    for( int i=0;i<nums.size();i++){
        if(nums[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) return;
    for( int i=j+1;i<nums.size();i++){
        if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
    }
        
    }
};
QUES 2 SQUARE OF SORTED ARRAY
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int left = 0, right = n - 1;
        int pos = n - 1;

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[pos] = nums[left] * nums[left];
                left++;
            } else {
                result[pos] = nums[right] * nums[right];
                right--;
            }
            pos--;
        }

        return result;
    }
};
QUES 3 CONTAINER WITH MOST WATER
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int h = min(height[left], height[right]);

            maxWater = max(maxWater, width * h);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};
