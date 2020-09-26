import java.util.Arrays;
import java.util.HashMap;

public class PrisonLaborDodgers {
    public static int solution(int[] x, int[] y) {
        int sum = 0;
        for (int value : x) sum += value;
        for (int value : y) sum -= value;

        return x.length > y.length ? sum : -sum;
    }

    public static void main(String[] args) {
        System.out.println(solution(new int[]{13, 5, 6, 2, 5}, new int[]{5, 2, 5, 13}));
    }
}