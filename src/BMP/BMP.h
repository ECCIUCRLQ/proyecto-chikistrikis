#ifndef BMP_H
#define BMP_H
#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)
typedef struct {
  u_int16_t file_type;
  u_int32_t file_size;
  u_int16_t reserved_1;
  u_int16_t reserved_2;
  u_int32_t data_offset;
} BMP_File_Header;

typedef struct {
  u_int32_t header_size;
  int32_t width;
  int32_t height;
  u_int16_t planes;
  u_int16_t bit_count;
  u_int32_t image_compression;
  u_int32_t image_size;
  int32_t horizontal_resolution;
  int32_t vertical_resolution;
  u_int32_t colors_used;
  u_int32_t important_colors;
} BMP_Info_Header;

#pragma pop(1)

typedef struct {
  BMP_File_Header file_header;
  BMP_Info_Header info_header;
  int32_t data_size;
  u_int16_t bytes_per_pixel;
  unsigned char* pixel_data; 
} BMP_Image;

BMP_Image* read_BMP(const char* file_name);
void save_BMP(const BMP_Image* bmp_image,const char* file_name);
#endif