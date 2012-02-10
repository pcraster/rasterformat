#include <stdlib.h>
#include "csf.h"
 
/* process a raster in 
 * chunks of 2 rows
 * assuming an even number of rows
 */
 
extern void DoThatWithIt(REAL4 * , size_t );

void main(int argc, char *argv[] )
{
 
  REAL4 *buf;
  MAP *map;                      
  size_t r, nrCols;
  size_t chunkSize;
 
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

  nrCols = RgetNrCols(map); 
  chunkSize = 2*nrCols; 

  (void)RuseAs(map, CR_REAL4); 

  buf = (REAL4 *)Rmalloc(map, chunkSize);

  for(r=0; r < RgetNrRows(map); r += 2)
  {
    RgetSomeCells(map, r*nrCols, chunkSize, buf); 
    DoThatWithIt(buf, chunkSize);
    RputSomeCells(map,r*nrCols, chunkSize, buf); 
  }

  Mclose(map);
  free(buf);

  exit(0);
}
