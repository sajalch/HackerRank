/*
A coin was tossed numerous times. You need to find the longest streak of tosses resulting  and the longest streak of tosses resulting in .

Formally, given the results of  tosses of a coin, find the maximum number of consecutive  and the maximum number of consecutive .

Consider the following example: a coin was tossed  times and the results were . Therefore, the longest  streak was  and the longest  streak was .

Complete the function getMaxStreaks which takes an array of strings toss and returns an array of two integers denoting the maximum streaks of  and  respectively.

Input Format

In the first line, there is a single integer  denoting the number of tosses.

Then,  lines follow. The  of them contains a string  denoting the result of the  toss of the coin.

Constraints

Output Format

In a single line, print two space-separated integers denoting the maximum streak of  and the maximum streak of  respectively.

Sample Input 0

7
Heads
Tails
Tails
Tails
Heads
Heads
Tails
Sample Output 0

2 3
Explanation 0

The longest streak of  is 2 and the longest streak of  is 3.

Sample Input 1

3
Tails
Tails
Tails
Sample Output 1

0 3
Explanation 1

The longest streak of  is 0 since there were no such tosses, and the longest streak of  is 3.

Sample Input 2

4
Heads
Heads
Heads
Heads
Sample Output 2

4 0
Explanation 2

The longest streak of  is 4, and the longest streak of  is 0 since there were no such tosses.
*/




#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'getMaxStreaks' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY toss as parameter.
 */

vector<int> getMaxStreaks(vector<string> toss) {
    // Return an array of two integers containing the maximum streak of heads and tails respectively
    vector<int> streak;    
    int h=0, t=0, hm=0, tm=0;
    for(string x:toss) {
        if(x=="Heads"){h++; hm=max(hm, h);}
        else h=0;
        if(x=="Tails"){t++; tm=max(tm, t);}
        else t=0;    
    }
    streak.push_back(hm);
    streak.push_back(tm);
    return streak;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string toss_count_temp;
    getline(cin, toss_count_temp);

    int toss_count = stoi(ltrim(rtrim(toss_count_temp)));

    vector<string> toss(toss_count);

    for (int i = 0; i < toss_count; i++) {
        string toss_item;
        getline(cin, toss_item);

        toss[i] = toss_item;
    }

    vector<int> ans = getMaxStreaks(toss);

    for (long unsigned int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
