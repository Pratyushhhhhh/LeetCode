class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        num1 = float('inf') #sys.maxsize
        num2 = float('inf')
        for i in range(len(nums)):
            num3 = nums[i]
            if num3 <= num1:
                num1=num3
            elif num3 <= num2:
                num2=num3
            else:
                return True
        return False
        