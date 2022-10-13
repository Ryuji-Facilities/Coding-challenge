package linearSearch

func linearSearch(data []int, target int) int {
	for index, v := range data {
		if v == target {
			return index
		}
	}
	return -1
}