
#include <stdlib.h>
#include "csf.h"

/* process a raster per row
 * minimal checking
 */

extern void DoThatWithRow(REAL4 *, size_t );

void main(int argc, char *argv[] )
{

  REAL4 *buf;
  MAP *map;                      
  size_t r;
  size_t nrOfCells;

  if (argc != 2)
  {
   fprintf(stderr,"%s: no file specified\n",argv[0]);
   exit(1);
  }

  map = Mopen(argv[1], M_READ_WRITE);
  if (map == NULL)  
  {  
     Mperror(argv[1]);
     exit(1);
  }

  nrOfCells = RgetNrCols(map); 

  (void)RuseAs(map, CR_REAL4); 

  buf = (REAL4 *)Rmalloc(map, nrOfCells);

  for(r=0; r < RgetNrRows(map); r++ )
  {
    RgetRow(map, r, buf); 
    DoThatWithRow(buf, nrOfCells);
    RputRow(map,r, buf); 
  }

  Mclose(map);
  free(buf);

  exit(0);
}
