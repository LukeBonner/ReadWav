#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "wave.h"
#include "file.h"

#define TRUE 1
#define FALSE 0


/*
a large amount of this code is a manipulation and explanation of
http://truelogic.org/wordpress/2015/09/04/parsing-a-wav-file-in-c/
(by manipulation, this code is based off of the source and changed to fit
our program specifications)


Also worked on in conjunction with Cade Snuffer, some code solutions will
look similar.
*/


/**
  Main will hold our file loc and begin to call all of the functions that
  we need to read in, manipulate ( parse ), and write out our wav file

*/
int main(int argc, char** argv){
  char *fileloc = "/mnt/c/Shchool Shtuff/CIS343/343readWav/reversed_message.wav";
  /*
  size_t size = 300;

  while(!feof(stdin)){
    fileloc = ((char*)malloc(sizeof(char)*300));
    getline(&fileloc,&size,stdin);
  }
  //malloc is free, fly my pretty!
  */
  //making our buffer that will hold all of our intitial wav information
  char* buffer;

  //holds the side of our file and fills our buffer by calling
  //read file
  int filesize = read_file(fileloc,&buffer);

  //making something to hold our actual sound data from our buffer
  char* dataholder = malloc(sizeof(char*) * (filesize-43));

/*
  for(int i = 0;i<(filesize-43);i++){
    dataholder[i] = buffer[i+43];
  }
  */



  //holding space for our reversed wav file
  char** reverseBuffer = malloc(sizeof(buffer));

  //parse our buffered information into a wavFile pointer
  struct wavfile* wav = parse(buffer);

  //write_file(argv[2],reverseBuffer,filesize);
  free(reverseBuffer);
  free(buffer);

}



/**
  the parse method accepts buffer from main that is created by reading all
  elements within the file given and then begins to make sense of the
  information and sorts it where it seems to be for a .wav file
*/
struct wavfile* parse(char* contents){
  int i = 0;

  struct wavfile wav;
  struct wavfile* wavLocater = &wav;
  memcpy(wavLocater,contents,sizeof(struct wavfile));
  wavLocater->total_size -=8;


  printf("%d", wavLocater->total_size);
/*
  for(i =0;i<4;i++){
    wavLocater->riff[i]=contents[i];
  }

  wavLocater->total_size=contents[4];


  for(i=8;i<12;i++)
  {
    wavLocater->wave[i]=contents[i];

  }

  for(i=12;i<16;i++){
    wavLocater->fmt[i]=contents[i];

  }

  wavLocater->fmt_length = contents[16];

  wavLocater->fmt_type = contents[21];

  wavLocater->channels = contents[22];

  wavLocater->sample_rate = contents[24];

  wavLocater->byte_rate = contents[28];

  wavLocater->alignment = contents[32];

  wavLocater->bits_per_sample = contents[34];


  for(i=36;i<40;i++){
  wavLocater->chunk_header[i] = contents[i];

  }

  wavLocater->data_sizel = contents[43];*/

  return wavLocater;
}
