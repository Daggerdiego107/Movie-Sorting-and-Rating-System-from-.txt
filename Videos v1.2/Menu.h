#ifndef MENU_H
#define MENU_H
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Movie.h"
#include "Episode.h"
#include "Video.h"
using namespace std;

class Menu: public Video{
protected:
  vector<Video*> videos;
public:
  Menu ();
  ~Menu();
  void loadFile(const string& fileName);
  void showVideos() const;
  void rateVideo(const string& id, int calificacion, Menu& menu);
  void showByRating(int minRating, int videoType) const;
  void showByGenre(const string& selectedGenre, int videoType) const;
};
#endif