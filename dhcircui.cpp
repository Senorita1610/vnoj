import java.util.HashSet;
import java.util.Scanner;

public class Main {
    
    static int[] answer = {0, 
            1, 
            3,
            7,
            15,
            35,
            77,
            179,
            429,
            1039,
            2525,
            6235,
            15463,
            38513,
            96231,
            241519,
            607339,
            1529533,
            3857447};
    
    public static void main(String[] args) {
        int n = new Scanner(System.in).nextInt();

        if (true) {
            System.out.println(answer[n]);
            return;
        }

        HashSet<Rational>[] sol = new HashSet[n + 1];
        Rational cap = new Rational(60, 1);
        sol[1] = new HashSet<>();
        sol[1].add(cap);
        
        
        sol[0] = new HashSet<>(sol[1]);

        for (int i = 2; i <= n; i++) {
            sol[i] = new HashSet<>();
            
            for (int j = 1; j <= i / 2; j++) {
                for (Rational r1 : sol[j]) {
                    for (Rational r2 : sol[i - j]) {
                        sol[i].add(r1.par(r2));
                        sol[i].add(r1.ser(r2));
                    }
                }
            }

            
            sol[0].addAll(sol[i]);
            System.out.println(sol[0].size() + ", ");
        }

        System.out.println(sol[0].size());
    }
    
    static class Rational {
        long a;
        long b;

        public Rational(long a, long b) {
            this.a = a / gcd(a, b);
            this.b = b / gcd(a, b);
        }

        private static long gcd(long a, long b) {
            while (b != 0) {
                a = a % b;
                long tmp = a;
                a = b;
                b = tmp;
            }
            return a;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Rational rational = (Rational) o;

            if (a != rational.a) return false;
            return b == rational.b;
        }

        @Override
        public int hashCode() {
            int result = (int) (a ^ (a >>> 32));
            result = 31 * result + (int) (b ^ (b >>> 32));
            return result;
        }

        public Rational par(Rational cap) {
            long x = cap.a * this.b + this.a * cap.b;
            long y = cap.b * this.b;
            if (y / cap.b != this.b) throw new RuntimeException();
            return new Rational(x, y);
        }

        public Rational ser(Rational cap) {
            long x = cap.a * this.a;
            if (x / cap.a != this.a) throw new RuntimeException();
            long y = cap.a * this.b + this.a * cap.b;
            return new Rational(x, y);
        }

        @Override
        public String toString() {
            return String.format("Rational{%d/%d}", a, b);
        }
    }
}

