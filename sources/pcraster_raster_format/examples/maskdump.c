#include <stdio.h>
#include <stdlib.h>
#include "csf.h"

/* a simple csf-mask to stdout
 * program, with minimal checking
 * a mask is boolean-map, here we
 * use version 1 compatibility. 
 */

void main(int argc, char *argv[] )
{

  UINT1 *row;
  MAP *map;                      
  size_t r,c;

  if (argc != 2)
  {
   fprintf(stderr,"%s: no file specified\n",argv[0]);
   exit(1);
  }

  map = Mopen(argv[1], M_READ);

  if (! RvalueScaleIs(map, VS_BOOLEAN))
  {    /* it's not VS_BOOLEAN, VS_CLASSIFIED 
        * or VS_NOTDETERMINED 
        */
       fprintf(stderr,"'%s' is not a boolean map\n",argv[1]);
       exit(1);
  }

  RuseAs(map, VS_BOOLEAN); 
  row = (UINT1 *)Rmalloc(map, RgetNrCols(map));

  for(r=0; r < RgetNrRows(map); r++)
  {
   RgetRow(map, r, row);
   for(c=0; c < RgetNrCols(map); c++)
     printf("%d ",(int)row[c]);
   printf("\n");
  }

  free(row);
  Mclose(map);

  exit(0);
}
