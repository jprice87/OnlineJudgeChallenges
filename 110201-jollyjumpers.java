
//import statements
import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        //need to check for last endline character so the printing works
        while (reader.hasNext()) {
            int numNumbers = reader.nextInt();
            ArrayList<Integer> array = new ArrayList<Integer>();
            for (int x = 0; x < numNumbers; x++) {
                array.add(reader.nextInt());
            }

            ArrayList<Integer> array2 = new ArrayList<Integer>();
            for (int x = 0; x < array.size() - 1; x++) {
                int difference = Math.abs(array.get(x) - array.get(x + 1));
                array2.add(difference);
            }
            boolean isJolly = true;
            for (int x = 1; x < numNumbers; x++) {
                if (!array2.contains(x)) {
                    isJolly = false;
                }
            }
            if (isJolly) {
                System.out.println("Jolly");
            } else {
                System.out.println("Not jolly");
            }
        }

    }
}