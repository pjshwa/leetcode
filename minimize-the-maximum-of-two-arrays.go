func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func max(a, b int64) int64 {
	if a >= b {
		return a
	}
	return b
}

func minimizeSet(divisor1 int, divisor2 int, uniqueCnt1 int, uniqueCnt2 int) int {
	low := int64(0)
	high := int64(3e9)

	// convert divisors to int64 to avoid overflow
	div1 := int64(divisor1)
	div2 := int64(divisor2)
	ucnt1 := int64(uniqueCnt1)
	ucnt2 := int64(uniqueCnt2)
	lcm := div1 * div2 / gcd(div1, div2)

	for low < high {
		mid := (low + high) / 2
		arr1OnlyCnt := mid/div2 - mid/lcm
		arr2OnlyCnt := mid/div1 - mid/lcm
		bothCnt := mid - mid/div1 - mid/div2 + mid/lcm

		arr1NeedCnt := max(ucnt1-arr1OnlyCnt, 0)
		arr2NeedCnt := max(ucnt2-arr2OnlyCnt, 0)

		if arr1NeedCnt+arr2NeedCnt <= bothCnt {
			high = mid
		} else {
			low = mid + 1
		}
	}

	return int(low)
}
