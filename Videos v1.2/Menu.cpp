#include "Menu.h"
#include "Episode.h"
#include "Movie.h"
#include "Video.h"
#include <algorithm>
#include <iomanip>
using namespace std;

Menu::Menu() {}

Menu::~Menu() {
  for (Video *video : videos) {
    delete video;
  }
}

void Menu::loadFile(const string& fileName) {
  ifstream file(fileName);
  if (!file) {
    cout << "Could not open the file." << endl;
  } else {
    string line;
    while (getline(file, line)) {
      stringstream ss(line);
      string type, id, name, duration, genre;

      getline(ss, type, ',');
      getline(ss, id, ',');
      getline(ss, name, ',');
      getline(ss, duration, ',');
      getline(ss, genre, ',');

      //Delete blank spaces that could affect the text file
      genre.erase(genre.find_last_not_of(" \n\r\t") + 1);

      if (type == "p") {
        int duratioon = stoi(duration);
        videos.push_back(new Movie(type, id, name, duratioon, genre));
      } else if (type == "c") {
        string seriesTitle, epNumber;
        getline(ss, seriesTitle, ',');
        getline(ss, epNumber, ',');

        //Delete blank spaces that could affect the text file
        seriesTitle.erase(seriesTitle.find_last_not_of(" \n\r\t") + 1);
        epNumber.erase(epNumber.find_last_not_of(" \n\r\t") + 1);

        int duratioon = stoi(duration);
        int epNumbeer = stoi(epNumber);
        videos.push_back(new Episode(type, id, name, duratioon, genre,
                                      seriesTitle, epNumbeer));
      }
    }
  }
}

void Menu::showVideos() const {
  for (Video *video : videos) {
    cout << video->toString() << endl;
  }
}
void Menu::rateVideo(const string& id, int rating,
                                Menu& menu) {
  for (Video *video : menu.videos) {
    if (video->getId() == id) {
      video->addRating(rating);
      cout << "\nSuccesfuly added the rating\n" << endl;
      return;
    }
  }
  cout << "The video with the provided ID was not found." << endl;
}
void Menu::showByRating(int minRating,
                                        int videoType) const {
  for (Video *video : videos) {
    if (video->getAvgRating() >= minRating &&
        (videoType == 3 || (videoType == 1 && video->getType() == "p") ||
         (videoType == 2 && video->getType() == "c"))) {
      if (video->getAvgRating() == 0.0) {
      } else {
        cout << video->toString() << endl;
      }
    }
  }
}
void Menu::showByGenre(const string& selectedGenre,
                                  int videoType) const {
  for (Video *video : videos) {
    if (videoType == 3 || (videoType == 1 && video->getType() == "p") ||
        (videoType == 2 && video->getType() == "c")) {
      if (video->getGenre() == selectedGenre) {
        cout << video->toString() << endl;
      }
      }
    }
  }