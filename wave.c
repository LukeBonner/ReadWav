#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "wave.h"
#include "file.h"

#define TRUE 1
#define FALSE 0
struct wavfile* parse(char *);


unsigned char buffer4[4];
unsigned char buffer2[2];

int j = 0;
char *fileloc;
char *outFile;
char *filename;
int filesize;
struct wavfile wav;

/*
a large amount of this code is a manipulation and explanation of
http://truelogic.org/wordpress/2015/09/04/parsing-a-wav-file-in-c/
(by manipulation, this code is based off of the source and changed to fit
our program specifications)

*/

int main(int argc, char** argv){
  *fileloc = (char *) malloc(sizeof(char) *1024);
  //malloc is free, fly my pretty!


  filesize = read_file(fileloc,argv);

  free(fileloc);

}



struct wavfile* parse(char* contents){

  for(int i = 0; i <filesize;i++){
    j++;
    if(i>=0 && i <=4){
      wav.riff[i]=contents[i];
    }
    if(i>=5 && i <=8){
      wav.total_size +=contents[i];
    }
    wav.total_size -= 8;

    if(i>=9 && i <=12){
      wav.wave[j-i] = contents[i];

    }

    if(i>=13 && i <=16){
      wav.fmt[j-i] = contents[i];

    }
    if(i>=17 && i <=19){
      wav.fmt_length += contents[i];
    }
    if(i>=20 && i <=21){
      wav.fmt_type += contents[i];
    }
    if(i>=22 && i <=23){
      wav.channels += contents[i];
    }
    if(i>=24 && i <=27){
      wav.sample_rate += contents[i];
    }
    if(i>=28 && i <=31){
      wav.byte_rate += contents[i];
    }
    if(i>=32 && i <=33){
      wav.alignment += contents[i];
    }
    if(i>=34 && i <=35){
      wav.bits_per_sample += contents[i];
    }

    if(i>=36 && i <=39){
      wav.chunk_header[j-i]=contents[i];

    }
    if(i>=40 && i <=43){
      wav.data_sizel += contents[i];
    }
    if(i=43){
      wav.sound_data = malloc(sizeof(char) * wav.data_sizel);
    }

    if(i>43){
      wav.sound_data[j-i] = contents[i];

    }
  }

  char* outString = malloc(sizeof(char) * wav.data_sizel);

  write_file(outFile,outString,wav.total_size);
  return wav.data_sizel;
  free(wav.sound_data);


}
