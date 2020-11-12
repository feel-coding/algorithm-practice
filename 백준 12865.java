import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int maxWeight = in.nextInt();
        int[] weight = new int[n];
        int[] value = new int[n];
        for (int i = 0; i < 2 * n; i++) {
            if(i % 2 == 0) weight[i / 2] = in.nextInt();
            else value[i / 2] = in.nextInt();
        }
        int[][] arr = new int[n + 1][maxWeight + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= maxWeight; j++) {
                if (i == 0 || j == 0) {
                    arr[i][j] = 0;
                } else if (weight[i - 1] <= j) {
                    arr[i][j] = Integer.max(arr[i - 1][j], value[i - 1] + arr[i - 1][j - weight[i - 1]]);
                }
                else {
                    arr[i][j] = arr[i - 1][j];
                }
//                System.out.print(arr[i][j] + " ");
            }
//            System.out.println();
        }
        System.out.println(arr[n][maxWeight]);
    }
}
