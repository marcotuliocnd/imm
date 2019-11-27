#include "ImageMap.h"

struct image {
    String fileName;
    FILE *imageFilePointer;
};

Image *openTextImage() {

}

void closeImage(Image *image) {
    fclose(image->imageFilePointer);
}