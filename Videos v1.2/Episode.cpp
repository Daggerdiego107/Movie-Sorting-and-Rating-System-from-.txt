#include "Episode.h"
#include <iomanip>
using namespace std;

Episode::Episode(const string& type, const string& id, const string& name, int duration,const string& genre, const string& seriesTitle, int epNumber): Video(type, id, name, duration, genre), seriesTitle(seriesTitle), epNumber(epNumber) {}

string Episode::getSeriesTitle() const {
    return seriesTitle;
}
int Episode::getEpNumber() const{
    return epNumber;
}
string Episode::getType() const{
  if (type=="c"){
    return "Episode";
  } else {
    return "Episode";
  }
}
string Episode::getGenre() const {
    return genre;
}
string Episode::toString() const{
  stringstream ss;
  ss << "\nType: " << getType() << endl;
  ss << "ID: " << id << endl;
  ss << "Name: " << name << endl;
  ss << "Duration: " << duration << " minutes" << endl;
  ss << "Genre: " << genre << endl;
  ss << "Series Title: " << seriesTitle << endl;
  ss << "Episode Number: " << epNumber << endl;
  double avgRating = getAvgRating();
  if (avgRating == 0.0){
    ss << "Average Rating: " << "NR" << endl;
  }else{
    ss << "Average Rating: " << fixed << setprecision(1) << getAvgRating() <<endl;
  }
  return ss.str();
}