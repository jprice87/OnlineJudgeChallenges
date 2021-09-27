//Import statements
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    //declare variables to hold the strings an an array that keeps count of letters in the alphabet
    string word1;
    string word2;
    int word1Array[26];
    int word2Array[26];

    //loop while there are two words to grab
    while (getline(cin, word1) && getline(cin, word2))
    {
        //set the length to variables
        int word1Size = word1.size();
        int word2Size = word2.size();

        //set word arrays with unsigned bytes
        memset(word1Array,0,sizeof(word1Array));
        memset(word2Array,0,sizeof(word2Array));

        //loop through word1 and tally the amount of characters in word1array
        for (int x = 0; x < word1Size; ++x) 
        {
            // - 'a' is converting between ascii and the alphabet character array
            word1Array[word1[x] - 'a'] = word1Array[word1[x] - 'a'] + 1;
        }
        //loop through word1 and tally the amount of characters in word1array
        for (int y = 0; y < word2Size; ++y) 
        {
            // - 'a' is converting between ascii and the alphabet character array
            word2Array[word2[y] - 'a'] = word2Array[word2[y] - 'a'] + 1;
        }

        //loop through the alphabet
        for (int x = 0; x < 26; ++x)
        {
            //start at the end of the smaller one between the two word arrays
            for (int y = min(word1Array[x],word2Array[x])-1; y >= 0; --y)
            {
                //convert back and send to console
                putchar('a' + x);
            }
        }
        putchar('\n');
    }
    return 0;
}


