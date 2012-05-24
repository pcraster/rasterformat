#include "csf.h" 

void main(void) 
{    

 MAP *map; 

 map = Rcreate("test.map",100,80,
       CR_UINT1, VS_BOOLEAN, PT_YINCT2B, 0.0,0.0,0.0,1.0); 

 if (map == NULL) 
 {     
  Mperror("map.dat"); 
  exit(1);
 }

 Mclose(map);  /* close CSF-file before exiting  */
 exit(0);

}
