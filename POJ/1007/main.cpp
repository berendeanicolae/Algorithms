#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int inv(string &str){
    int s=0;

    for (unsigned i=0; i<str.size(); ++i){
        for (unsigned j=i+1; j<str.size(); ++j){
            s += str[i]>str[j];
        }
    }
    return s;
}

vector<pair<int, string> > strings;

int main()
{
    int n, m;

    cin >> n >> m;
    for (int i=0; i<m; ++i){
        string str;

        cin >> str;
        strings.push_back(make_pair(inv(str), str));
    }
    sort(strings.begin(), strings.end());
    for (int i=0; i<m; ++i){
        cout << strings[i].second << "\n";
    }
    return 0;
}