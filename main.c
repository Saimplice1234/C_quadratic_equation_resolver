#include<stdio.h>
#include <math.h>  

#define TAILLE_MAX 1000

void showBannerEquation(){

    FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = "";
 
    fichier = fopen("banner.txt", "r");
 
    if (fichier != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
        {
            printf("%s", chaine);
        }
 
        fclose(fichier);
    }
}

int getDeltaValue(int a,int b,int c){

   int exponent=pow(b,2);
   int tempAC=a*c;
   return exponent - 4 * tempAC;

}
void generatePrintfWithoutRef(char * str){
   printf(str);
}
int generateScanfAsNumber(){
   int ref;
   scanf("%d",&ref);
   return ref;
}

int main(){

  showBannerEquation();
  generatePrintfWithoutRef("\n\nWelcome to our quadratic equation resolver");
  generatePrintfWithoutRef("\n\nEnter the a term:");
  int a=generateScanfAsNumber();
  printf("La valeur de a est %d",a);

  return 0;
}