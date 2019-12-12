#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Miscelaneous.h"

void printSoftwareTitle() {
    printf("  _____   __  __   __  __ \n |_   _| |  \\/  | |  \\/  |\n   | |   | \\  / | | \\  / |\n   | |   | |\\/| | | |\\/| |\n  _| |_  | |  | | | |  | |\n |_____| |_|  |_| |_|  |_|\n\n\n");
}

int checkFileFormat(char *filePath) {
  int fileNameLength = strlen(filePath);
  if (filePath[fileNameLength-1] == 't') {
    if (filePath[fileNameLength-2] == 'x') {
      if (filePath[fileNameLength-3] == 't') {
        if (filePath[fileNameLength-4] == '.')
          return 0;
      }
    }
  } else if (filePath[fileNameLength-1] == 'm') {
    if (filePath[fileNameLength-2] == 'm') {
      if (filePath[fileNameLength-3] == 'i') {
        if (filePath[fileNameLength-4] == '.')
          return 1;
      }
    }
  }

  return -1;
}

void addFormat(char *filePath, int fileFormat) {
  if (fileFormat == 1)
    strcat(filePath, ".imm");
  if (fileFormat == 0)
    strcat(filePath, ".txt");
}
