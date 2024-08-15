#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "Video.h"
using namespace std;

class Movie: public Video{
public:
  Movie(const string& type, const string& id, const string& name, int duration, const string& genre);
  string getGenre() const override;
  string getType() const override;
  string toString() const override;
};

#endif