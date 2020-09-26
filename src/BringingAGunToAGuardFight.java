import java.util.ArrayList;
import java.util.HashMap;

public class BringingAGunToAGuardFight {
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

    public static int poss = 0;
    public static long dist, wall_x, wall_y, self_x, self_y, enemy_x, enemy_y;
    public static HashMap<Long, HashMap<Long, Long>> M = new HashMap<>();
    public static ArrayList<Triple<Long, Long, Long>> MirrorPoints = new ArrayList<>();
    public static ArrayList<Triple<Long, Long, Long>> selfMirrorPoints = new ArrayList<>();
    public static ArrayList<Triple<Long, Long, Long>> enemyMirrorPoints = new ArrayList<>();

    static class IncreaseStackSize implements Runnable {

        public static long gcd(long a, long b) {
            return b == 0 ? a : gcd(b, a % b);
        }

        private static long getDistance(long vect_x, long vect_y) {
            return vect_x * vect_x + vect_y * vect_y;
        }


        public static void getAllPoints(long vect_x, long vect_y, long prev_dim) {
            long x = vect_x - self_x, y = vect_y - self_y;
            //        System.out.println(x + " " + y);
            long g = gcd(Math.abs(x), Math.abs(y));
            if (g != 0) {
                x /= g;
                y /= g;
            }

            if (getDistance(vect_x - self_x, vect_y - self_y) > ((dist * dist))) return;
            if (M.containsKey(x) && M.get(x).containsKey(y)) return;

            if (!M.containsKey(x)) M.put(x, new HashMap<>());
            M.get(x).put(y, getDistance(vect_x - self_x, vect_y - self_y));
            //        System.out.println(vect_x + " " + vect_y + " " + x + " " + y + " " + M.get(x).get(y));
            MirrorPoints.add(new Triple<>(x, y, M.get(x).get(y)));


            if (prev_dim != 0) {
                x = vect_x;
                y = vect_y;

                long diff = y;
                y -= 2 * diff;

                long x1 = x - self_x, y1 = y - self_y;
                g = gcd(Math.abs(x1), Math.abs(y1));
                if (g != 0) {
                    x1 /= g;
                    y1 /= g;
                }
                if (!(getDistance(x - self_x, y - self_y) > ((dist * dist))) && !(M.containsKey(x1) && M.get(x1).containsKey(y1)))
                    getAllPoints(x, y, 0);
            }

            if (prev_dim != 1) {
                x = vect_x;
                y = vect_y;

                long diff = x;
                x -= 2 * diff;

                long x1 = x - self_x, y1 = y - self_y;
                g = gcd(Math.abs(x1), Math.abs(y1));
                if (g != 0) {
                    x1 /= g;
                    y1 /= g;
                }
                if (!(getDistance(x - self_x, y - self_y) > ((dist * dist))) && !(M.containsKey(x1) && M.get(x1).containsKey(y1)))
                    getAllPoints(x, y, 1);
            }

            if (prev_dim != 2) {
                x = vect_x;
                y = vect_y;

                long diff = wall_y - y;
                y += 2 * diff;

                long x1 = x - self_x, y1 = y - self_y;
                g = gcd(Math.abs(x1), Math.abs(y1));
                if (g != 0) {
                    x1 /= g;
                    y1 /= g;
                }
                if (!(getDistance(x - self_x, y - self_y) > ((dist * dist))) && !(M.containsKey(x1) && M.get(x1).containsKey(y1)))
                    getAllPoints(x, y, 2);
            }

            if (prev_dim != 3) {
                x = vect_x;
                y = vect_y;

                long diff = wall_x - x;
                x += 2 * diff;

                long x1 = x - self_x, y1 = y - self_y;
                g = gcd(Math.abs(x1), Math.abs(y1));
                if (g != 0) {
                    x1 /= g;
                    y1 /= g;
                }
                if (!(getDistance(x - self_x, y - self_y) > ((dist * dist))) && !(M.containsKey(x1) && M.get(x1).containsKey(y1)))
                    getAllPoints(x, y, 3);
            }
        }

        public void run() {
            getAllPoints(self_x, self_y, -1);
            selfMirrorPoints = (ArrayList<Triple<Long, Long, Long>>) MirrorPoints.clone();
            MirrorPoints.clear();
            M.clear();

            getAllPoints(enemy_x, enemy_y, -1);
            ArrayList<Triple<Long, Long, Long>> enemyMirrorPoints = new ArrayList<>();
            enemyMirrorPoints = (ArrayList<Triple<Long, Long, Long>>) MirrorPoints.clone();
            MirrorPoints.clear();
            M.clear();

//        for(Triple<Long, Long, Long> self : selfMirrorPoints)
//            System.out.print("(" + self.x + " " + self.y + " " + self.d + ")");
//        System.out.println();
//
//        for(Triple<Long, Long, Long> enemy : enemyMirrorPoints)
//            System.out.print("(" + enemy.x + " " + enemy.y + " " + enemy.d + ") ");
//        System.out.println();


            poss = enemyMirrorPoints.size();

            for(Triple<Long, Long, Long> enemy : enemyMirrorPoints)
                for(Triple<Long, Long, Long> self : selfMirrorPoints)
                    if (enemy.x.equals(self.x) && enemy.y.equals(self.y) && enemy.d > self.d) {
                        poss--;
                        break;
                    }
        }
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

        Thread th = new Thread(null, new IncreaseStackSize(), "whatever", 1<<26);
        th.start();
        try {
            th.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return poss;
    }

    public static void main(String[] args) {
        System.out.println(solution(new int[]{10, 10}, new int[]{4, 4}, new int[]{3, 3}, 5000));
    }
}

/*
new int[]{3, 2}, new int[]{1, 1}, new int[]{2, 1}, 4
new int[]{300, 275}, new int[]{150, 150}, new int[]{185, 100}, 500
new int[]{42, 59}, new int[]{34, 44}, new int[]{6, 34}, 5000
new int[]{2, 5}, new int[]{1, 2}, new int[]{1, 4}, 11
new int[]{10, 10}, new int[]{4, 4}, new int[]{3, 3}, 5000
new int[]{10, 10}, new int[]{4, 4}, new int[]{3, 3}, 1000
 */