/*
 * ControllerTransport.h
 *
 *  Created on: 11 déc. 2012
 *      Author: developpeur
 */

#include "ControllerGeneral.h"

#ifndef CONTROLLERTRANSPORT_H_
#define CONTROLLERTRANSPORT_H_

class ControllerTransport : public ControllerGeneral{
public:
	ControllerTransport(double width, double height, const char * logo, double maxW,double maxH, SShaders* Shaders );
	~ControllerTransport();

	virtual void display();
	virtual void setDisplay(double x, double y);
	bool action(double x, double y);

private:
	void createButtons();

};


#endif /* CONTROLLERTransport_H_ */
