#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string FILENAME = "lab-37-data-3.txt";
int sum_ascii(string);

int main() {
    ifstream file(FILENAME);
    if (!file.is_open()) {
        cout << "Error opening file: " << FILENAME << endl;
        return 1;
    }


    // char a = 'A';
    // cout << a << endl;
    // cout << (int) a << endl;
    // int b = 66;
    // cout << b << endl;
    // cout << (char) b << endl;
    
    int value = sum_ascii("Hello World");
    cout << value << endl;

    return 0;
}

int sum_ascii(string s) {
    int sum = 0;
    
    // Loop through each character 'c' in the string 'text'
    for (char c : s) {
        sum += (int) c;
    }
    return sum;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/