#include "BMP.h"
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
  void increment_brightness(u_int8_t* pixel_data, int32_t data_size);
  void inverse_colors(u_int8_t* pixel_data, int32_t data_size);
  void increment_saturation(u_int8_t* pixel_data, int32_t data_size);
#ifdef __cplusplus
}
#endif

int main(int argc, char *argv[]) {
  if (argc == 4) {
    BMP_Image* new_image = read_BMP(argv[1]);
    int filter = atoi(argv[3]);
    printf("El valor de filter es: %i\n",filter);
    if(new_image != NULL) {
      printf("New bmp image has been created.\n");
      printf("Next, the filter will be applied.\n");
      if(filter == 1) {
        increment_brightness(new_image->pixel_data,new_image->data_size);
        printf("The increase brightness filter has been applied to the image.\n");
      } else {
        if(filter == 2) {
          inverse_colors(new_image->pixel_data,new_image->data_size);
          printf("The inverse color filter has been applied to the image.\n");
        } else {
          if(filter == 3) {
            increment_saturation(new_image->pixel_data,new_image->data_size);
            printf("The increase saturation filter has been applied to the image.\n");
          } else {
            printf("The filter you choosed doesn't exist. No filter has been applied to the image.\n");
          }
        }
      }
      printf("Now, its time to save it.\n");
      save_BMP(new_image,argv[2]);
      printf("New copy of the image has been created. Check it out on the folder for this program.\n");
      free(new_image->pixel_data);
      free(new_image);
    }
  } else {
    printf("Usage: ./program name_of_BMP.bmp name_of_BPM_copy.bmp filter_number\nFor example: ./program Homero.bmp Homero_copy.bmp 1\nFilter 1: increase brightness filter.\nFilter 2: inverse color filter.\nFilter 3: increase saturation filter.\n");
  }

  return 0;
}