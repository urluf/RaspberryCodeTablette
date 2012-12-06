#ifndef _OBSERVER_H
	#define _OBSERVER_H

#include "Observable.h"

class Observer{

public:
virtual void update() = 0;
virtual ~Observer();

};
#endif
