class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        visited = set()
        minH = [[grid[0][0],0,0]]
        directions = [[0,1],[0,-1],[1,0],[-1,0]]
        N = len(grid)
        visited.add((0,0))
        
        while minH:
            t, r, c = heapq.heappop(minH)

            if r == N-1 and c == N-1:
                return t

            for dr,dc in directions:
                newR, newC = r+dr, c+dc

                if newR < 0 or newC < 0 or newR > N-1 or newC > N-1 or (newR,newC) in visited:
                    continue

                visited.add((newR,newC))
                heapq.heappush(minH, [max(t, grid[newR][newC]), newR, newC])
        

