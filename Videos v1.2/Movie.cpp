#include "Movie.h"
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

Movie::Movie(const string& type, const string& id, const string& name, int duration, const string& genre): Video(type, id, name, duration, genre){}

string Movie::getGenre() const {
    return genre;
}

string Movie::getType() const{
  if (type=="p"){
    return "Movie";
  } else {
    return "Movie";
  }
}

string Movie::toString() const{
  stringstream ss;
  ss << "\nType: " << getType()<< endl;
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