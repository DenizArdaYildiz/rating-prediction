#include <algorithm>
#include <fstream>
#include <sstream>   
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdio>
#include <cmath>
#include <numeric>
using namespace std;



// Custom comparator function for sorting the vector of pairs
bool comp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

int main() {
    // Create two unordered_maps to store the counts of ratings for each user and movie
    unordered_map<string, int> user_ratings;
    unordered_map<string, int> movie_ratings;

    // Open the train.csv file and read the rows
    ifstream f("train.csv");
    string line;
    getline(f, line); // Skip the header row
    while (getline(f, line)) {
        // Split the row by the comma delimiter
        int pos = line.find(',');
        string user_id = line.substr(0, pos);
        line = line.substr(pos + 1);
        pos = line.find(',');
        string movie_id = line.substr(0, pos);
        // Update the count of ratings for the user
        if (user_ratings.count(user_id) > 0) {
            user_ratings[user_id]++;
        }
        else {
            user_ratings[user_id] = 1;
        }
        // Update the count of ratings for the movie
        if (movie_ratings.count(movie_id) > 0) {
            movie_ratings[movie_id]++;
        }
        else {
            movie_ratings[movie_id] = 1;
        }
    }
    f.close();

    // Store the users and movies in a vector of pairs
    vector<pair<string, int>> users;
    vector<pair<string, int>> movies;
    for (const auto& p : user_ratings) {
        users.push_back(make_pair(p.first, p.second));
    }
    for (const auto& p : movie_ratings) {
        movies.push_back(make_pair(p.first, p.second));
    }

    // Sort the vector of pairs by count in decreasing order
    sort(users.begin(), users.end(), comp);
    sort(movies.begin(), movies.end(), comp);

    // Print the top 10 users and top 10 movies
    cout << "Top 10 users:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << ". User " << users[i].first << " with " << users[i].second << " ratings" << endl;
    }
    cout << "\nTop 10 movies:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << ". Movie " << movies[i].first << " with " << movies[i].second << " ratings" << endl;
    }

    return 0;
}







