#include <cstdio>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    /*freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);*/
    int v[255]={}, max=0;

    for (int i=0; i<4; ++i){
        char line[100];

        gets(line);
        for (char *p=line; *p; ++p){
            if (!isupper(*p))
                continue;
            if (++v[*p]>max){
                max = v[*p];
            }
        }
    }
    for (; max; --max){
        string output;

        for (char letter='A'; letter<='Z'; ++letter){
            output += (v[letter]>=max ? '*' : ' ');
            output += (letter<'Z' ? " " : "");
        }
        while (output[output.size()-1]!='*'){
            output.erase(output.end()-1, output.end());
        }
        printf("%s\n", output.c_str());
    }
    for (char letter='A'; letter<='Z'; ++letter){
        printf("%c%s", letter, letter<'Z' ? " " : "");
    }
    return 0;
}
