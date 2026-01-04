class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        def is_prime(x: int) -> bool:
            if x < 2:
                return False
            i = 2
            while i * i <= x:
                if x % i == 0:
                    return False
                i += 1
            return True

        ans = 0

        for n in nums:
            p = -1
            i = 2
            while i * i <= n:
                if n % i == 0:
                    p = i
                    break
                i += 1

            if p == -1:
                continue

            q = n // p

            if q == p * p and is_prime(p):
                ans += 1 + p + p * p + n
            elif p != q and is_prime(p) and is_prime(q):
                ans += 1 + p + q + n

        return ans
