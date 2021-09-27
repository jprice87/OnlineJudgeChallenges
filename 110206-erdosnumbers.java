import java.util.*;

class Main
{
    public static void main(String [] args)
    {
        Scanner reader = new Scanner(System.in);
        int scenarios = reader.nextInt();
        HashMap<String, ArrayList<String>> authorHash = new HashMap<String, ArrayList<String>>();
        HashMap<Integer, HashMap<String, Integer>> finalErdosHash = new HashMap<Integer, HashMap<String, Integer>>();
        ArrayList<ArrayList<String>> finalArrayList = new ArrayList<ArrayList<String>>();
        HashMap<String, Integer> erdosNums = new HashMap<String, Integer>();
        ArrayList<Integer> tempList = new ArrayList<Integer>();
        ArrayList<String> authorList = new ArrayList<String>();
        ArrayList<HashMap<String, Integer>> tempErdosList = new ArrayList<HashMap<String, Integer>>();
        for (int x = 0; x < scenarios; x++)
        {
            int numPapers = reader.nextInt();
            int numAuthors = reader.nextInt();
            reader.nextLine();
            for (int y = 0; y < numPapers; y++)
            {
                String paperLine = reader.nextLine().trim();
                String[] authorsAndPaper = paperLine.split(":");
                ArrayList<String> authorsArrayList = new ArrayList<String>();

                //put authors into separate array positions
                authorsAndPaper[0].replaceAll("\\s", "");
                String[] authorsArray = authorsAndPaper[0].split(",");
                for (int z = 0; z < authorsArray.length - 1; z = z + 2)
                {
                    authorsArrayList.add(authorsArray[z].concat("," + authorsArray[z+1]).replaceAll("\\s", ""));
                }

                for (int z = 0; z < authorsArrayList.size(); z++)
                {
                    ArrayList<String> neighbors = authorHash.getOrDefault(authorsArrayList.get(z), new ArrayList());
                    for (int w = 0; w < authorsArrayList.size(); w++)
                    {
                        if (!(authorsArrayList.get(z).equals(authorsArrayList.get(w))))
                        { 
                            neighbors.add(authorsArrayList.get(w));
                        }
                    }
                    authorHash.put(authorsArrayList.get(z), neighbors);
                }
                
            }//papers
            
           // erdosNums = erdos(authorHash);
            //finalArrayList.add(erdosNums);
            
            for (int z = 0; z < numAuthors; z++)
            {
                String authorName = reader.nextLine();
                //erdosNums.put(authorName,(erdos(authorHash).get(authorName)));
                authorList.add(authorName);
                
            }
            tempList.add(numAuthors);
            tempErdosList.add(erdos(authorHash));
            // finalArrayList.add(tempList);
            // int scenario2 = x + 1;
            // System.out.println("Scenario " + scenario2);


        }//scenarios
        
        for (int x = 0; x < scenarios; x++)
        {
            int tempScenario = x + 1;
            System.out.println("Scenario " + tempScenario);
            for (int q = 0; q < tempList.get(x); q++)
            {
                // int temp = erdosNums.getOrDefault(authorList.get(q).replaceAll("\\s", ""), -1);
                int temp = tempErdosList.get(x).getOrDefault(authorList.get(q).replaceAll("\\s", ""), -1);
                if (temp <= -1)
                {
                    System.out.println(authorList.get(q) + " infinity");
                }
                else
                {
                    System.out.println(authorList.get(q) +" " + temp);
                }
            }
        }
        System.out.println("");
        reader.close();
        System.exit(0);

        
    }

    static HashMap<String, Integer> erdos(HashMap authorHash)
    {
        HashMap<String, Integer> erdosNums = new HashMap<String, Integer>();
        Queue<String> queue = new PriorityQueue<String>();
        queue.add("Erdos,P.0");
        while (!queue.isEmpty())
        {
           // String currentAuthor = queue.peek();
            String authorAndErdos = queue.remove();
            
            int indexOfDot = authorAndErdos.lastIndexOf(".");

            String currentAuthor = authorAndErdos.substring(0, indexOfDot + 1);
            Integer erdosNum = Integer.parseInt(authorAndErdos.substring(indexOfDot + 1));

            if (!erdosNums.containsKey(currentAuthor))
            {
                erdosNums.put(currentAuthor, erdosNum);
            }
            boolean tempChanged = false;
            Object newAuthorList = authorHash.get(currentAuthor);
            for(int i = 0; i < ((ArrayList<String>)newAuthorList).size(); i++)
            {
                if (!erdosNums.containsKey(((ArrayList<String>)newAuthorList).get(i)))
                {
                    int temp = erdosNum + 1;
                    tempChanged = true;
                    queue.add(((ArrayList<String>)newAuthorList).get(i) + temp);
                }
            }
            if(tempChanged)
            {
                erdosNum = erdosNum + 1;
                tempChanged = false;
            }

            // Object[] keys = authorHash.keySet().toArray();
            // for (int i = 0; i < keys.length; i++)
            // {
            //     if (!contains(queue,keys[i].toString()))
            //     {
            //         int temp = erdosNum + 1;
            //         queue.add(keys[i].toString() + temp);
            //     }
            // }

            
        }
        return erdosNums;
    }

    static boolean contains(Queue<String> queue, String author)
    {
        for (String authorAndErdos1: queue)
            {
                if ((authorAndErdos1.substring(0, authorAndErdos1.lastIndexOf(".") + 1)).equals(author) )
                {
                    return true;
                }    
            }
            return false;
    }
}






