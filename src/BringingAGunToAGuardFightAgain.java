import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class BringingAGunToAGuardFightAgain {
    static class Triple<T1, T2, T3> {
        T1 x;
        T2 y;
        T3 d;

        Triple(T1 x, T2 y, T3 d) {
            this.x = x;
            this.y = y;
            this.d = d;
        }
    }

    static class Pair<T1, T2> {
        T1 x;
        T2 y;

        Pair(T1 x, T2 y) {
            this.x = x;
            this.y = y;
        }
    }

    static long dist, wall_x, wall_y, self_x, self_y, enemy_x, enemy_y;
    static long getDist(long x, long y) { return ((x - self_x) * (x - self_x) + (y - self_y) * (y - self_y)); }
    static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }

    public static ArrayList<Triple<Long, Long, Long>> getAllMirrors(long x, long y) {
        ArrayList<Triple<Long, Long, Long>> MirrorPoints = new ArrayList<>();
        long diffx1 = 2 * x;
        long diffx2 = 2 * (wall_x - x);
        long diffy1 = 2 * y;
        long diffy2 = 2 * (wall_y - y);

        long leftx = x - diffx1, lefty = y;
        long i = 1;

        while(getDist(leftx, lefty) <= (dist * dist)) {
            MirrorPoints.add(new Triple<>(leftx, lefty, getDist(leftx, lefty)));
            if (i % 2 == 0) leftx -= diffx1;
            else leftx -= diffx2;
            i++;
        }

        MirrorPoints.add(new Triple<>(x, y, 0L));
        Collections.reverse(MirrorPoints);

        long rightx = x + diffx2, righty = y;
        i = 1;

        while(getDist(rightx, righty) <= (dist * dist)) {
            MirrorPoints.add(new Triple<>(rightx, righty, getDist(rightx, righty)));
            if (i % 2 == 0) rightx += diffx2;
            else rightx += diffx1;
            i++;
        }

//        for (Triple<Long, Long, Long> triple : MirrorPoints)
//            System.out.print("(" + triple.x + ", " + triple.y + ", " + triple.d + ") ");
//        System.out.println();

        ArrayList<Triple<Long, Long, Long>> MirrorPointsInY = new ArrayList<>();

        System.out.println(MirrorPoints.size());
        System.out.println(MirrorPointsInY.size());

        for (Triple<Long, Long, Long> t : MirrorPoints) {
            long downx = t.x, downy = t.y - diffy1;
            i = 1;

            while(getDist(downx, downy) <= (dist * dist)) {
                MirrorPointsInY.add(new Triple<>(downx, downy, getDist(downx, downy)));
                if (i % 2 == 0) downy -= diffy1;
                else downy -= diffy2;
                i++;
            }

            long upx = t.x, upy = t.y + diffy2;
            i = 1;
//            System.out.println(MirrorPointsInY.size());

            while(getDist(upx, upy) <= (dist * dist)) {
                MirrorPointsInY.add(new Triple<>(upx, upy, getDist(upx, upy)));
                if (i % 2 == 0) upy += diffy2;
                else upy += diffy1;
                if (true) {
                    System.out.println(upx + " " + upy + " " + getDist(upx, upy));
                }
                i++;
            }
        }
//

        MirrorPoints.addAll(MirrorPointsInY);
        return MirrorPoints;
    }

    public static int solution(int[] dimensions, int[] your_position, int[] guard_position, int distance){
        //Your code here
        dist = distance;
        wall_x = dimensions[0];
        wall_y = dimensions[1];
        self_x = your_position[0];
        self_y = your_position[1];
        enemy_x = guard_position[0];
        enemy_y = guard_position[1];

        ArrayList<Triple<Long, Long, Long>> selfMirrorPoints = getAllMirrors(self_x, self_y);
        ArrayList<Triple<Long, Long, Long>> enemyMirrorPoints = getAllMirrors(enemy_x, enemy_y);

        System.out.println();
        for (Triple<Long, Long, Long> triple : enemyMirrorPoints)
            System.out.println("(" + triple.x + ", " + triple.y + ", " + triple.d + ") ");
        System.out.println();

        HashMap<Long, HashMap<Long, Long>> M = new HashMap<>();
        HashMap<Long, HashMap<Long, Long> > V = new HashMap<>();

        for (Triple<Long, Long, Long> triple : selfMirrorPoints) {
            long x = triple.x - self_x;
            long y = triple.y - self_y;
            long g = gcd(Math.abs(x), Math.abs(y));
            if (g == 0) {
//                System.out.print("(" + triple.x + ", " + triple.y + ", " + triple.d + ") ");
                continue;
            }
            x = x / g;
            y = y / g;
            if (!M.containsKey(x)) M.put(x, new HashMap<>());
            if (!M.get(x).containsKey(y)) M.get(x).put(y, getDist(triple.x, triple.y));
            else M.get(x).put(y, Math.min(M.get(x).get(y), getDist(triple.x, triple.y)));
        }

//        System.out.println();
//        for (Triple<Long, Long, Long> triple : selfMirrorPoints)
//            System.out.print("(" + triple.x + ", " + triple.y + ", " + triple.d + ") ");
//        System.out.println();
//
        int poss = enemyMirrorPoints.size();
//
        for (Triple<Long, Long, Long> triple : enemyMirrorPoints) {
            long x = triple.x - self_x;
            long y = triple.y - self_y;
            long g = gcd(Math.abs(x), Math.abs(y));
            if (g == 0) {
//                System.out.print("(" + triple.x + ", " + triple.y + ", " + triple.d + ") ");
                continue;
            }
            x = x / g;
            y = y / g;


            if (V.containsKey(x) && V.get(x).containsKey(y)) {
                poss--;
                continue;
            }

            if (!M.containsKey(x)) M.put(x, new HashMap<>());
            if (!M.get(x).containsKey(y)) {
                M.get(x).put(y, getDist(triple.x, triple.y));
                if (!V.containsKey(x)) V.put(x, new HashMap<>());
                V.get(x).put(y, 1L);
            }
            else {
                if (M.get(x).get(y) < getDist(triple.x, triple.y)) poss--;
                else {
                    if (!V.containsKey(x)) V.put(x, new HashMap<>());
                    V.get(x).put(y, 1L);
                }
                M.get(x).put(y, Math.min(M.get(x).get(y), getDist(triple.x, triple.y)));

            }
        }

        System.out.println(selfMirrorPoints.size());
        System.out.println(enemyMirrorPoints.size());

        return poss;
    }

    public static void main(String[] args) {
        System.out.println(solution(new int[]{23, 10}, new int[]{6, 4}, new int[]{3, 2}, 23));
    }
}

/*
new int[]{3, 2}, new int[]{1, 1}, new int[]{2, 1}, 4
new int[]{300, 275}, new int[]{150, 150}, new int[]{185, 100}, 500
new int[]{42, 59}, new int[]{34, 44}, new int[]{6, 34}, 5000
new int[]{2, 5}, new int[]{1, 2}, new int[]{1, 4}, 11
new int[]{10, 10}, new int[]{4, 4}, new int[]{3, 3}, 5000
new int[]{23, 10}, new int[]{6, 4}, new int[]{3, 2}, 23
new int[]{2, 5}, new int[]{1, 2}, new int[]{1, 4}, 11
 */