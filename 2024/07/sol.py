from sys import stdin


def chk(tar, nums):
    n = len(nums)

    for i in range(2**(n - 1)):
        cur = nums[0]
        b = i

        for j in range(1, n):
            if b % 2 == 0:
                cur += nums[j]
            else:
                cur *= nums[j]

            if cur > tar:
                break

            b //= 2

        if cur == tar:
            return True

    return False


def chk2(tar, nums):
    n = len(nums)

    for i in range(3**(n - 1)):
        cur = nums[0]
        b = i

        for j in range(1, n):
            if b % 3 == 0:
                cur += nums[j]
            elif b % 3 == 1:
                cur *= nums[j]
            else:
                cur = int(str(cur) + str(nums[j]))

            if cur > tar:
                break

            b //= 3

        if cur == tar:
            return True

    return False


res = 0
res2 = 0

for s in stdin:
    tar, nums = s.strip().split(": ")
    tar = int(tar)
    nums = list(map(int, nums.split(" ")))

    if chk(tar, nums):
        res += tar
    elif chk2(tar, nums):
        res2 += tar

print(res)
print(res + res2)
