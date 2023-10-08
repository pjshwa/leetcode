func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func maxDotProduct(nums1 []int, nums2 []int) int {
	n, m := len(nums1), len(nums2)

	nums1AllNeg, nums1AllPos, nums1Max, nums1Min := true, true, nums1[0], nums1[0]
	for _, v := range nums1 {
		if v > 0 {
			nums1AllNeg = false
		}
		if v < 0 {
			nums1AllPos = false
		}
		nums1Max = max(nums1Max, v)
		nums1Min = min(nums1Min, v)
	}

	nums2AllNeg, nums2AllPos, nums2Max, nums2Min := true, true, nums2[0], nums2[0]
	for _, v := range nums2 {
		if v > 0 {
			nums2AllNeg = false
		}
		if v < 0 {
			nums2AllPos = false
		}
		nums2Max = max(nums2Max, v)
		nums2Min = min(nums2Min, v)
	}

	if nums1AllNeg && nums2AllPos {
		return nums1Max * nums2Min
	}
	if nums1AllPos && nums2AllNeg {
		return nums1Min * nums2Max
	}

	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, m+1)
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			dp[i][j] = max(dp[i][j], dp[i-1][j-1]+nums1[i-1]*nums2[j-1])
		}
	}

	return dp[n][m]
}
