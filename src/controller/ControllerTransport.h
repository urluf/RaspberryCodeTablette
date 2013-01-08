/*
 * ControllerTransport.h
 *
 *  Created on: 11 déc. 2012
 *      Author: developpeur
 */
#ifndef CONTROLLERTRANSPORT_H_
#define CONTROLLERTRANSPORT_H_

#include "ControllerGeneral.h"
#include "../graphic/LayoutTransport.h"

class ControllerTransport : public ControllerGeneral{
public:
	ControllerTransport(double width, double height);
	~ControllerTransport();

	virtual string setDisplay(string titleButton);
	string action(double x, double y);

};


#endif /* CONTROLLERTransport_H_ */
