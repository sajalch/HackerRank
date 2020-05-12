/*

Estimating the strength of any password is an important aspect of Information Security. In this challenge, your task is to calculate the strength of a given password in terms of weights assigned to the characters.

A password consists of English lowercase letters only.
Each English lowercase letter has assigned an integer weight in the range from 0 to 25 inclusive in such a way that the weight of letter  is given explicitly and weights of other letters follow in cyclic order. For example, if , then , , , , , , .
The strength of a password is the sum of weights of all characters the password consists of
Consider the following example. Let the password be  and the weight of letter  be 10. Then, the weights of all letters of the password are: , , , , , , , so the strength of the password is .

Input Format

In the first line, there is a string  denoting the password.

In the second line, there is an integer  denoting the weight of letter 

Constraints

 consists of English lowercase letters only
Output Format

The only line of the output must contain an integer denoting the strength of the password.

Sample Input 0

hellomrz
2
Sample Output 0

91
Explanation 0

The password is "hellomrz" and the weight of  is 2, so the weights of all letters of the password are: , , , , , , . The strength of the password is then .

Sample Input 1

aaaaa
1
Sample Output 1

5
Explanation 1

The password is "aaaaa" and the weight of  is 1, so the strength of the password is  as it consists of 5 letters .



*/




int getStrength(string password, int weight_a) {
    // Complete the function
    int answer=0,val=1;
    for(auto x:password)
    {
        val=(int)x-97+weight_a;
        val%=26;
        answer+=val;        
    } 
    return  answer;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string password;
    getline(cin, password);

    string weight_a_temp;
    getline(cin, weight_a_temp);

    int weight_a = stoi(ltrim(rtrim(weight_a_temp)));

    int strength = getStrength(password, weight_a);

    fout << strength << "\n";

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