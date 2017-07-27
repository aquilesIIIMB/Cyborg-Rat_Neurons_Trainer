#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <wiringPi.h>

int i =0;

int main() {
  if (wiringPiSetupGpio () == -1)
    exit (1) ;

  pinMode(7, OUTPUT);

  while(1) {
	i=i+1;
    	digitalWrite(7, 0);
    	digitalWrite(7, 1);
	printf("%d\n",i);
  }

  return 0 ;
}
