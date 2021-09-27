//import statements
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

//function takes in a vector and returns the numbers without the spacing around them
string presentation(const vector<string> &v)
{
    //create new stringstream and size variable
    stringstream ss;
    int size = v.size();

    //loop for the size of the vector
    for (int x = 0; x < size; x++)
    {
        //get the length of the string in the vector and loop the string
        int length = v[x].size();
        for (int y = 0; y < length; y++)
        {
            //if current position is a number then add to string stream
            if (v[x][y] >= '0' && v[x][y] <= '9')
            {
                ss << v[x][y];
            }
        }
    }

    //return string stream
    return ss.str();
} 
int main(void)
{
    //declare variables for the number of entries, the input, and vectors for the correct answers, submissions, and final values.
    int numCorrect;
    int numAnswers;
    string input;
    vector<string> correct;
    vector<string> answer;
    vector<string> finalV;

    //loop until seeing a 0
    while (cin >> numCorrect)
    {
        if (numCorrect == 0)
        {
            break;
        }

        //make sure that the vectors are cleared and ready for reuse
        correct.clear();
        answer.clear();

        //needed to go to the next line of input
        cin.ignore(100, '\n');

        //loop for number of correct answers and push to correct vector
        for (int x = 0; x < numCorrect; x++)
        {
            getline(cin, input);
            correct.push_back(input);
        }

        //take in the number of answers
        cin >> numAnswers;

        //one more ignore needed
        cin.ignore(100, '\n');

        //loop for number of submissions and push to answer vector
        for (int x = 0; x < numAnswers; x++)
        {
            getline(cin, input);
            answer.push_back(input);
        }

        //check for an equal number of responses
        if (numCorrect == numAnswers)
        {
            //declare variable to track correctness
            bool isCorrect = true;

            //loop for the number of submissions and if they differ in one position then break loop and isCorrect false
            for (int x = 0; x < numCorrect; x++)
            {
                if (correct[x] != answer[x])
                {
                    isCorrect = false;
                    break;
                }
            }

            //check if it correct, continue loop if it is, push accepted response
            if (isCorrect)
            {
                finalV.push_back("Accepted");
                continue;
            }
        }

        //if you reached here then it wasnt accepted. Check to see if presentation is off, if so then push presentation error
        if (presentation(correct) == presentation(answer))
        {
            finalV.push_back("Presentation Error");
            continue;
        }
        //add wrong 
        finalV.push_back("Wrong Answer");
    }

    //loop over final size and print
    int size = finalV.size();
    for (int x = 0; x < size; x++)
    {
        int run = x + 1;
        cout << "Run #" << run << ": " << finalV[x] << endl;
    }
    return 0;

} 

