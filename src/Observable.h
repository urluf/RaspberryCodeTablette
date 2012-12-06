#ifndef _OBSERVABLE_H	
	#define _OBSERVABLE_H

#include <set>
#include <algorithm>
#include "Observer.h"

using namespace std;

class Observable{
private:
	set<Observer*> observers;
public:
	~Observable();
protected:
	Observable();
	void addObserver(Observer* o);
	void removeObserver(Observer* o);
	bool NotifyObservers();
private:
	Observable(const Observable& o);
	Observable& operator=(const Observable& o);
};

#endif
