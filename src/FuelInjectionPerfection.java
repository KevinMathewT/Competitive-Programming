import java.math.BigInteger;

public class FuelInjectionPerfection {
    public static int solution(String x) {
        BigInteger n = new BigInteger(x);
        int steps = 0;
        while (n.compareTo(BigInteger.ONE) > 0) {
//            System.out.print(" -> " + n);
            steps++;
            if (n.mod(BigInteger.TWO).compareTo(BigInteger.ZERO) == 0) {
                n = n.divide(BigInteger.TWO);
                continue;
            }

            if(n.compareTo(BigInteger.ONE.add(BigInteger.TWO)) == 0) {
                steps += 1;
                return steps;
            }

            int modval = n.mod(BigInteger.valueOf((long) 4)).intValue();
            if (modval == 3) n = n.add(BigInteger.ONE);
            else n = n.subtract(BigInteger.ONE);
        }
        return steps;
    }

    public static void main(String[] args) {
            System.out.println(solution("100000000000000000000000000000000000000000000000000"));
    }
}
