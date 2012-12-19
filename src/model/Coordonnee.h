#ifndef COORDONNEE_H_
#define COORDONNEE_H_


class Coordonnee{


private: //donne le pourcentage du xMin d'un bouton....
	double xMin;
	double xMax;
	double yMin;
	double yMax;
public:
	Coordonnee(double XMin, double XMax, double YMin, double YMax);
	double getXMin();
	double getXMax();
	double getYMin();
	double getYMax();
};

#endif
