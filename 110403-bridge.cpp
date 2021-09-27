//included libraries
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    //grab number of scenarios and then loop
    int scenarios;
    cin >> scenarios;
    while ( scenarios > 0 )
    {
        scenarios = scenarios - 1;

        //grab number of people and then loop, taking in the times and putting it into vector people
        int numPeople;
        cin >> numPeople;
        vector<int> people(numPeople + 1);
        for (int x = 1; x <= numPeople; ++x)
            cin >> people[x];
        
        //sort to help compare fast and slow people easier
        sort(people.begin(), people.end());

        //create output string stream and declare index for number of people and total time
        stringstream ss;
        int tempNumPeople = numPeople;
        int totalTime = 0;

        //if there are 4 or more people then you can run the fastest two, 
        //the fastest back, the slowest two, and the slowest two back or
        //check the fastest and slowest, fastest back, fastest and second
        //slowest, then finally fastest back
        while (tempNumPeople >= 4)
        {

            int fastFast = people[2] + people[1] + people[tempNumPeople] + people[2];
            int fastSlow = people[tempNumPeople] + people[1] + people[tempNumPeople - 1] + people[1];

            //check if first or second setup is faster then increment people index
            if (fastFast < fastSlow)
            {
                //add to the total time then print the round
                totalTime += fastFast;
                ss << people[1] << " " << people[2] << endl;
                ss << people[1] << endl;
                ss << people[tempNumPeople - 1] << " " << people[tempNumPeople] << endl;
                ss << people[2] << endl;
            }
            else
            {
                //add to the total time then print the round
                totalTime += fastSlow;
                ss << people[1] << " " << people[tempNumPeople] << endl;
                ss << people[1] << endl;
                ss << people[1] << " " << people[tempNumPeople - 1] << endl;
                ss << people[1] << endl;
            }
            tempNumPeople -= 2;
        }

        //if there are three people you can only run the fastest
        //and the second fastest, fastest back, then fastest and
        //third fastest back
        if (tempNumPeople == 3)
        {
            //add to the total time then print the round
            totalTime += people[2] + people[1] + people[3];
            ss << people[1] << " " << people[2] << endl;
            ss << people[1] << endl;
            ss << people[1] << " " << people[3] << endl;
        }

        //if there are two people then just run them across
        else if (tempNumPeople == 2)
        {
            //add to the total time then print the round
            totalTime += people[2];
            ss << people[1] << " " << people[2] << endl;
        }

        //if there is only one person then just run them across
        else
        {
            //add to the total time then print the round
            totalTime += people[1];
            ss << people[1] << endl;
        }

        //print the total time then the string stream
        cout << totalTime << endl;
        cout << ss.str();

        //if there are more scenarios then print blank
        if (scenarios > 0)
            cout << endl;
    }
    return 0;
}