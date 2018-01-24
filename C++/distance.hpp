#ifndef   DISTANCE_HPP
#define   DISTANCE_HPP

#define LONG_RADIUS 6378137.000
#define SHORT_RADIUS 6356752.314140
#define M_PI 3.14159265358979
#define deg_to_rad(deg) ((deg) / 180 * M_PI)

enum ECoordinate {
	X = 0,
	Y = 1,
};

enum EOrder {
	FIRST = 0,
	SECOND = 1,
};

class Distance{
private:
	double coordinate[2][2];
	double longitude_diff, latitude_diff, latitude_ave, 
		eccentricity, w, radius_of_prime_vertical_circle, meridian_radius_of_curvature, distance;
public:
	void getCoordinate(double latitude, double logitude, int i);
	double calculateDistance();
};

void Distance::getCoordinate(double logitude, double latitude, int i) {
	coordinate[i][X] = logitude;
	coordinate[i][Y] = latitude;
}
double Distance::calculateDistance() {
	longitude_diff = deg_to_rad(coordinate[SECOND][X] - coordinate[FIRST][Y]);
	latitude_diff = deg_to_rad(coordinate[SECOND][Y] - coordinate[FIRST][Y]);
	latitude_ave = deg_to_rad((coordinate[FIRST][Y] + coordinate[SECOND][Y]) / 2);

	eccentricity = 1 - pow(SHORT_RADIUS, 2) / pow(LONG_RADIUS, 2);
	w = sqrt(1 - eccentricity * pow(sin(latitude_ave), 2));
	radius_of_prime_vertical_circle = LONG_RADIUS / w;
	meridian_radius_of_curvature = (LONG_RADIUS * (1 - eccentricity)) / pow(w, 3);
	distance = sqrt(pow(latitude_diff * meridian_radius_of_curvature, 2)
		+ pow(longitude_diff * radius_of_prime_vertical_circle * cos(latitude_ave), 2));

	return distance;
}
#endif