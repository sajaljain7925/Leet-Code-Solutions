class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        MOD = 10**9 + 7
        self.best = 0

        def total_sum(node):
            if not node:
                return 0
            return node.val + total_sum(node.left) + total_sum(node.right)

        S = total_sum(root)

        def dfs(node):
            if not node:
                return 0
            left = dfs(node.left)
            right = dfs(node.right)
            curr = node.val + left + right
            self.best = max(self.best, curr * (S - curr))
            return curr

        dfs(root)
        return self.best % MOD
