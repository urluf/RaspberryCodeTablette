#include "Model.h"
#include "mButton.h"

Model::Model(){
	this->numPage = 1;
	this->currentPage = HOME;
}

Model::Model(Page page){
	this->numPage =1;
	switch(page){

	case HOME:
		this->currentPage = HOME;
		break;
	case EVNMT:
		this->currentPage = EVNMT;
		break;
	case PLAN:
		this->currentPage = PLAN;
		break;
	case EDT:
		this->currentPage = EDT;
		break;
	case PERSO:
		this->currentPage = PERSO;
		break;
	case TRANSPORT:
		this->currentPage = TRANSPORT;
		break;
	case ORGA:
		this->currentPage = ORGA;
		break;
	default:
		this->currentPage = HOME;
		break;
	}
}

void Model::pageSuivante(){
	this->numPage++;
}

void Model::pagePrecedente(){
	this->numPage--;
}

void Model::premierePage(){
	this->numPage = 1;
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
