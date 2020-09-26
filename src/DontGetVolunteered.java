import java.util.Arrays;
        import java.util.HashMap;

public class DontGetVolunteered {
    static int[][] vis = new int[10][10];

    public static int solution(int src, int dest) {
        int src_x = src / 8, src_y = src % 8;
        int dest_x = dest / 8, dest_y = dest % 8;

        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                vis[i][j] = Integer.MAX_VALUE;

        dfs(src_x, src_y, 0);
        return vis[dest_x][dest_y];
    }

    static void dfs(int curr_x, int curr_y, int dist) {
        if(curr_x < 0 || curr_x > 7 || curr_y < 0 || curr_y > 7 || vis[curr_x][curr_y] <= dist) return;
        vis[curr_x][curr_y] = dist;

        dfs(curr_x + 1, curr_y + 2, dist + 1);
        dfs(curr_x + 2, curr_y + 1, dist + 1);
        dfs(curr_x - 1, curr_y + 2, dist + 1);
        dfs(curr_x - 2, curr_y + 1, dist + 1);
        dfs(curr_x + 1, curr_y - 2, dist + 1);
        dfs(curr_x + 2, curr_y - 1, dist + 1);
        dfs(curr_x - 1, curr_y - 2, dist + 1);
        dfs(curr_x - 2, curr_y - 1, dist + 1);
    }

    public static void main(String[] args) {
        System.out.println(solution(0, 1));
    }
}
