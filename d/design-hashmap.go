type MyHashMap struct {
	data []int
}

func Constructor() MyHashMap {
	slice := make([]int, 1000001)
	for i := range slice {
		slice[i] = -1
	}
	return MyHashMap{data: slice}
}

func (this *MyHashMap) Put(key int, value int) {
	this.data[key] = value
}

func (this *MyHashMap) Get(key int) int {
	return this.data[key]
}

func (this *MyHashMap) Remove(key int) {
	this.data[key] = -1
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Put(key,value);
 * param_2 := obj.Get(key);
 * obj.Remove(key);
 */
