// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int slow = 0, fast = 0;
//         while (true) {
//             slow = nums[slow];
//             fast = nums[nums[fast]];
//             if (slow == fast) {
//                 break;
//             }
//         }

//         int slow2 = 0;
//         while (true) {
//             slow = nums[slow];
//             slow2 = nums[slow2];
//             if (slow == slow2) {
//                 return slow;
//             }
//         }
//     }
// };


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]);

            if (nums[index] < 0) {
                return index;
            }

            nums[index] = -nums[index];
        }

        return -1;
    }
};
