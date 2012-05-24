#include "csf.h"

/* make a boolean map 
 * with minimal checking
 */

void main(int argc, char *argv[] )
{

  REAL8 inValue;
  UINT1 outValue;
  MAP *in, *out;                      
  size_t r,c;

  if (argc != 2)
  {
   fprintf(stderr,"%s: no file specified\n",argv[0]);
   exit(1);
  }

  in = Mopen(argv[1], M_READ);
  if (in == NULL)  
  {  
     Mperror(argv[1]);
     exit(1);
  }
  RuseAs(in, CR_REAL8); 
  out = Rdup(argv[2], in, CR_UINT1, VS_BOOLEAN);
  if (out == NULL)  
  {  
     Mperror(argv[2]);
     exit(1);
  }

  for(r=0; r < RgetNrRows(in); r++)
   for(c=0; c < RgetNrCols(in); c++)
   {
    RgetCell(in,r,c,&inValue); 
    if (IS_MV_REAL4(&inValue))
     outValue = MV_UINT1;
    else
     outValue = inValue > 0;
    RputCell(out,r,c,&outValue); 
   }

  Mclose(in);
  Mclose(out);

  exit(0);
}
