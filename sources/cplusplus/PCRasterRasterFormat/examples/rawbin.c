
#include <stdio.h>
#include "csf.h"

/* a simple raw binary to csf
 * program, with minimal checking
 * for example 512*512 b/w image
 * stored in byte format
 */

void main(int argc, char *argv[] )
{

  FILE *in;
  MAP  *out;                      
  size_t r,c;
  UINT1 val;

  if (argc != 2)
  {
   fprintf(stderr,"%s: no file specified\n",argv[0]);
   exit(1);
  }

  in = fopen(argv[1], "rb");
  out = Rcreate(argv[2], 512, 512, CR_UINT1, VS_BOOLEAN, 
                 PT_YINCT2B, 0.0, 0.0, 0.0, 100.0);

  for(r=0; r < 512; r++)
   for(c=0; c < 512; c++)
   {
       fread(&val, 1, 1, in);
       val = (val != 0);
       RputCell(out,r,c,&val); 
   }

  fclose(in);
  Mclose(out);

  exit(0);
}
