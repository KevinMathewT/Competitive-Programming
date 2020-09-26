import java.util.Arrays;

public class IonFluxRelabeling {
    public static int[] solution(int h, int[] q) {
        int root = (1 << h) - 1;
        int[] ret = new int[q.length];
        int pos = 0;
        for (int value : q) ret[pos++] = getParent(value, 1, root, -1);
        return ret;
    }

    static int getParent(int search, int low, int current, int parent) {
        if (search == current) return parent;
        int mid = (low + current) / 2;
        if (search < mid) return getParent(search, low, mid - 1, current);
        else return getParent(search, mid, current - 1, current);
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(solution(5, new int[]{19, 14, 28})));
        System.out.println(Arrays.toString(solution(3, new int[]{7, 3, 5, 1})));
    }
}