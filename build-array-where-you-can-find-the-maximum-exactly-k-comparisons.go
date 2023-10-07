const MOD = 1000000007

func numOfArrays(n, m, k int) int {
	dp := make([][][]int, n)

	for i := range dp {
		dp[i] = make([][]int, m+1)
		for j := range dp[i] {
			dp[i][j] = make([]int, k+1)
		}
	}
	for j := 1; j <= m; j++ {
		dp[0][j][1] = 1
	}

	for i := 1; i < n; i++ {
		for pj := 1; pj <= m; pj++ {
			for cj := 1; cj <= m; cj++ {
				for l := 1; l <= k; l++ {
					if cj > pj && l == k {
						continue
					}

					addl := 0
					if cj > pj {
						addl = 1
					}
					cur := &dp[i][max(cj, pj)][l+addl]
					*cur = (*cur + dp[i-1][pj][l]) % MOD
				}
			}
		}
	}

	ans := 0
	for j := 1; j <= m; j++ {
		ans = (ans + dp[n-1][j][k]) % MOD
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
