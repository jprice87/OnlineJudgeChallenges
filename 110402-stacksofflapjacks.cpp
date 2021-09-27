//included libraries
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    //loop while there is input
    string lineString;
    while(getline(cin, lineString))
    {
        //declare variables to hold the expected and the original stacks, number of pancakes, the index of the max, and the number for the flip
        int stack[1000];
        int flipNumbers[1000];
        int numPancakes = 0;
        int maxIndex = -1;
        int flipNum = 0;

        //turn string into integer stringstream and counting number of pancakes
        stringstream sin(lineString);
        //insert stack into the stack vector and count number or elements
        while (sin >> stack[numPancakes])
        {
            numPancakes++;
        }

        //print out original stack of pancakes
        cout << stack[0];
        for (int x = 1; x < numPancakes; x++)
        {
            cout << " " << stack[x];
        }
        cout << endl;

        //loop through pancakes
        for (int currentCakeIndex = 0; currentCakeIndex < numPancakes; currentCakeIndex++)
        {
            //set maxIndex to bottom pancake 
            //(largest index pos initially, then 2nd largest index, 
            //... , then finally the smallest index)
            maxIndex = (numPancakes - currentCakeIndex) - 1;
            //find new maxIndex if stack[maxIndex] is not the max
            for (int newMaxIndex = 0; newMaxIndex < numPancakes - currentCakeIndex; newMaxIndex++)
            {
                if (stack[maxIndex] < stack[newMaxIndex])
                {
                    maxIndex = newMaxIndex;
                }
            }
            //if the max width pancake is not on the top but not on the bottom
            //flip from the index of the difference between the numPancakes and maxIndex
            if (maxIndex != ((numPancakes - currentCakeIndex) - 1))
            {
                if (maxIndex > 0)
                {
                    flipNumbers[flipNum] = numPancakes - maxIndex;
                    flipNum++;
                    int tempIndex = maxIndex;
                    int tempPancake;
                    for (int x = 0; x < tempIndex; x++)
                    {
                        tempPancake = stack[x];
                        stack[x] = stack[tempIndex];
                        stack[tempIndex] = tempPancake;
                        tempIndex--;
                    }
                }

                //if maxIndex is on the bottom
                flipNumbers[flipNum] = currentCakeIndex + 1;
                flipNum++;
                int tempIndex = (numPancakes - currentCakeIndex) - 1;
                int tempPancake;
                for (int x = 0; x < tempIndex; x++)
                {
                    tempPancake = stack[x];
                    stack[x] = stack[tempIndex];
                    stack[tempIndex] = tempPancake;
                    tempIndex--;
                }
            }
        }

        //print out the flip numbers
        for (int x = 0; x < flipNum; x++)
        {
            cout << flipNumbers[x] << " ";
        }
        puts("0");
    }
return 0;
}