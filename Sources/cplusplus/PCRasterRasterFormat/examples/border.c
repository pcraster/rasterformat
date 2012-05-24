
#include <stdlib.h>
#include "csf.h"

/* set border to MV
 * with minimal checking
 */

void main(int argc, char *argv[] )
{
  MAP *map;                      
  void *mv;
  size_t i,nrRows,nrCols;

  if (argc != 2)
  {
   fprintf(stderr,"%s: no file specified\n",argv[0]);
   exit(1);
  }

  map = Mopen(argv[1], M_READ_WRITE);
  RuseAs(map, CR_REAL8); 

  mv = Rmalloc(map, 1);
  SetMV(map, mv);

  nrRows = RgetNrRows(map);
  nrCols = RgetNrCols(map);

  for(i=0; i < RgetNrCols(map); i++) { 
   RputCell(map, 0       , i, mv);
   RputCell(map, nrRows-1, i, mv);
  }
  for(i=0; i < RgetNrRows(map); i++) { 
   RputCell(map, i, 0       , mv);
   RputCell(map, i, nrCols-1, mv);
  }

  free(mv);
  Mclose(map);

  exit(0);
}
