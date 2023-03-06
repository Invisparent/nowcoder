import java.util.Scanner;
import java.math.BigInteger;

public class Main {
public static void main(String[] args) {
        Scanner ivsScan = new Scanner(System.in);
        int n = ivsScan.nextInt();
        BigInteger res = new BigInteger("1");
        BigInteger i;
        BigInteger modNum = new BigInteger("10");
        BigInteger zero = new BigInteger("0");
        int zn = 0;
        for (int t = 0; t < n; ++t) {
            i = ivsScan.nextBigInteger();
            res = res.multiply(i);
            while (res.mod(modNum).equals(zero)) {
                ++zn;
                res = res.divide(modNum);
            }
        }
        while (res.mod(modNum).equals(zero)) {
            ++zn;
            res = res.divide(modNum);
        }

        String str = res.toString();
        if (str.length() >= 3)
            for (int t = 0; t < 3; ++t)
                System.out.print(str.charAt(t));
        else {
            System.out.print(str);
            for (int t = 3; t > str.length(); --t)
                System.out.print('0');
        }
        System.out.println();
        System.out.print(zn);
    }
}
