#include "csf.h" 

extern void DoSomethingToFillTheMap(MAP *map);

void main(void) 
{    

 MAP *map; 

 /* create a boolean map named "map.dat"
  * with 250 rows and 200 columns
  * the projection has its y co-ordinate increasing
  * from top to bottom 
  * the top left co-ordinate is (X,Y) = (1200,1000)
  * the map is rotated counter clockwise 1.34 radians 
  * with the top left as rotation point
  * cells are 25 units wide
  */
 map = Rcreate("map.dat",250, 200, CR_UINT1, VS_BOOLEAN, 
                 PT_YINCT2B, 1200.0, 1000.0, 1.34, 25.0);

 if (map == NULL) 
 {     
  Mperror("map.dat"); 
  exit(1);
 }

 DoSomethingToFillTheMap(map);

 /* close CSF-file before exiting  
  */
 Mclose(map); 

 exit(0);
}
