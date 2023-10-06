func majorityElement(nums []int) []int {
	// Boyer-Moore Majority Vote algorithm
	// https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html

	var (
		majority1, majority2 int
		count1, count2       int
	)

	for _, num := range nums {
		if num == majority1 {
			count1++
		} else if num == majority2 {
			count2++
		} else if count1 == 0 {
			majority1 = num
			count1 = 1
		} else if count2 == 0 {
			majority2 = num
			count2 = 1
		} else {
			count1--
			count2--
		}
	}

	count1 = 0
	count2 = 0
	for _, num := range nums {
		if num == majority1 {
			count1++
		} else if num == majority2 {
			count2++
		}
	}

	var result []int
	if count1 > len(nums)/3 {
		result = append(result, majority1)
	}
	if count2 > len(nums)/3 {
		result = append(result, majority2)
	}

	return result
}
