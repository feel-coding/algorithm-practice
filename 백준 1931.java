import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        ArrayList<Tuple> li = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            li.add(new Tuple(in.nextInt(), in.nextInt()));
        }
        li.sort(new Comparator<Tuple>() {
            @Override
            public int compare(Tuple o1, Tuple o2) {
                if (o1.y - o2.y < 0)
                    return -1;
                else if (o1.y - o2.y > 0)
                    return 1;
                else
                    return o1.x - o2.x;
            }
        });
        ArrayList<Tuple> order = new ArrayList<>();
        int count = 0;
        order.add(li.get(0));
        count++;
        for (int i = 1; i < n; i++) {
            if(order.get(count - 1).y <= li.get(i).x) {
                count++;
                order.add(li.get(i));
            }
        }
        System.out.println(count);
    }
}
class Tuple {
    int x;
    int y;

    public Tuple(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}
