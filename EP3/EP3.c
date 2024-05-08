#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int *load_image_from_file(char *filename, int *w, int *h) ;
void save_image_to_file(char *filename, int *I, int w, int h) ;
int *invert_image(int *I, int w, int h) ;
int *binarize(int *I, int w, int h, int t) ;
int *filter_image(int *I, int w, int h, int d, int tipo) ;
int *expand(int *I, int d, int w, int h);
int *cont(int *I, int w, int h); 
int *label_components(int *I, int w, int h, int *ncc) ;


int *load_image_from_file(char *filename, int *w, int *h) {

FILE *f;
char line[MAX];
int i, x=0;
int *I;
f = fopen(filename,"r");
  
fscanf(f, "%[^\n]\n", line);
fscanf(f, "%d", w);
  fscanf(f, "%d", h);
fscanf(f, "%d", &x);
I = malloc(sizeof(int)*(*w)*(*h)) ;
for (i =0; i < (*h * *w) ; i++){

    fscanf(f, "%d", I + i);
    
}
fclose(f);
return I;
}



void save_image_to_file(char *filename, int *I, int w, int h) {

int i, j;
FILE* f = fopen (filename,"w");

fprintf (f,"P2\n");
fprintf(f, "%d %d\n", w,h);
fprintf (f,"255\n");

for (i =0; i < h  ; i++){
for (j = 0; j < w ; j++){
    fprintf(f, "%d  ", I[i*w + j]);
    
}
 fprintf(f,"\n");
}
fclose (f);
}



int *invert_image(int *I, int w, int h) {

int *invertida = malloc(sizeof(int)*w*h);
int i, j;


for (i = 0; i<w; i++){

    for (j=0 ; j< h; j++){

        invertida[i*h + j] = ( 255 - I[i*h + j] );
    }
}

return invertida;
}


int *binarize(int *I, int w, int h, int t) {

int *bin = (malloc(sizeof(int)*(w)*(h)));
int i, j;

for (i = 0; i < h; i++){

    for (j = 0; j < w; j++){

        if (I[i*w + j] >= t) {bin[i*w + j] = 255;}
        else {bin[i*w + j] = 0;}

    }
}

return bin;

}



int *expand(int *I, int d, int w, int h){

int i, j;

int *exp = (malloc(sizeof(int)*(w+d-1)*(h+d-1)));




for (i = d/2; i < h+(d/2); i++){

for (j = d/2; j < w+ (d/2); j++){

        exp[i*(w+d-1)+j] = I[(i-(d/2))*(w)+(j-(d/2))];
      
        
}
}

for (i = 0; i < (d/2); i++){

for (j = (d/2); j < (w+ (d/2)); j++){

    exp[i*(w+d-1) +j] = I[j-(d/2)];
    exp[(i+h+(d/2))*(w+d-1) +j] = I[(h-1)*w+j-(d/2)];
        
}
}

for (i = (d/2); i < (h+ (d/2)); i++){

for (j = 0; j < (d/2); j++){

    exp[i*(w+d-1) +j] = I[(i-(d/2))*w];
    exp[(i)*(w+d-1) +(j+w+(d/2))] = I[(i-(d/2))*w + (w-1)];
        
}
}

for (i = 0; i < (d/2); i++){

for (j = 0; j < (d/2); j++){

    exp[i*(w+d-1) +j] = I[0];
    exp[(i)*(w+d-1) +(j+w+(d/2))] = I[w-1];
    exp[(i+h+(d/2))*(w+d-1) +j] = I[(h-1)*w];
    exp[(i+h+(d/2))*(w+d-1) +(j+w+(d/2))] = I[(h-1)*w+(w-1)];

        
}
}



return exp;

}

int *filter_image(int *I, int w, int h, int d, int tipo) {

int min, max=0, valor_med;
int *med;
int *filtro;
int i,j,k,l,s,ii,jj;
int aux;
int *ex;
med = malloc(sizeof(int)*d*d);
ex = expand(I,d, w, h);
filtro = malloc(sizeof(int)*h*w);




for (i=(d/2);i<(h+(d/2)); i++){

    for (j=(d/2);j<(w+(d/2));j++){

        min = ex[(i-(d/2))*(w+d-1) + (j- (d/2))];
        max = ex[(i-(d/2))*(w+d-1) + (j- (d/2))];


        s=0;
      for (k=(i-(d/2));k<=(i+(d/2));k++){

        for(l=(j-(d/2));l<=(j+(d/2));l++){

           /* esses fors vão percorrer a área dxd*/
           
            med[s] = ex[k*(w+d-1)+l];
            s++;


            if (min > (ex[(k)*(w+d-1) + (l)])){

                min = ex[(k)*(w+d-1) + (l)];
            }

            if (max < (ex[(k)*(w+d-1) + (l)])){

                max = ex[(k)*(w+d-1) + (l)];
            }


    }
    }    


        if(tipo == 1){

            filtro[(i-(d/2))*w+(j-(d/2))] = min;

        }



        if( tipo == 2){ /* ordenando */

            for(ii=0;ii<d;ii++){

                for(jj=0;jj<d;jj++){

                    if (med[ii] > med[jj]){

                        aux = med[ii];
                        med[ii] = med[jj];
                        med[jj] = aux; 

                    }

            }
            }
        
        valor_med = med[((d*d)/2)];
        filtro[(i-(d/2))*w+(j-(d/2))] = valor_med;

        }


        if(tipo == 3){

            filtro[(i-(d/2))*w+(j-(d/2))] = max;
        }


}
} /* fim dos FOR's que percorrem a principal*/


return filtro;
}


int *cont(int *I, int w, int h) {

    int *contorno;
    int i,j;
    int *filtro = filter_image(I,w,h,3,1);
    contorno = malloc(sizeof(int)*w*h);
    
   for(i = 0; i< (h); i++){
    for(j = 0; j< (w); j++){
    contorno[i*w+j] = (I[i*w+j] - filtro[i*w+j]);
    }
   }

   return contorno;
}



int *label_components(int *I, int w, int h, int *ncc) {

int *lista;
int *rotulo;
int i,j,k,l,saida=0,entrada=0;
lista = malloc(sizeof(int)*w*h);
rotulo = malloc(sizeof(int)*w*h);

for(i=0;i<(w*h);i++){

lista[i] = 0;
rotulo[i] = 0;

}
*ncc = 0;

for (i =0; i< h; i++){

    for (j=0; j < w; j++){

        entrada =0;
        saida=0;

        if((I[i*w+j]!= 0)&&(rotulo[i*w+j]==0)){
            *ncc = *ncc + 1;
            rotulo[i*w+j] = *ncc;
            lista[entrada] = (i*w+j);
            
            while(entrada <= saida){
        for (k=-1;k<=1;k++){

         for(l=-1;l<=1;l++){
        
             if ((((lista[entrada]%w)+l)>=0)&&(((lista[entrada]%w)+l)< w)&&(lista[entrada]/w +k >= 0)&&((lista[entrada]/w +k)<h)){ 
            /* esse if garante que não ocorra segmentation fault: ou seja, que não tentemos "ler" uma casa da matriz que não exista*/

                if((I[lista[entrada] + (k*w+l)]!=0)&&(rotulo[lista[entrada] + (k*w+l)]==0)){

                    saida++;
                    lista[saida] = lista[entrada] + (k*w+l); 
                    rotulo[lista[saida]] = *ncc; 

            }
            }
    }
}
    entrada++;


        } /*fim do while*/ 

        }/* se não for igual a zero */
}}

return rotulo;
}


int main (){

char L = 'a';

 int leu = 0;
 /* L */
char filename[MAX];
int w,h;
int* I;
/* B */ 
int t;
int *result;
/*F*/
int tipo;
int d;
int ncc;

I = NULL;
result = NULL;

while ((L != 'Q') && (L != 'q')){

 
 printf ("----------------------------------------------\n \n");
printf ("Escolha uma opção \n");
 printf (" Q. Quit\n");
 printf (" L. Ler um arquivo\n");
 printf (" S. Salvar imagem em arquivo\n");
 printf (" M. Manter entrada anterior\n \n");

 printf (" B. Binarizar a imagem\n");
 printf (" C. Contorno da imagem\n");
 printf (" I. Inverter a imagem\n");
 printf (" F. Filtrar a imagem\n");
 printf (" R. Rotular os componentes conexos\n \n");

scanf (" %c", &L);
  


  if (((L == 'M') || (L == 'm'))&& leu)  { 

free(result);
result = NULL;

}
else if (result != NULL) {


free(I);
I = result;
result = NULL;


}
if ((L != 'Q') || (L != 'q')){
if ((L == 'L') || (L == 'l')) {
    
    printf (" Digite o nome do arquivo de entrada: \n");
    scanf ("%s", filename);
    
    I = load_image_from_file(filename, &w, &h) ;
   
   if ((I!=NULL)){
   leu = 1;
    printf ("** Tamanho da imagem: %d x %d \n \n", w,h);}

    
    } 


     
else if (((L == 'S') || (L == 's'))&& leu) {
    printf ("==> Digite o nome do arquivo de saída:\n");
    scanf ("%s", filename);
    save_image_to_file(filename, I, w, h) ;
    printf("** Imagem gravada no arquivo %s \n", filename); /* colocar nome do arq*/

    }



else if (((L == 'B') || (L == 'b'))&& leu)  {
    
    printf ("Digite o limiar:");
    scanf("%d",&t);

    result = binarize(I,w,h,t);
    printf("** Imagem foi binarizada \n \n") ;
     
    }

 else if (((L == 'C') || (L == 'c'))&& leu)  {

     result = cont(I,w,h);

  printf("** contrno aplicado\n \n") ;
    
 } 


else if (((L == 'F') || (L == 'f'))&& leu)  { 
    
printf ("==> Digite o tipo do filtro: ");
scanf ("%d", &tipo);
printf ("==> Escolha o tamanho do filtro: ");
scanf ("%d", &d);
printf (" ** Imagem foi filtrada\n");

    result = filter_image(I,w,h,d,tipo);
    /*save_image_to_file("bordab.pgm",result,w+d-1,h+d-1);*/
    }


else if (((L == 'I') || (L == 'i'))&& leu)  {
    
    result = invert_image( I, w, h) ;
    printf(" ** Imagem foi invertida\n");
}


else if ((L == 'R') || (L == 'r')) {

printf(" ** Imagem foi rotulada\n");
result = label_components(I, w,h,&ncc); 
printf("** Número de componentes conexos: %d \n",ncc);

 

}

 


if(!leu){printf("Nenhuma imagem alocada na memória do computador\n");}

} /* fim do "if (L == 'Q')" */


} /* fim do while */
free(I);
free(result);
return 0;
}

