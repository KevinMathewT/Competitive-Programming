public class FindTheAccessCodes {
    public static int solution(int[] l) {
        int ret = 0;

        for (int i=1;i<l.length - 1;i++) {
            int c1 = 0, c2 = 0;
            for (int j=0;j<i;j++) if (l[i] % l[j] == 0) c1++;
            for (int j=i+1;j<l.length;j++) if(l[j] % l[i] == 0) c2++;

            ret += c1 * c2;
        }

        return ret;
    }

    public static void main(String[] args) {
        System.out.println(solution(new int[]{1, 1}));
    }
}
