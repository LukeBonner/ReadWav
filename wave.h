#include <stdio.h>
#include <stdlib.h>

struct wavfile{
  unsigned char riff[4];
  unsigned int total_size;
  unsigned char wave[4];
  unsigned char fmt[4];
  unsigned int fmt_length;
  unsigned short fmt_type;
  unsigned short channels;
  unsigned int sample_rate;
  unsigned int byte_rate;
  unsigned short alignment;
  unsigned short bits_per_sample;
  unsigned char chunk_header[4];
  unsigned int data_sizel;
};

struct wavfile* parse(char *);
