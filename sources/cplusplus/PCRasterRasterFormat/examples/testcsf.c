#include <stdio.h>
#include "csf.h"

/* test if files are CSF files
 * writing error messages to
 * stdout  
 */

void main(int argc, char *argv[] )
{
  MAP *map;
  int i;

  for(i=1; i < argc; i++)
    if ((map = Mopen(argv[1], M_READ)) == NULL)
    {
        printf("%s %s\n", argv[i], MstrError());
        ResetMerrno();
    }
    else
    {
        printf("%s is a CSF file\n",argv[i]);
        Mclose(map);
    }

  exit(0);
}
