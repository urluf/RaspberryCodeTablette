#ifndef _MODEL_H
	#define _MODEL_H

#include <string>
#include "../Observable.h"


class Model : protected Observable{


protected:
	typedef enum ePage{
		EVNMT,
		PLAN,
		EDT,
		PERSO,
		TRANSPORT,
		ORGA,
		HOME
	}Page;

	int numPage;
	Page currentPage;

protected:
	void pageSuivante();
	void pagePrecedente();
	void backToPage(int page);


public:
	Model();
	~Model();
	string getCurrentPage();
	int getNumPage();
};
#endif
