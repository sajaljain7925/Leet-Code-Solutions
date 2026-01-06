from collections import deque

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        q = deque([root])
        level = 1
        best_level = 1
        max_sum = float('-inf')

        while q:
            size = len(q)
            curr_sum = 0

            for _ in range(size):
                node = q.popleft()
                curr_sum += node.val

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

            if curr_sum > max_sum:
                max_sum = curr_sum
                best_level = level

            level += 1

        return best_level
