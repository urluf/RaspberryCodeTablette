#ifndef LAYOUT_H
#define LAYOUT_H

#include "../model/mButton.h"
#include "../EnumTypeButton.h"
#include "../Observer.h"
#include <list>

using namespace std;

class Layout : public Observer
{

protected:
	int nbButtonSquare;
	list<mButton*> lButtons;

public:
	Layout();
	virtual ~Layout();
	virtual int getNbButtonSquare();
	virtual list<mButton*> getButtons();
	
};


#endif
