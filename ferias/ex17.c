#include <stdbool.h>
#include <stdio.h> 


bool IsIsogram (const char *string) 
{
 
  int i, j, ok = 1;
        
    for(i=0;string[i] != 0; i++){
      
      if (((string[i] >= 97)&&(string[i] <= 122)) || ((string[i] >= 65)&&(string[i] <= 90))){
        ok = 0;
      }
      
      for(j=i; string[j] != 0; j++){
        
        if(string[i] == string[j])
        {
          ok = 0;
        }
        if(string[i] == (string[j]-32))
        {
          ok = 0;
        }
         if(string[i] == (string[j]+32))
         {
          ok = 0;
        }
       
        
      }
      return ok;
    }
}

int main(){

int ok;
char string[] = "abca";
int i;



ok = IsIsogram(string);
printf("%d", ok);

 if(ok == 1){
    printf("true");
  }
  else{
  printf("false");
  }
    return 0;

}
