class Solution(object):
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        r = 0 #READ
        w = 0 #WRITE
        while r<len(chars) :
            ch = chars[r]
            count = 0
            while r<len(chars) and chars[r] == ch:
                r+=1
                count+=1
            chars[w]=ch
            w+=1
            if count > 1 : # we need to extract digits and add them
                for digit in str(count):
                    chars[w]=digit
                    w+=1

        return w