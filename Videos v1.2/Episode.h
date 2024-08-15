#ifndef EPISODE_H
#define EPISODE_H
#include "Video.h"
#include <string>
using namespace std;

class Episode : public Video {
protected:
  string seriesTitle;
  int epNumber;

public:
  Episode(const string& type, const string& id, const string& name, int duration, const string& genre, const string& seriesTitle, int epNumber);
  string getSeriesTitle() const;
  int getEpNumber() const;
  string getGenre() const override;
  string getType() const override;
  string toString() const override;
};

#endif