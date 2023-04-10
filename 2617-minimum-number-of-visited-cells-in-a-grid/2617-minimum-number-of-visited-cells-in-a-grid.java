class Solution {
    public int minimumVisitedCells(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] dist = new int[m][n];
        for (int[] row : dist) 
            Arrays.fill(row, Integer.MAX_VALUE);
        dist[0][0] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        pq.offer(new int[] {0, 0, 0});
        
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int i = curr[0], j = curr[1], steps = curr[2];
            if (i == m-1 && j == n-1) 
                return steps+1;
            if (dist[i][j] < steps) 
                continue;
            for (int k = 1; k <= grid[i][j]; k++) 
            {
                int x = i + k, y = j;
                if (x < m && dist[x][y] > steps + 1) 
                {
                    dist[x][y] = steps + 1;
                    pq.offer(new int[] {x, y, steps + 1});
                }
                x = i; y = j + k;
                if (y < n && dist[x][y] > steps + 1) 
                {
                    dist[x][y] = steps + 1;
                    pq.offer(new int[] {x, y, steps + 1});
                }
            }
        }
        
        return -1;
    }
}