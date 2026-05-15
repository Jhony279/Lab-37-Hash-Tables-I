#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

const string FILENAME = "lab-37-data-3.txt";
const int MAX_OPTIONS = 6;

int main_menu();
int get_hash_index(string);
void print_first_100(const map<int, list<string>>&);
void search_key(map<int, list<string>>&);
void add_key(map<int, list<string>>&);
void remove_key(map<int, list<string>>&);

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

    int choice = 0;
    bool again = true;
    // Main menu loop
    while (again) {
        int sel = main_menu();
        switch (sel) {
            case 1:
                print_first_100(hash_table);
                break;

            case 2:
                search_key(hash_table);
                break;

            case 3:
                add_key(hash_table);
                break;

            case 4:
                remove_key(hash_table);
                break;

            case 5:
                break;

            case 6:
                again = false;
                break;

            default:
                cout << "\nInvalid selection.\n";
                break;
        }
    }

    return 0;
}

int main_menu() {
    cout << "\n*** Main Menu ***\n";
    cout << "[1] Print First 100 Items\n";
    cout << "[2] Search Key\n";
    cout << "[3] Add Key\n";
    cout << "[4] Delete Key\n";
    cout << "[5] Modify key\n";
    cout << "[6] Quit\n";
    cout << "Choice --> ";

    int choice;
    cin >> choice;
    while (choice < 1 || choice > MAX_OPTIONS) {
        cout << "Invalid, again --> ";
        cin >> choice;
    }
    return choice;
}

int get_hash_index(string s) {
    int sum = 0;
    
    // Loop through each character 'c' in the string 'text'
    for (char c : s) {
        sum += (int) c;
    }
    return sum;
}

void print_first_100(const map<int, list<string>>& hash_table) {
    int total_printed = 0;
    // Iterate through the hash table and print the first 100 items
    for (auto it = hash_table.begin(); it != hash_table.end(); ++it) {
        if (total_printed >= 100) break;
        
        cout << "Index " << it->first << " contains: ";
        for (const string &code : it->second) {
            cout << code << ", ";
            total_printed++;
            if (total_printed >= 100) break; 
        }
        cout << endl;
    }
    cout << "\nTotal items printed: " << total_printed << endl;
}

void search_key(map<int, list<string>>& hash_table) {
    string key;
    cout << "Enter key to search for: ";
    cin >> key;
    int hash_index = get_hash_index(key);
    
    if (hash_table.count(hash_index)) {
        auto& bucket = hash_table[hash_index];
        auto found = find(bucket.begin(), bucket.end(), key);
        if (found != bucket.end()) {
            cout << ">> Found! Key '" << key << "' is located at index " << hash_index << ".\n";
        } else {
            cout << ">> Key '" << key << "' not found.\n";
        }
    } else {
        cout << ">> Key '" << key << "' not found.\n";
    }
}

void add_key(map<int, list<string>>& hash_table) {
    string key;
    cout << "Enter key to add: ";
    cin >> key;
    int hash_index = get_hash_index(key);
    hash_table[hash_index].push_back(key);
    cout << ">> Success. Key '" << key << "' added to index " << hash_index << ".\n";
}

void remove_key(map<int, list<string>>& hash_table) {
    string key;
    cout << "Enter key to remove: ";
    cin >> key;
    int hash_index = get_hash_index(key);
    
    if (hash_table.count(hash_index)) {
        auto& bucket = hash_table[hash_index];
        auto found = find(bucket.begin(), bucket.end(), key);
        if (found != bucket.end()) {
            bucket.erase(found);
            cout << ">> Success. Key '" << key << "' removed from index " << hash_index << ".\n";
            // Clean up empty buckets
            if (bucket.empty()) {
                hash_table.erase(hash_index);
            }
        } else {
            cout << ">> Key '" << key << "' not found. Cannot remove.\n";
        }
    } else {
        cout << ">> Key '" << key << "' not found. Cannot remove.\n";
    }
}