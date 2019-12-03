#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "./pages/OpenImage/OpenImage.h"
#include "./pages/ConvertImage/ConvertImage.h"
#include "./pages/SegmentImage/SegmentImage.h"

void router(int numberOfArgs, char *args[]) {

  char *functionality = args[1];
  char *imageRelativePath = args[2];

  if (strcmp(functionality, "-open") == 0)
    OpenImage(imageRelativePath);

  else if (strcmp(functionality, "-convert") == 0)
    ConvertImage(imageRelativePath, args[3]);

  else if (strcmp(functionality, "-segment") == 0) {
    if (numberOfArgs < 4) {
      printf("Error! Usage:\n");
      printf("\t-segment thr file.imm segfile.imm\n");
      exit(1);
    }
    SegmentImage(args[2], args[3], args[4]);
  }

  // else if (strcmp(functionality, "-cc") == 0)
  //
  // else if (strcmp(functionality, "-lab") == 0)

}
