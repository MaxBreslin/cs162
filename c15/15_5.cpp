#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct SongData {
    char title[101];
    char artist[101];
    int year;
};
 
void loadSongs(SongData* songs, int &numSongs);
void printSongData(SongData* songs, int numSongs);

int main() {
    int numSongs = 0;
    SongData songs[50];
    loadSongs(songs, numSongs);
    printSongData(songs, numSongs);
    return 0; 
}

void loadSongs(SongData* songs, int &numSongs) {
    ifstream songFile("songs.txt");
    while(songFile) {
        songFile.getline(songs[numSongs].title, 101, ';');
        songFile.getline(songs[numSongs].artist, 101, ';');
        songFile >> songs[numSongs].year;
        songFile.ignore();
        numSongs ++;
    }    
}
void printSongData(SongData* songs, int numSongs) {
    for(int i = 0; i < numSongs; i++) {
        cout << left << setw(25) << songs[i].title << setw(25) << songs[i].artist << setw(4) << songs[i].year << endl;
    }
}