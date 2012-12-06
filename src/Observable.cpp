#include "Observable.h"


Observable::Observable(){

}

void Observable::addObserver(Observer* o){
	this->observers.insert(o);
}

void Observable::removeObserver(Observer* o){
	this->observers.erase(o);

}	

bool Observable::NotifyObservers(){

	  for (set<Observer*>::const_iterator it = observers.begin(); it != observers.end(); ++it)
	                        (*it)->update();
	  return observers.size()>0;

}

Observable::~Observable(){

}
