#include "BMP.h"


BMP_Image* read_BMP(const char* file_name) {
  FILE* input_file;
  BMP_Image* new_image = NULL;
  input_file = fopen(file_name,"rb"); // Open FILE in read binary.
  if(input_file != NULL) { // Check that file could be opened.
    printf("Loading image [%s]...\n",file_name);
    new_image = (BMP_Image*) malloc(sizeof(BMP_Image)); // Allocate memory for the new Image.
    if(new_image != NULL) {
      fread(&(new_image->file_header),sizeof(BMP_File_Header),1,input_file); // Read the file header from the image.
      fread(&(new_image->info_header),sizeof(BMP_Info_Header),1,input_file); // Read the info header from the image.
      new_image->data_size = new_image->file_header.file_size - (sizeof(BMP_File_Header) + sizeof(BMP_Info_Header));
      new_image->bytes_per_pixel = new_image->info_header.bit_count/8;
      printf("-> Size of non metadata: %i.\n",new_image->data_size);
      printf("-> Witdh from image: %i.\n",new_image->info_header.width);
      printf("-> Height from image: %i.\n",new_image->info_header.height);
      printf("-> Bytes per pixel: %i.\n",new_image->bytes_per_pixel);
      // Now its time to read the pixel data.
      // But first, we need to allocate memory for the array that will contain these info.
      new_image->pixel_data = (u_int8_t *) malloc(sizeof(u_int8_t) * (new_image->data_size));
      if(new_image->pixel_data != NULL) {
        fread(new_image->pixel_data,3,new_image->data_size,input_file);
        printf("-> Pixel data has been read\n");
      } else {
        printf("Error: Memory for the pixel data couldn't be allocated.");
      }
    } else {
      printf("Error: Memory for the new image couldn't be allocated.");
    }
  } else {
    printf("Error: File couldn't be opened.\n");
  }
  fclose(input_file);
  return new_image;
}

void save_BMP(BMP_Image* bmp_image,const char* file_name) {
  FILE* output_file;
  output_file = fopen(file_name,"w"); // Open the file on write mode.
  if(output_file != NULL) { // Check if output_files could be opened.
    fwrite(&(bmp_image->file_header),sizeof(BMP_File_Header),1,output_file);
    fwrite(&(bmp_image->info_header),sizeof(BMP_Info_Header),1,output_file);
    printf("-> Wrote the metadata to new image.\n");
    // Write the pixel data to the output_file.
    fwrite(bmp_image->pixel_data,sizeof(unsigned char),bmp_image->data_size,output_file);
    printf("-> Wrote the pixel data to new image.\n");
  }
  printf("-> Finished creating new image.\n");
  fclose(output_file);
  return;
}
