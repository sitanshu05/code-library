#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string caesarCipher(string s, int k) {
    string b = "abcdefghijklmnopqrstuvwxyz";
    string c = "";
    int kk = 0;
    int kh = k % 26;
    for(int i = 0;i < 26;i++)
    {
        c = c + b[i + kh];
        kk++;
        if(i + kh == 25)
        {
            break;
        }
    }

    int j = 0;
    while(kk < 26)
    {
        c = c + b[j];
        kk++;j++;
    }

    int f = s.length();
    cout << b << endl;
    cout << c << endl;
    for(int i = 0;i < f;i++)
    {
        for(int j = 0;j < 26;j++)
        {
            if(s[i] == '-')
            {
                break;
            }

            else if(s[i] == b[j])
            {
                s[i] = c[j];
                break;
            }
        }
    }

    for(int i = 0;i < f;i++)
    {
        if(isupper(s[i]))
        {
            char x = tolower(s[i]);
            //cout << x << endl;
            for(int j = 0;j < 26;j++)
            {
                if(x == b[j])
                {
                    char mh = toupper(c[j]);
                    s[i] = mh;
                    break;
                }
            }
        }
    }

    return s;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

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
