#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/misc/Miscelaneous.h"

#include "./routes.h"

int main(int argc, char *argv[]) {
  printSoftwareTitle();

  if (argc < 3 && argc >= 2) {
      printf("Error, No files passed! Usage: ./imm -option file\n");
      exit(1);
  } else if (argc == 1) {
    printf("Error! Usage:\n");
    printf("\t-open file.txt\n");
    printf("\t-open file.imm\n");
    printf("\t-segment thr file.imm segfile.imm\n");
    printf("\t-cc segfile.im outfile\n");
    printf("\t-lab imlab.txt imlabout.txt\n");
    exit(1);
  }

  router(argc, argv);

  return 0;
}
