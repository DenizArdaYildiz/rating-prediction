#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <numeric>
#include <utility> // for std::pair
#include <iomanip> 


using namespace std;

// Function to split a string into a vector of fields
vector<string> split(const string& s, char delimiter) {
    vector<string> fields;
    stringstream ss(s);
    string field;
    while (getline(ss, field, delimiter)) {
        fields.push_back(field);
    }
    return fields;
}

int main() {
    // Open the input files
    ifstream file1("deniz.csv");
    ifstream file2("output.csv");

    // Open the output file
    ofstream out_file("arda.csv");
    int index = 0;
    // Read the files line by line
    string line1, line2;
    while (getline(file1, line1) && getline(file2, line2)) {
        // Split the lines into fields
        auto fields1 = split(line1, ',');
        auto fields2 = split(line2, ',');

        // Check if the fields are numeric
        bool field1_is_numeric = true;
        bool field2_is_numeric = true;
        try {
            stod(fields1[1]);
        }
        catch (...) {
            field1_is_numeric = false;
        }
        try {
            stod(fields2[1]);
        }
        catch (...) {
            field2_is_numeric = false;
        }

        // Calculate the average of the fields if both are numeric
        double avg = 0;
        if (field1_is_numeric && field2_is_numeric) {
            avg = (stod(fields1[1]) + stod(fields2[1])) / 2;
        }

        // Write the first field of both lines and the average to the output file
             
        
        out_file << index-1 << "," << std::fixed << std::setprecision(5) << avg<< std::endl;

        // Increment the index
        index++;
    }

    

    // Close the files
    file1.close();
    file2.close();
    out_file.close();

    return 0;
}