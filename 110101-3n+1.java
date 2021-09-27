//import statements
import java.util.*;

class Main {
    public static void main(String [] args)
    {
        //Declare scanner and a few variables
        Scanner reader = new Scanner(System.in);
        int i = 0;
        int j = 0;
        int maxCycle = 0;

        //while there is still input, loop through from i to j and calculate the max cycle
        while (reader.hasNext())
        {
            //grab the next ints for i and j
            i = reader.nextInt();
            j = reader.nextInt();
            
            //Math.min makes it work for when i is less than j
            for(int x = Math.min(i,j); x<= Math.max(i,j); x++)
            {
                //if new cycle is greater than previous then set new max
                if (getCycleAmount(x) > maxCycle)
                {
                    maxCycle = getCycleAmount(x);
                }
            }
            //print
            System.out.println(String.format("%d %d %d", i, j, maxCycle));
            maxCycle = 0;
        }
        //close reader and exit
        reader.close();
        System.exit(0);
    }

    //get the amount of cycles for a given number
    static int getCycleAmount(int x)
    {
        //cycle is always at least 1
        int cycleAmount = 1;
        while(x != 1)
        {
            //if odd number
            if (x % 2 != 0)
            {
                x = (x * 3) + 1;
            }
            //if even number
            else
            {
                x = x/2;
            }
            //increment cycles
            cycleAmount++;
        }
        return cycleAmount;
    }
}