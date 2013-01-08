#include "modelTan.h"


modelTan::modelTan(){
    vector<vector<char> > sources;
    sources.clear();

    populate_sources("2.txt", sources);

    for (size_t i = 0; i < sources.size(); ++i)
    {
        parse(&sources[i][0], INFOS_TRAFFIC);
    }
}

//charge les lignes de notre fichier dans la variable source
void modelTan::populate_sources(const char *filter, vector<vector<char> > &sources)
{
    char filename[256];

        sprintf(filename, filter);
        FILE *fp = fopen(filename, "rb");
        if (fp)
        {
            fseek(fp, 0, SEEK_END);
            int size = ftell(fp);
            fseek(fp, 0, SEEK_SET);
            vector<char> buffer(size + 1);
            fread (&buffer[0], 1, size, fp);
            fclose(fp);
            sources.push_back(buffer);
        }
}

//sauvegarde les données provenants du fichier json des horaires de bus dans notre tableau
void modelTan::saveHoraires(json_value *value, string name)
{
    if(value->name != NULL){
        name = value->name;
    }
    switch(value->type)
    {
    case JSON_OBJECT:
    case JSON_ARRAY:
        for (json_value *it = value->first_child; it; it = it->next_sibling)
        {
                saveHoraires(it, name);
        }
        break;
    case JSON_STRING:
        if(name.compare("heure")==0){
            addHeure(value->string_value);
        }
        else if(name.compare("passages")==0){
            addMinute(value->string_value);
        }
    }
}

//ajoute une heure au tableau
void modelTan::addHeure(string heure){
    Horaires horaire;
    horaire.heure = heure;
    this->lHoraires.push_back(horaire);
}

//ajoute une minute au tableau
void modelTan::addMinute(string minute){
    this->lHoraires.back().minutes.push_back(minute);
}

//sauvegarde les infos trafic dans notre tableau
void modelTan::saveInfosTraffic(json_value *value, string name){
    if(value->name != NULL){
        name = (value->name);
    }
    switch(value->type)
    {
    case JSON_OBJECT:
    case JSON_ARRAY:
        //printf(value->type == JSON_OBJECT ? "{\n" : "[\n");
        for (json_value *it = value->first_child; it; it = it->next_sibling)
        {
            saveInfosTraffic(it, name);
        }
        break;
    case JSON_STRING:
        if(name.compare("INTITULE")==0){
            addIntitule(value->string_value);
        }
        else if(name.compare("RESUME")==0){
            addResume(value->string_value);
        }
        else if((name.compare("DATE_DEBUT")==0)||(name.compare("HEURE_DEBUT")==0)){
            addDebut(value->string_value);
        }
        else if((name.compare("DATE_FIN")==0)||(name.compare("HEURE_FIN")==0)){
            addFin(value->string_value);
        }
        else if((name.compare("TRONCONS")==0)){
            addLigne(value->string_value);
        }
        break;
    }
}

void modelTan::addIntitule(string intitule){
    InfosTraffic infosTraffic;
    infosTraffic.intitule = intitule;
    infosTraffic.dateDeb = ""; //on initialise les dates pour pouvoir faire facilement les concaténations
    infosTraffic.dateFin = "";
    this->lInfos.push_back(infosTraffic);
}

void modelTan::addResume(string resume){
    this->lInfos.back().resume = resume;
}

void modelTan::addDebut(string debut){
    this->lInfos.back().dateDeb += " " + debut;
}

void modelTan::addFin(string fin){
    this->lInfos.back().dateFin += " " + fin;
}


void modelTan::addLigne(string ligne){
    //si la ligne concerné par l'info est une des lignes passant près de polytech, on ajoute, sinon on supprime
    if((ligne.find("72") != string::npos) || (ligne.find("76") != string::npos)){
        this->lInfos.back().ligne = ligne;
    }
    else{
        this->lInfos.pop_back();
    } 
}



//str.find(chaine) != npos alors trouvé!!!! popback() pour supprimer le denrier élément

//parse le fichier json voulu
bool modelTan::parse(char *source, parsing_type type)
{
    char *errorPos = 0;
    char *errorDesc = 0;
    int errorLine = 0;
    block_allocator allocator(1 << 10);
    
    json_value *root = json_parse(source, &errorPos, &errorDesc, &errorLine, &allocator);
    if (root)
    {
        if(type == HORAIRES){
            saveHoraires(root);
        }
        else if(type == INFOS_TRAFFIC){
            saveInfosTraffic(root);
        }

        return true;
    }

    return false;
}

//Attention: les deux dernières valeurs du tableau correspondent aux horaires du prochain bus!!!
vector<Horaires> modelTan::getHoraires(int numBus, int direction){
    this->lHoraires.clear();
    vector<vector<char> > sources;
    sources.clear();
    populate_sources("1.txt", sources);

    for (size_t i = 0; i < sources.size(); ++i)
    {
        parse(&sources[i][0], HORAIRES);
    }

    return this->lHoraires;
}

vector<InfosTraffic> modelTan::getInfosTraffic(){
    return this->lInfos;
}

modelTan::~modelTan(){

}