/***********************

Conway Game of Life

serial version

************************/

#include <stdio.h>

#include <stdlib.h>

#define NI 10        /* array sizes */

#define NJ 10

#define NSTEPS 10    /* number of time steps */

int main(int argc, char *argv[]) {

	int i, j, k, ni, nj, pos_v, pos_h;
	int **map, **new;  
	float x;

  	/* allocate arrays */

	  ni = NI + 2;  /* add 2 for left and right ghost cells */
	  nj = NJ + 2;
	  map = malloc(ni*sizeof(int*));
	  //new = malloc(ni*sizeof(int*));

	  for(i=0; i<ni; i++){
		    map[i] = malloc(nj*sizeof(int));
		    //new[i] = malloc(nj*sizeof(int));
	  }

	  for(i=1; i<=NI; i++){// Posicion vertical
		    for(j=1; j<=NJ; j++){ // Posicion horizontal
				x = rand()/((float)RAND_MAX + 1);
				if(x<0.9){
					map[i][j] = 0;
				}
				else {
					map[i][j] = 1;
				}
		    }
	}

	for(i=1; i<=NI; i++){
		for(j=1; j<=NJ; j++){
			printf("%d     ", map[i][j]);
		}
		printf("\n");
	}
	
	pos_v = 1;
	pos_h = NJ/2;

	for(k=1; k<=10; k++){
		
		x = rand()/((float)RAND_MAX + 1);
		if(x<0.25){ //derecha
			if(pos_v == NI | map[pos_v+1][pos_h] == 1){
				continue;			
			}
			else{
				pos_v = pos_v + 1;
				map[pos_v][pos_h] = map[pos_v][pos_h] + 2;
			}			
		}
		else if (x<0.5){//arriba
			if(pos_h == NJ | map[pos_v][pos_h+1] == 1){
				continue;			
			}
			else{
				pos_h = pos_h + 1;
				map[pos_v][pos_h] = map[pos_v][pos_h] + 2;
			}
		}
		else if (x<0.75){//izquierda
			if(pos_v == 1 | map[pos_v-1][pos_h] == 1){
				continue;			
			}
			else{
				pos_v = pos_v - 1;
				map[pos_v][pos_h] = map[pos_v][pos_h] + 2;
			}
		}
		else {//abajo
			if(pos_h == 1 | map[pos_v][pos_h-1] == 1){
				continue;			
			}
			else{
				pos_h = pos_h - 1;
				map[pos_v][pos_h] = map[pos_v][pos_h] + 2;
			}
		}
		printf("\n");

		for(i=1; i<=NI; i++){
		    for(j=1; j<=NJ; j++){
			 printf("%d     ", map[i][j]);
			}
		    printf("\n");
		}

		map[pos_v][pos_h] = map[pos_v][pos_h] - 2;
	}

	// Evaluar la aleatoriedad
	printf("Ten random numbers in [1,100]\n");
 
	for (i = 1; i <= 10; i++) {
		k = rand() % 100 + 1;
		printf("%d\n", k);
	}

	return 0 ;
}


