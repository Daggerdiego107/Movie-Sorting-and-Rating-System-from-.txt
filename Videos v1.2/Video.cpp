#include "Video.h"
#include <iomanip>
#include <numeric>
#include <sstream>
using namespace std;

Video::Video(const string& type, const string& id, const string& name, int duration, const string& genre): type(type), id(id), name(name), duration(duration), genre(genre){}

string Video::getId() const{
  return id; 
}
string Video::getName() const{
  return name;
}
int Video::getDuration() const{
  return duration;
}
string Video::getGenre() const{
  return genre;
}
double Video::getAvgRating() const{
  if (ratings.empty())
    return 0.0;
  return accumulate(ratings.begin(), ratings.end(), 0.0) / ratings.size();
}
void Video::addRating(int rating){
  ratings.push_back(rating);
}

ostream &operator<<(ostream& os, const Video& video){
  double avgRating = video.getAvgRating();
  if (avgRating == 0.0) {
    os << video.getType() << "," << video.id << "," << video.name << "," << video.duration << "," << video.genre << "," << "NR";
  } else {
    os << video.getType() << "," << video.id << "," << video.name << "," << video.duration << "," << video.genre << "," << fixed << setprecision(1) << avgRating;
  }
  return os;
}

string Video::toString() const{
  stringstream ss;
  ss << "Type: " << type << endl;
  ss << "ID: " << id << endl;
  ss << "Name: " << name << endl;
  ss << "Duration: " << duration << " minutes" << endl;
  ss << "Genre: " << genre << endl;
  double avgRating = getAvgRating();
  if (avgRating == 0.0){
    ss << "Average Rating: " << "NR" << endl;
  }else{
    ss << "Average Rating: " << fixed << setprecision(1) << getAvgRating() <<endl;
  }
  return ss.str();
}

string Video::getType() const{
  return type;
}