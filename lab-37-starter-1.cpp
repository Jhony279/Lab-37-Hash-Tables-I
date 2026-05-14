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

    int total_sum = 0;
    while (getline(file, line)) {  // Read the file line by line
        // Get hash index
        int hash_index = get_hash_index(line);

        // insert into hash table
        hash_table[hash_index].push_back(line);
    }
    file.close();  // Close the file after reading

    int count = 0;
    // Iterate through the map
    for (auto it = hash_table.begin(); it != hash_table.end() && count < 100; ++it) {
        
        // it->first is the integer hash index
        cout << "Index " << it->first << " contains: ";
        
        // it->second is the list<string>, so we loop through it to print the codes
        for (string code : it->second) {
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