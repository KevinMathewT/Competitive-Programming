package com.company;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;

public class DoomsdayFuel {
    static BigInteger det;

    public static BigInteger gcd(BigInteger a, BigInteger b) { return b.equals(BigInteger.ZERO) ? a : gcd(b, a.mod(b)); }

    public static BigInteger[][] multiply(BigInteger[][] A, BigInteger[][] B) {
        BigInteger[][] ret = new BigInteger[A.length][B[0].length];
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < B[0].length; j++) {
                ret[i][j] = BigInteger.ZERO;
                for (int k = 0; k < A[0].length; k++)
                    ret[i][j] = ret[i][j].add(A[i][k].multiply(B[k][j]));
            }
        }

        return ret;
    }

    public static BigInteger[][] multiplyWithConstant(BigInteger[][] A, BigInteger x) {
        BigInteger[][] ret = new BigInteger[A.length][A[0].length];
        for (int i = 0; i < A.length; i++)
            for (int j = 0; j < A[0].length; j++)
                ret[i][j] = A[i][j].multiply(x);

        return ret;
    }

    public  static BigInteger[][] minor(BigInteger[][] matrix, long row, long column) {
        BigInteger[][] minor = new BigInteger[matrix.length - 1][matrix.length - 1];

        for (int i = 0; i < matrix.length; i++)
            for (int j = 0; i != row && j < matrix[i].length; j++)
                if (j != column)
                    minor[i < row ? i : i - 1][j < column ? j : j - 1] = matrix[i][j];
        return minor;
    }

    public static BigInteger determinant(BigInteger[][] matrix) {
        if (matrix.length == 1) return matrix[0][0];
        if (matrix.length == 2)
            return matrix[0][0].multiply(matrix[1][1]).subtract(matrix[0][1].multiply(matrix[1][0]));

        BigInteger det = BigInteger.ZERO;
        for (int i = 0; i < matrix[0].length; i++)
            det = det.add(BigInteger.valueOf((long) Math.pow(-1, i)).multiply(matrix[0][i].multiply(determinant(minor(matrix, 0, i)))));
        return det;
    }

    public static BigInteger[][] inverse(BigInteger[][] matrix) {
        BigInteger[][] inverse = new BigInteger[matrix.length][matrix.length];
        if (matrix.length == 1) {
            det = matrix[0][0];
            inverse[0][0] = BigInteger.ONE;
            return inverse;
        }

        for (int i = 0; i < matrix.length; i++)
            for (int j = 0; j < matrix[i].length; j++)
                inverse[i][j] = (BigInteger.valueOf((long)Math.pow(-1, i + j))).multiply(determinant(minor(matrix, i, j)));

        det = determinant(matrix);
        for (int i = 0; i < inverse.length; i++) {
            for (int j = 0; j <= i; j++) {
                BigInteger temp = inverse[i][j];
                inverse[i][j] = inverse[j][i];
                inverse[j][i] = temp;
            }
        }

        return inverse;
    }

    public static BigInteger[][] getIdentity(int n, BigInteger id) {
        BigInteger[][] ret = new BigInteger[n][n];
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (i == j) ret[i][i] = id;
                else ret[i][j] = BigInteger.ZERO;

        return ret;
    }

    public static BigInteger[][] subtract(BigInteger[][] A, BigInteger[][] B) {
        BigInteger[][] ret = new BigInteger[A.length][A[0].length];
        for (int i=0;i<A.length;i++)
            for (int j=0;j<A[0].length;j++)
                ret[i][j] = A[i][j].subtract(B[i][j]);

        return ret;
    }

    public static int[] solution(int[][] m) {
        int n = m.length;

        ArrayList<Integer> terminals = new ArrayList<>();
        ArrayList<Integer> non_terminals = new ArrayList<>();

        for (int i=0;i<n;i++) {
            int flag = 1;
            for (int j=0;j<n;j++) {
                if (i == j) continue;
                if (m[i][j] != 0) {
                    flag = 0;
                    break;
                }
            }

            if (flag == 1) {
                terminals.add(i);
                m[i][i] = 1;
            } else {
                non_terminals.add(i);
            }
        }

        if (terminals.get(0) == 0) {
            int[] ret = new int[terminals.size() + 1];
            ret[0] = 1;
            ret[terminals.size()] = 1;
            return ret;
        }

        ArrayList<BigInteger> sums = new ArrayList<>();

        BigInteger g = BigInteger.ONE;
        for (int[] BigIntegers : m) {
            BigInteger sum = BigInteger.ZERO;
            for (int j = 0; j < n; j++) sum = sum.add(BigInteger.valueOf(BigIntegers[j]));
            g = g.multiply(sum.divide(gcd(g, sum)));
            sums.add(sum);
        }

        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                m[i][j] *= g.divide(sums.get(i)).intValue();

        ArrayList<Integer> ordered = new ArrayList<>();
        ordered.addAll(terminals);
        ordered.addAll(non_terminals);

        BigInteger[][] A = new BigInteger[n][n];

        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                A[i][j] = BigInteger.valueOf(m[ordered.get(i)][ordered.get(j)]);

        int num_terminals = terminals.size(), num_non_terminals = non_terminals.size();
        BigInteger[][] Q = new BigInteger[num_non_terminals][num_non_terminals];
        for (int i=n-num_non_terminals;i<n;i++)
            for (int j=n-num_non_terminals;j<n;j++)
                Q[i - (n - num_non_terminals)][j - (n - num_non_terminals)] = A[i][j];

        BigInteger[][] R = new BigInteger[num_non_terminals][num_terminals];
        for (int i=n-num_non_terminals;i<n;i++)
            for (int j=0;j<n-num_non_terminals;j++)
                R[i - (n - num_non_terminals)][j] = A[i][j];

        BigInteger[][] F = multiplyWithConstant(inverse(subtract(getIdentity(num_non_terminals, g), Q)), g);
        BigInteger[][] FR = multiply(F, R);


        int[] ret = new int[num_terminals + 1];

        BigInteger[] imp = FR[0];

        ArrayList<BigInteger> non_zeros = new ArrayList<>();

        for (int i=0;i<num_terminals;i++)
            if(!imp[i].equals(BigInteger.ZERO))
                non_zeros.add(imp[i]);

        BigInteger g2 = non_zeros.get(0);
        for (int i=1;i<non_zeros.size();i++)
            g2 = gcd(g2, non_zeros.get(i));

        for (int i=0;i<num_terminals;i++)
            imp[i] = imp[i].divide(g2);
        BigInteger sum = BigInteger.ZERO;

        for (int i=0;i<num_terminals;i++) {
            sum = sum.add(imp[i]);
            ret[i] = imp[i].intValue();
        }

        ret[num_terminals] = sum.intValue();
        return ret;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(solution(new int[][]{
                {0, 86, 61, 189, 0, 18, 12, 33, 66, 39},
                {0, 0, 2, 0, 0, 1, 0, 0, 0, 0},
                {15, 187, 0, 0, 18, 23, 0, 0, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        })));
    }
}

/*
                {0, 7, 0, 17, 0, 1, 0, 5, 0, 2},
                {0, 0, 29, 0, 28, 0, 3, 0, 16, 0},
                {0, 3, 0, 0, 0, 1, 0, 0, 0, 0},
                {48, 0, 3, 0, 0, 0, 17, 0, 0, 0},
                {0, 6, 0, 0, 0, 1, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

                {0, 2, 1, 0, 0},
                {0, 0, 0, 3, 4},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0,0},
                {0, 0, 0, 0, 0}

                {0, 86, 61, 189, 0, 18, 12, 33, 66, 39},
                {0, 0, 2, 0, 0, 1, 0, 0, 0, 0},
                {15, 187, 0, 0, 18, 23, 0, 0, 0, 0},
                {48, 0, 3, 0, 0, 0, 17, 0, 0, 0},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
 */