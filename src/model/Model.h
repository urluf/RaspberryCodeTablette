#ifndef _MODEL_H
	#define _MODEL_H

#include <string>
#include "../Observable.h"


class Model : protected Observable{


public:
	typedef enum ePage{
		EVNMT,
		PLAN,
		EDT,
		PERSO,
		TRANSPORT,
		ORGA,
		HOME
	}Page;


protected:
	int numPage;
	Page currentPage;

public:
	Model();
	Model(Page page);
	~Model();
	string getCurrentPage();
	int getNumPage();
	void pageSuivante();
	void pagePrecedente();
	void backToPage(int page);
	void premierePage();
};
#endif
