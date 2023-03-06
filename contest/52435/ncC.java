import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner ivsScan = new Scanner(System.in);
        int n = ivsScan.nextInt();
        BigInteger p = ivsScan.nextBigInteger();
        BigInteger res1 = new BigInteger("2");
        res1 = res1.pow(n);
        BigInteger res2 = new BigInteger("2");
        res2 = res2.modPow(res1, p);
        System.out.println(res2);
    }
}
