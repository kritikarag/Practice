class NumArray:
    
    def lsb(self, i):
        return (i & -i)

    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.nums = [0] * self.n
        self.n_bit = self.n + 1
        self.bit = [0] * self.n_bit
        for i, v in enumerate(nums):
            self.update(i, v)

    def update(self, index: int, val: int) -> None:
        d = val - self.nums[index]
        if not d:
            return
        self.nums[index] = val
        index += 1
        index_copy = index
        while index < self.n_bit:
            self.bit[index] += d * index_copy
            index += self.lsb(index)
        
    def query(self, index):
        index += 1
        ret = 0
        while index:
            ret += self.bit[index]
            index -= self.lsb(index)
        return ret
        
    def sumRange(self, left: int, right: int) -> int:
        return self.query(right) - self.query(left - 1)