func integerBreakRecursive(n int) int {
	if n <= 4 {
		return n
	}
	return 3 * integerBreakRecursive(n-3)
}

func integerBreak(n int) int {
	if n <= 3 {
		return n - 1
	}
	return integerBreakRecursive(n)
}
