import java.util.*;

class Main {
    public static void main(String[] args)
    {
        //Create scanner and variables
        Scanner reader = new Scanner(System.in);
        int rows = 0;
        int cols = 0;
        int numMines = 0;
        int fieldNum = 1;
        ArrayList<String[][]> minefieldArray = new ArrayList<String[][]>();
        //Loop while there is still input
        while (reader.hasNext())
        {
            //Set rows and columns and minefield grid. If rows or columns is empty then exit
            rows = reader.nextInt();
            cols = reader.nextInt();
            String[][] minefield = new String[rows+2][cols+2];
            if (rows == 0 || cols == 0)
            {
                printMinefield(minefieldArray);
            }
            //what about 1 x 1 ?
            else
            {
                //Needed to grab the last endline character?
                String temp2 = reader.nextLine();
                //loop through input and add to minefield grid
                for (int x = 1; x <= rows; x++)
                {
                    String temp = reader.nextLine();
                    if (temp != "")
                    {
                        for(int y = 1; y <= cols; y++)
                        {
                            minefield[x][y] = temp.substring(y-1, y);
                        }
                        temp = "";
                    }
                    
                }
                //loop through input grid to get the number of mines at each location
                for (int x = 1; x <= rows; x++)
                {
                    for (int y = 1; y <= cols; y++)
                    {
                        numMines = getNumberOfMines(minefield, x,y);
                        if (numMines != -1)
                        {
                            minefield[x][y] = Integer.toString(numMines);
                        }
                    }
                }
                //add to arraylist
            minefieldArray.add(minefield);
            }
        }
        reader.close();   
    }

    static void printMinefield(ArrayList<String[][]> minefield)
    {
        for (int x = 0; x < minefield.size(); x++)
        {
            String[][] currentField = minefield.get(x);
            System.out.println("Field #" + (x+1) + ":");
            for (int y = 1; y <= currentField.length - 2; y++)
            {
                for (int z = 1; z < currentField[0].length - 2; z++)
                {
                    System.out.print(currentField[y][z]);
                }
                System.out.println(currentField[y][currentField[0].length - 2]);
            }
            if ((x+1) < minefield.size())
            {
                System.out.println("");
            }
        }
    }   
    
    static int getNumberOfMines(String[][] minefield, int row, int col)
    {
        //if the current grid square is a bomb then return -1
        int numMines = 0;
        if(minefield[row][col].equals("*"))
        {
            return -1;
        }
        else
        {
            // loop through the 8 close positions a bomb can be located at and tally
            for(int x = row-1; x<=row+1; x++)
            {
                for (int y = col-1; y<=col+1; y++)
                {
                    if (!(x == row && y == col))
                    {
                        if (minefield[x][y] != null && minefield[x][y].equals("*"))
                        {
                            numMines++;
                        }
                    }
                }
            }
            return numMines;
        }
        
    }
}
     

