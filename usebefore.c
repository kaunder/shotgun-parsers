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
//then use it all over the place, sans recognition


//Function prototypes
void usage();
void debug(char *str);
void getInput(char *buf);
void foo(char *buf);
void bar(char *buf);
char* baz(char *buf);
char* passthrough(char *buf);

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


  //Do a bunch of stuff with the random input

  foo(randobuf);
  bar(randobuf);

  printf("%s",baz(randobuf));
  
  //printf("%s", randobuf);
  

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

//copy the first 32 bytes from random buffer into smaller buffer
void foo(char *buf){

  //use some bytes from buf
  int i=0;
  char *smallbuf = malloc(33);
  for(i=0;i<32;i++){
    smallbuf[i]=buf[i];
  }

  //null terminate smallbuf
  smallbuf[32]='\0';
  
  //call baz, why not
  char *c=baz(smallbuf);

  //let's see it
  printf("%s\n",c);
  
  //call bar()
  bar(buf);
  
}

//read every 4th char out of the input buffer
void bar(char *buf){
  
  //here have bytes
  int i=0;
  char *anotherbuf = malloc(NUM_BYTES/4);
  for(i=0;i<NUM_BYTES;i+=4){
    anotherbuf[i]=buf[i];
  }

  anotherbuf[i/4]='\0';

  //call baz()
  baz(passthrough(buf));
  
}


char* baz(char *buf){

  //use even more bytes..
  char c = buf[NUM_BYTES];
  char *onemore = malloc(NUM_BYTES/2);

  //aagh omg we're memcpying
  memcpy(onemore, buf, NUM_BYTES/2);
  

  return "c";
}

//pick a single char off of buf, pass buf on
char* passthrough(char *buf){

  char c = buf[NUM_BYTES/2];

  return buf;
  
}

void debug(char *str){
  if(debug_flag){
    printf("%s\n",str);
  }
}

