#include <iostream>
using namespace std;

char code[] = "101010011010001101001111001101000001110100110010111110001110100010000011010011110011010000001101110101101110001011010011110100010000011001011101110110001111011111100100110010111001000100000110000111100111100011110100111010010101110010000010110011101111111010111100100100000111000011000011110011111001111101111101111111001011001000100000110100111100110100000110010111000011110011111100111100111110100110000111100101110100110010111100100101110";

int main()
{
    char l=0;
    int b=0;

    for (char c : code){
        ++b;
        l = (l<<1) + c-'0';
        if (b==7){
            b = 0;
            cout << l;
            l = 0;
        }
    }
    return 0;
}