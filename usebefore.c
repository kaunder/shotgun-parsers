///////////////////////////////////////////////////////////////
// Third shotgun parser property                             //
// (use before full recognition)                             //
// Katie Underwood                                           //
//                                                           //
///////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

#define NUM_BYTES 64
#define debug_flag 0

//read in something...from a network?
//then use it shittily all over the place


//Function prototypes
void usage();
void debug(char *str);
void getInput(char *buf);
void foo();
void bar();
void baz();

int main(int argc, char *argv[]){

  //If required, check here for required number/type of arguments
  /*if(argc==1){//or whatever it should be
    usage();
    return 0;
    }*/


  //Define our input buffer here
  char *randobuf = malloc(NUM_BYTES+1);

  //Get a bunch o random input
  getInput(randobuf);

  printf("%s", randobuf);
  

  return 0;
}

//Helper function to print a usage message
void usage(){
  printf("%s\n","Usage: ./useb4 | hexdump");
}

void getInput(char *buf){

  debug("We're gonna get input now...");
  
  //read a bunch of bytes from /dev/urandom
  //Be aware - sometimes you'll get zeros off of /dev/urandom,
  //and so if you're piping into hexdump it'll look like you
  //have less output. But it's just bc hexdump doesn't print the 0s.
  //(don't panic)
  FILE *f;
  f=fopen("/dev/urandom", "r");
  fread(buf, 1, NUM_BYTES, f);
  fclose(f);

  //null terminate that shit
  buf[NUM_BYTES]='\0';

  
  
  debug("Done getting input from /dev/random.");
}

void debug(char *str){
  if(debug_flag){
    printf("%s\n",str);
  }
}
