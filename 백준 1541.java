import java.awt.datatransfer.StringSelection;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        StringTokenizer st = new StringTokenizer(s, "-");
        ArrayList<Integer> list = new ArrayList<>();
        while (st.hasMoreTokens()) {
            String next = st.nextToken();
            if(next.contains("+")) {
                StringTokenizer tokenizer = new StringTokenizer(next, "+");
                int sum = 0;
                while (tokenizer.hasMoreTokens()) {
                    sum += Integer.parseInt(tokenizer.nextToken());
                }
                list.add(sum);
            }
            else {
                list.add(Integer.parseInt(next));
            }
        }
        int result = list.get(0);
        for (int i = 1; i < list.size(); i++) {
            result -= list.get(i);
        }
        System.out.println(result);
    }
}