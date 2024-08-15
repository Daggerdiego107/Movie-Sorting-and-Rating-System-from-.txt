#ifndef VIDEO_H
#define VIDEO_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Video {
protected:
  string type;
  string id;
  string name;
  int duration;
  string genre;
  vector<int> ratings;
public:
  Video() = default;
  Video(const string& type, const string& id, const string& name, int duration, const string& genre);
  virtual ~Video() = default;
  string getId() const;
  string getName() const;
  int getDuration() const;
  virtual string getGenre() const;
  double getAvgRating() const;
  void addRating(int rating);
  virtual string getType() const;
  virtual string toString() const;

friend ostream& operator<<(ostream& os, const Video& video);
};

#endif