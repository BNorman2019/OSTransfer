#include <stdio.h>

int main() {
  FILE *infile;
  FILE *outfile;
  char buffer[255];

  infile = fopen("input.dat", "r");
  outfile = fopen("output.dat", "w+");
  
  while(fgets(buffer, 255, (FILE*)infile)) {
    fputs(buffer, outfile);
  }

  fclose(outfile);
  fclose(infile); 
  return 0;
}

