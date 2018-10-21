#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <fstream>
// Vectors used instead of arrays due so size could be altered after declaration
#include <vector>


using namespace std;

int main()
{
    ifstream players;
    players.open("inputfile.txt");
    vector<string> playernames;
    string temp;

    while (!players.eof())
    {
        temp.clear();
        getline(players,temp);
        if (!temp.empty()) playernames.push_back(temp);
    }
    players.close();

    // If odd number of competators then add a match of each player against nobody
    if (playernames.size()%2 == 1) playernames.push_back("Nobody");

    int halfpoint = playernames.size()/2;
    int roundnumber = playernames.size()-1;

    ofstream roundi;

    for (int i = 0; i < roundnumber; i++)
    {
        string roundname = "Round" + to_string(i+1) + ".txt";
        roundi.open(roundname);

        for (int j = 0; j < halfpoint; j++)
        {
            string outline;
            int offset = j + i;
            int halfoffset = j + i + halfpoint;

            if (offset >= playernames.size()) offset -= playernames.size()-1;
            if (halfoffset >= playernames.size()) halfoffset -= playernames.size()-1;

            if (j == 0) outline = playernames[j] + " vs. " + playernames[halfoffset];
            else outline = playernames[offset] + " vs. " + playernames[halfoffset];

            roundi << outline << endl;
        }

        roundi.close();
    }

// New loop exists in case the game has first turn bias, allows players that previously started second to start first
    for (int i = 0; i < roundnumber; i++)
    {
        string roundname = "Round" + to_string(i+1+roundnumber) + ".txt";
        roundi.open(roundname);

        for (int j = 0; j < halfpoint; j++)
        {
            string outline;
            int offset = j + i;
            int halfoffset = j + i + halfpoint;

            if (offset >= playernames.size()) offset -= playernames.size()-1;
            if (halfoffset >= playernames.size()) halfoffset -= playernames.size()-1;

            if (j == 0) outline = playernames[halfoffset] + " vs. " + playernames[j];
            else outline = playernames[halfoffset] + " vs. " + playernames[offset];

            roundi << outline << endl;
        }

        roundi.close();
    }

// Used for debugging purposes
    /*for (int i = 0; i < playernames.size(); i++)
    {
        cout << playernames[i] << endl;
    }*/

    return 0;
}
