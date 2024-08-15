#include "Video.h"
#include "Episode.h"
#include "Movie.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
  Menu menu;
  menu.loadFile("videos.txt");
  int option=0;

  do{
  cout << "Welcome to the OOP Streaming Platform\n";
  cout << "1. Show all the menu\n"; 
  cout << "2. Rate a Movie / Series Episode\n";
  cout << "3. Show Movie / Series Episode by Rating\n"; 
  cout << "4. Show Movie / Series Episode by Genre\n"; 
  cout << "5. Exit\n"; 
  cin >> option;
  switch(option){
    case 1: 
      cout << "Show all the menu" << endl;
      menu.showVideos();
      break;
    case 2: {
      string id;
      int rating;
      cout << "Rate a Video" << endl;
      cout << "Type in the Video ID: "; cin >> id;
      do {
        cout << "Type in the Rating (0-5): "; cin >> rating;
      } while (rating < 1 || rating > 5);
      menu.rateVideo(id, rating, menu);
      break;
    }  
    case 3: {
      int minRating;;
      int videoType;
      cout << "Show Movie / Series Episode by Rating" << endl;
    do {
      cout << "Type in the video type, (1) Movie , (2) Episodes , (3) Both: "; cin >> videoType;} while (videoType < 1 || videoType > 3);
      cout << "Type in the minimum rating: "; cin >> minRating;
      menu.showByRating(minRating, videoType);
    break;
  }
    case 4: {
      string selectedGenre;
      int videoType;
      cout << "Show Movie / Series Episode by Genre" << endl;
      do{
        cout << "Type in the video type, (1) Movie , (2) Episodes , (3) Both: "; cin >> videoType;} while (videoType < 1 || videoType > 3);
      cout << "Type in the genre: "; cin >> selectedGenre;
      menu.showByGenre(selectedGenre, videoType);
      break;
      }
    case 5:
      cout << "Exiting..." << endl;
      break;
    default:
      cout << "Invalid Option" << endl;
      break;
    }
  }    while (option != 5);
  return 0;
}
