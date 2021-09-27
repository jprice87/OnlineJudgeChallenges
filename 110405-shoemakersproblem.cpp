//included libraries
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

//job class description
class job
{
    public:
        int id;
        int time;
        int fine;
};

//compare function to help compare job time/fine ratio
bool compare(const job &job1, const job &job2)
{
    if (job1.time * job2.fine < job2.time * job1.fine)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    //grab scenarios and loop
    int scenarios;
    cin >> scenarios;
    while (scenarios > 0)
    {
        //grab the number of shoe jobs and loop
        int numShoes;
        cin >> numShoes;
        cin.ignore();
        vector<job> jobVector;
        int id = 1;

        //create job object and push them onto the job vector for later printing
        for (int x = 0; x < numShoes; x++)
        {
            job job;
            int time;
            int fine;
            string nothing;
            string line;
            stringstream ssInput;
            getline(cin, line);
            ssInput << line; 
            ssInput >> time >> fine >> nothing;
            job.id = id;
            id++;
            job.time = time;
            job.fine = fine;
            jobVector.push_back(job);
        }

        //stable sort keeps identical times from moving up and down the list
        //sort based on compared ratios of time/fine
        stable_sort(jobVector.begin(), jobVector.end(), compare);

        //print out job order
        cout << jobVector[0].id;
        for (int x = 1; x < numShoes; ++x)
        {
            cout << " " << jobVector[x].id;
        }
        cout << endl;
        scenarios--;

        //if there are more scenarios then print blank line
        if (scenarios > 0)
        {
            cout << endl;
        }
    }
    return 0;
}