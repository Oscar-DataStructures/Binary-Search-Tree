/*
Nicholas Reichert, Oscar Martinez
CS 271
Dr. Lall
Project 5
*/
using namespace std;

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

map<string, string> loadDataFile() {
  map<string, string> movieData;

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

      movieData[movieTitle] = movieGenres;
    }

    movieFile.close();
  } else {
    cout << "ERROR Reading file " << "data.tsv" << endl;
    exit(1);
  }

  return movieData;
}

void findGenre(map<string, string> movieData, string searchTerm) {
  if (movieData.count(searchTerm) > 0) {
    string genre = movieData[searchTerm];
    cout << "Genres: " << genre << endl << endl;
  } else {
    cout << "Title not found." << endl << endl;
  }
}

int main() {
  map<string, string> movieData = loadDataFile();
  while (true) {
    string searchName;
    cout << "Enter a movie/show title to search for: ";
    getline(cin, searchName, '\n');
    findGenre(movieData, searchName);
  }
  
  return 0;
}

