#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*An avid hiker keeps meticulous records of their hikes. During the last hike that took exactly  steps, for every step it was noted if it was an uphill, , or a downhill,  step. Hikes always start and end at sea level, and each step up or down represents a  unit change in altitude. We define the following terms:

A mountain is a sequence of consecutive steps above sea level, starting with a step up from sea level and ending with a step down to sea level.
A valley is a sequence of consecutive steps below sea level, starting with a step down from sea level and ending with a step up to sea level.
Given the sequence of up and down steps during a hike, find and print the number of valleys walked through.

Example

 

The hiker first enters a valley  units deep. Then they climb out and up onto a mountain  units high. Finally, the hiker returns to sea level and ends the hike.
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
int countingValleys(int steps, string path) 
{
    int sea_level = 0;
    int v = 0;
    
    for(int i = 0; i< steps; i++)
    {
        if(sea_level<= 0)
        { 
            if(path[i] == 'D')
            {
                v++;
                sea_level--;
               while(sea_level != 0)
               {
                   if( path[++i] == 'U')
                    {
                        sea_level++;
                     }
                else {
                    sea_level--;
                      }
               }
            }
            else 
            {
            sea_level++;
            }
        }
        else
        {
        if( path[i] == 'U')
        {
            sea_level++;
        }
        else {
         sea_level--;
        }
        
        }
    }
    return v;
} */

int countingValleys(int steps, string path) 
{
    int sea_level = 0;
    int v = 0;
    
    for(int i = 0; i< steps; i++)
    {
        if(sea_level<= 0)
        { 
            if(path[i] == 'D')
            {
                v++;
                sea_level--;
               while(path[++i] != 'U')
               {
                   sea_level--;
               }
                sea_level++;  
            }
            else {
            sea_level++;
            }
        }
        else
        {
        if( path[i] == 'U')
        {
            sea_level++;
        }
        else {
         sea_level--;
        }
        
        }
    }
    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

