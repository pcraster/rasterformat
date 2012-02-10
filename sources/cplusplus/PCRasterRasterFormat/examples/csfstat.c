#include <stdio.h>
#include "csf.h"

/* write some features of
 * a map to stdout
 * use REAL8 (biggest type),
 * works for all maps.
 */

void main(int argc, char *argv[] )
{

  REAL8 min,max;
  MAP *map;                      

  if (argc != 2)
  {
   fprintf(stderr,"%s: no file specified\n",argv[0]);
   exit(1);
  }

  map = Mopen(argv[1], M_READ);
  if (map == NULL)  
  {  
     Mperror(argv[1]);
     exit(1);
  }

  RuseAs(map, CR_REAL8); 

  /* min/max value */
  printf("min/max (header): ");
  if (RgetMinVal(map,&min))
      printf("%g ",min);
  else
      printf("MV ");
  if (RgetMaxVal(map,&max))
      printf("%g \n",max);
  else
      printf("MV \n");

  Mclose(map);

  exit(0);
}
