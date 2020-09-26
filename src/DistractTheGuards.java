import java.util.ArrayList;
import java.util.HashMap;

public class DistractTheGuards {
    static int n;
    static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }

    public static int checkLoop(long a, long b) {
        long g = gcd(a, b);
        a /= g; b /= g;
        long sum = (a + b);
        return Long.bitCount(sum) == 1 ? 0 : 1;
    }

    public static int solution(int[] banana_list) {
        n = banana_list.length;
        ArrayList<Integer>[] adj = new ArrayList[n];
        int[] sizes = new int[n];
        int[] vis = new int[n];

        for (int i=0;i<n;i++) adj[i] = new ArrayList<>();

        for (int i=0;i<n;i++)
            for (int j=i + 1;j<n;j++){
                if(i == j || banana_list[i] == banana_list[j] || checkLoop((long) banana_list[i], (long) banana_list[j]) == 0) continue;
                adj[i].add(j);
                adj[j].add(i);
            }

        for (int i=0;i<n;i++) {
            sizes[i] = adj[i].size();
            vis[i] = 0;
        }

        int pairs = 0;

        for (int i=0;i<n;i++) {
            int min_size = Integer.MAX_VALUE, ind = -1;
            for (int j=0;j<n;j++)
                if (vis[j] == 0 && sizes[j] < min_size) {
                    min_size = sizes[j];
                    ind = j;
                }
            if (ind == -1) break;
            vis[ind] = 1;

            int ind1 = ind;

            min_size = Integer.MAX_VALUE; ind = -1;
            for (int j=0;j<adj[ind1].size();j++) {
                if (vis[adj[ind1].get(j)] == 0 && sizes[adj[ind1].get(j)] < min_size) {
                    min_size = sizes[adj[ind1].get(j)];
                    ind = adj[ind1].get(j);
                }
            }

            for (int j=0;j<n;j++)
                if (adj[j].contains(ind1)) sizes[j]--;

            if (ind == -1) continue;
            vis[ind] = 1;
            pairs += 1;

            for (int j=0;j<n;j++)
                if (adj[j].contains(ind)) sizes[j]--;
        }

        return n - (2 * pairs);
    }

    public static void main(String[] args) {
        System.out.println(solution(new int[]{ 1, 7, 3, 21, 13, 19 }));
    }
}

/*
1, 1

1, 7, 3, 21, 13, 19
 */
