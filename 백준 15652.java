import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = "";
        StringBuilder sb = new StringBuilder();
        try {
            s = br.readLine();
        } catch (IOException e) {}
        StringTokenizer st = new StringTokenizer(s);
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] result = new int[m];
        permutationWithRepetition(n, m, 0, result, sb);
        System.out.println(sb);
    }
    static void permutationWithRepetition(int n, int m, int num, int[] result, StringBuilder sb) {
        if (num == m) {
            for (int i = 0; i < m; i++) {
                sb.append(result[i] + " ");
            }
            sb.append("\n");
            return;
        }
        for (int i = 0; i < n; i++) {
            if(num != 0 && result[num - 1] > i + 1)
                continue;
            else {
                result[num] = i + 1;
                permutationWithRepetition(n, m, num + 1, result, sb);
            }
        }
    }
}
