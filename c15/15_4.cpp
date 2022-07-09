#include <iostream>

using namespace std;

struct SongData {
    char title[50];
    char artist[50];
    int year;
};
 
void getSongData(SongData &song);
void printSongData(SongData song);

int main() {

    SongData song;
    
    getSongData(song);
    printSongData(song);

    return 0; 
}

void getSongData(SongData &song) {
    cin.getline(song.title, 50);
    cin.getline(song.artist, 50);
    cin >> song.year;
}

void printSongData(SongData song) {
    cout << "Title: " << song.title << endl;
    cout << "Artist: " << song.artist << endl;
    cout << "Year: " << song.year << endl;
}