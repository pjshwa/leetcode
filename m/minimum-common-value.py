class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        s=set(nums1)
        for e in nums2:
            if e in s:
                return e
        return -1
        