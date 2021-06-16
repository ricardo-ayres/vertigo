/*
Mapsize MUST be a value in the series
3, 5, 9, 17, 33, 65, 129, ... i.e.: 1+2^n , n>=1
*/
#define mapsize 65

void init_map();
float groundalt(float xg, float yg);
cartvektor groundnorm(float xg, float yg);
int map_vertex(int i, int j);
void init_waypoints();
cartvektor find_lowest_point();
void create_sea();
