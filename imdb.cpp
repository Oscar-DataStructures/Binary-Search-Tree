/*
Nicholas Reichert, Oscar Martinez
CS 271
Dr. Lall
Project 5
*/
using namespace std;

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "dict.h"

struct KVPair {
	string key;
	string value;
};
ostream& operator<<(ostream& os, const KVPair& dt) {
	return os << dt.key;
}
bool operator< (const KVPair &kv1, const KVPair &kv2) {
	return kv1.key < kv2.key;
}
bool operator> (const KVPair &kv1, const KVPair &kv2) {
	return kv1.key > kv2.key;
}
bool operator!= (const KVPair &kv1, const KVPair &kv2) {
	return kv1.key != kv2.key;
}
bool operator== (const KVPair &kv1, const KVPair &kv2) {
	return kv1.key == kv2.key;
}

Dictionary<KVPair> loadDataFile() {
  Dictionary<KVPair> movieData;

  ifstream movieFile;
  movieFile.open("data.tsv");
  if (movieFile.is_open()) {
    string input;
    while ( getline(movieFile, input) ) {
      istringstream ss(input);
      string junk;
      string movieTitle;
      string movieGenres;
      
      getline(ss, junk, '\t');
      getline(ss, junk, '\t');
      getline(ss, movieTitle, '\t');
      getline(ss, junk, '\t');
      getline(ss, junk, '\t');
      getline(ss, junk, '\t');
      getline(ss, junk, '\t');
      getline(ss, junk, '\t');
      getline(ss, movieGenres, '\t');

      KVPair moviePair;
      moviePair.key = movieTitle;
      moviePair.value = movieGenres;
      try {
        movieData.insert(moviePair);
      } catch (KeyError e) {
        // If a KeyError has occurred, the data is already in the Dictionary.
        // We won't do anything here.
        // The first occurence of a key that is added will always prevail.
      }
    }

    movieFile.close();
  } else {
    cout << "ERROR Reading file " << "data.tsv" << endl;
    exit(1);
  }

  return movieData;
}

void findGenre(Dictionary<KVPair> movieData, string searchTerm) {
  try {
    KVPair testPair;
    testPair.key = searchTerm;
    KVPair *foundPair = movieData.get(testPair);
    string genre = foundPair->value;
    cout << "Genres: " << genre << endl << endl;
  } catch (KeyError e) {
    cout << "Title not found." << endl << endl;
  }
}

int main() {
  Dictionary<KVPair> movieData = loadDataFile();
  while (true) {
    cout << "L1" << endl;
    string searchName;
    cout << "L2" << endl;
    cout << "Enter a movie/show title to search for: ";
    cout << "L3" << endl;
    getline(cin, searchName, '\n');
    cout << "L4" << endl;
    findGenre(movieData, searchName);
    cout << "L5" << endl;
  }
  
  return 0;
}

