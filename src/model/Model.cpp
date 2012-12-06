#include "Model.h"


Model::Model(){
	this->numPage = 1;
	this->currentPage = HOME;
}

void Model::pageSuivante(){
	this->numPage++;
}

void Model::pagePrecedente(){
	this->numPage--;
}

string Model::getCurrentPage(){

	switch(this->currentPage){

	case HOME:
		return "home";
	case EVNMT:
		return "evnmt";
	case PLAN:
		return "plan";
	case EDT:
		return "edt";
	case PERSO:
		return "perso";
	case TRANSPORT:
		return "transport";
	case ORGA:
		return "orga";
	default:
		return "home";
	}
}

int Model::getNumPage(){
	return this->numPage;
}

void Model::backToPage(int page){
	this->numPage = page;
}

Model::~Model(){

}
