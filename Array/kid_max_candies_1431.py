class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        """
        :type candies: List[int]
        :type extraCandies: int
        :rtype: List[bool]
        """
        max_c = max(candies)
        return [x + extraCandies >= max_c for x in candies]
        # max_c = 0  
        # res = [False] * len(candies)    
        # for i in range(0,len(candies)):
        #     max_c = max(max_c,candies[i])

        # for i in range(0,len(candies)):
        #     if candies[i] + extraCandies >= max_c :
        #         res[i] = True
        #     else:
        #         res[i] = False
        # return res
        