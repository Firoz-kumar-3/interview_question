https://leetcode.com/problems/find-the-duplicate-number/

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one duplicate number in nums, return this duplicate number.

Follow-ups:

How can we prove that at least one duplicate number must exist in nums? 
Can you solve the problem without modifying the array nums?
Can you solve the problem using only constant, O(1) extra space?
Can you solve the problem with runtime complexity less than O(n2)?
 
 Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [1,1]
Output: 1
Example 4:

Input: nums = [1,1,2]
Output: 1
 

Constraints:

2 <= n <= 3 * 104
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.


 .// the array will get change here.
 
  int findDuplicate(vector<int>& nums) {
     int i;
      for( i=0;i<nums.size();i++)
      {
          if(nums[abs(nums[i])]<0)
          {
             return abs(nums[i]);
              
          }
          else
          {
              nums[abs(nums[i])]=-nums[abs(nums[i])];
          }
      }
 
   return 0;       
        
        
    }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
Approach 3: Floyd's Tortoise and Hare (Cycle Detection)





int findDuplicate(vector<int>& nums) {
   
        int slow=nums[0];
        int fast=nums[0];
        
        //pointing slow 2nd and and fast to 3rd,as min 3 element can be in the array n(no of element)>=2
        slow=nums[slow];
        fast=nums[nums[fast]];
        
        while(slow!=fast)
        {
             slow=nums[slow];
             fast=nums[nums[fast]];
        }
        slow=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
    return fast;
    }
