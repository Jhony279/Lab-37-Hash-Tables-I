#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
using namespace std;

const string FILENAME = "lab-37-data-3.txt";
int get_hash_index(string);

int main() {
    // Map
    map<int, list<string>> hash_table;

    // Open the file for reading
    ifstream file(FILENAME);
    string line;
    if (!file.is_open()) {  // Check if the file was opened successfully
        cout << "Error opening file: " << FILENAME << endl;
        return 1;
    }

    while (getline(file, line)) {  // Read the file line by line
        string code = line;

        // Send the code to the hash function and receive its index
        int hash_index = get_hash_index(code);

        // Insert the code into the map at that hash index
        list<string> &bucket = hash_table[hash_index];
        bucket.push_back(code);
    }
    file.close();  // Close the file after reading

    int count = 0;
    // Display just the first 100 map entries to test the data structure
    for (auto it = hash_table.begin(); it != hash_table.end() && count < 100; ++it) {
        cout << "Index " << it->first << " contains: ";
        for (const string &code : it->second) {
            cout << code << ", ";
        }
        cout << endl;
        count++; // Keep track so we stop at 100
    }


    // char a = 'A';
    // cout << a << endl;
    // cout << (int) a << endl;
    // int b = 66;
    // cout << b << endl;
    // cout << (char) b << endl;

    return 0;
}

int get_hash_index(string s) {
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