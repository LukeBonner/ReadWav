#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "wave.h"
#include "file.h"

#define TRUE 1
#define FALSE 0


char **buffer;

/*
Note: code structure and understanding pulled from
https://stackoverflow.com/questions/14002954/c-programming-how-to-read
-the-whole-file-contents-into-a-buffer

*/
size_t read_file(char* filename, char** buffer){

  //this is going to be a large amount of reading things in


  FILE *f = fopen(filename,"rb");
  //now we go to the end of the file
  fseek(filename,0,SEEK_END);
  //now that we are at the end of the file, we can set
  //the current location ( end of the file ) to our file size
  long filesize = ftell(filename);
  //now we go back to the start of the file
  fseek(filename,0,SEEK_SET);

  //allocate memory for our "string" with our filesize...plus 1
  //because of array counting!
  buffer = malloc(filesize+1);


  //read in our file information into string
  fread(buffer,1,filesize,filename);

  //call parse to pass over the string to be analyzed into wav format
  parse(buffer);

  //finally, close the file
  fclose(filename);
  free(buffer);

  return filesize;
}


/*
  this function will output the
*/
size_t write_file(char* filename,char** buffer,size_t size){



}
