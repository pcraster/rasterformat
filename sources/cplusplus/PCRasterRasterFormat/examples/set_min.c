#include <stdio.h>
#include "csf.h"

/* set header min/max of a scalar map
 * to 0 and 1, since it's a membership
 * function
 */

void main(int argc, char *argv[] )
{
  MAP *map;
  REAL8 min,max;

  if (argc != 2)
  {
   fprintf(stderr,"%s: no file specified\n",argv[0]);
   exit(1);
  }

  if ((map = Mopen(argv[1], M_READ_WRITE)) == NULL)
    {
        Mperror(argv[1]);
        exit(1);
    }
  
  if ( (! RvalueScaleIs(map, VS_SCALAR))
       || RuseAs(map, CR_REAL8) )
  {
   fprintf(stderr,"%s is not a scalar map\n", argv[1]);
   exit(1);
  }
  
  if ( RgetMinVal(map, &min) &&
       RgetMaxVal(map, &max) &&
       min >= 0 && max <= 1)
  {
   min = 0; max = 1;
   RputMinVal(map,&min);
   RputMaxVal(map,&max);
  }
  else {
   fprintf(stderr,
           "%s: min/max not set or not in [0, 1]\n",
           argv[1]);
   exit(1);
  }
  Mclose(map);
  exit(0);
}
