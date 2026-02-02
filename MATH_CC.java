import java.util.*;

public class ExtremeBruteToolkit {

    /* -------------------------------------------------
       1. COUNT PRIMES (EXTREME BRUTE)  O(n^2)
    ------------------------------------------------- */
    static boolean isPrime(int x) {
        if (x < 2) return false;

        for (int i = 2; i < x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    static int countPrimes(int n) {
        int count = 0;

        for (int i = 2; i <= n; i++) {
            if (isPrime(i))
                count++;
        }
        return count;
    }


    /* -------------------------------------------------
       2. PRIME FACTORIZATION (EXTREME BRUTE)  O(n)
    ------------------------------------------------- */
    static void primeFactors(int n) {

        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                System.out.print(i + " ");
                n /= i;
            }
        }
    }


    /* -------------------------------------------------
       3. EULER PHI (EXTREME BRUTE using GCD) O(n log n)
    ------------------------------------------------- */
    static int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    static int phi(int n) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (gcd(n, i) == 1)
                count++;
        }
        return count;
    }


    /* -------------------------------------------------
       4. LARGEST POWER IN n! (BRUTE LOOP) O(n log n)
    ------------------------------------------------- */
    static int largestPower(int n, int p) {

        int count = 0;

        for (int i = 1; i <= n; i++) {
            int temp = i;

            while (temp % p == 0) {
                count++;
                temp /= p;
            }
        }

        return count;
    }


    /* -------------------------------------------------
       5. CRT (EXTREME BRUTE FORCE) VERY SLOW
    ------------------------------------------------- */
    static int crtBrute(int[] num, int[] rem, int k) {

        int x = 1;

        while (true) {

            boolean ok = true;

            for (int i = 0; i < k; i++) {
                if (x % num[i] != rem[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) return x;

            x++;
        }
    }
