#ifndef MODELTAN_H
#define MODELTAN_H

#include <string>
#include <stdio.h>
#include <fstream>
#include <vector>
#include "../../include/vjson/json.h"

using namespace std;

#define IDENT(n) for (int i = 0; i < n; ++i) printf("    ")

struct Horaires{
	string heure;
	vector<string> minutes;
};

struct InfosTraffic{
	string intitule;
	string dateDeb;
	string dateFin;
	string resume;
	string ligne;  //ligne de bus
};

//class servant à lire les fichiers JSON de la TAN fournit par l'open data
class modelTan{

private:
	enum parsing_type{
		HORAIRES,
		INFOS_TRAFFIC,
	};

private:
	vector<Horaires> lHoraires; //contient la liste des horaires pour les arrêts de polytech
	vector<InfosTraffic> lInfos;//contient la liste des infos pour les bus passant près de polytech

public:
	modelTan();
	~modelTan();
	vector<Horaires> getHoraires(int numBus, int direction); //renvoi les horaires du bus. Les deux dernières valeurs du tableau correspondent aux horaires du prochain
	vector<InfosTraffic> getInfosTraffic();

private:
	void addHeure(string heure);
	void addMinute(string minute);
	void addIntitule(string intitule);
	void addDebut(string debut);
	void addFin(string fin);
	void addResume(string resume);
	void addLigne(string ligne); //ajoute la ligne de bus si elle passe près de polytech seulement!! Sinon n'ajoute pas l'info trafic!!
	bool parse(char *source, parsing_type type);
	void saveHoraires(json_value *value, string name = "");
	void saveInfosTraffic(json_value *value, string name = "");
	void populate_sources(const char *filter, std::vector<std::vector<char> > &sources);
};

#endif