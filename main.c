#include<stdio.h>
#include <math.h>  
#include <regex.h>
#include <stdlib.h>

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
   int tempAB=4*tempAC;
   return exponent-(tempAB);

}
void pf(char * str){
   printf("%s",str);
}

void paternTest(int value)
{
    if (value == 0) {
        pf("Pattern found.\n");
    }
    else if (value == REG_NOMATCH) {
        pf("Pattern not found.\n");
    }
    else {
        pf("An error occured.\n");
    }
}

void showBannerBye(){
      FILE* fichier = NULL;
    char chaine[TAILLE_MAX] = "";
    fichier = fopen("banner2.txt", "r");
    if (fichier != NULL)
    {
      while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
      {
        printf("%s", chaine);
      }
        fclose(fichier);
    }
}
int getSolutionCase(int delta,int a,int b,int c){
  if(delta > 0){

    int x1,x2;
    int tempA=-b-delta;
    int tempB=2*a;
    x1=tempA/tempB;

    int tempASecond=-b+delta;
    int tempBSecond=2*a;
    x2=tempASecond/tempBSecond;
    
    printf("L'ensemble des solutions donne S={%d:%d}",x1,x2);
    showBannerBye();
  }else if(delta<0){
    pf("L'equation a pour solution ensemble de vide !");
  }
  else if(delta == 0){
   int x1,x2;
   x1=-b/2*a;
   x2=x1;
   printf("L'ensemble des solutions donne S={%d:%d}",x1,x2);
  }
 return 0;
}
int main(){

  char ptr_a[256],ptr_b[256],ptr_c[256];
  regex_t regex;
  int response,delta;
  int ptr_a_match,ptr_b_match,ptr_c_match;

  showBannerEquation();

  pf("\n\nWelcome to our quadratic equation resolver !");
  
  pf("\n\nEnter the a term:");
  scanf("%s",ptr_a);

  pf("Enter the b term:");
  scanf("%s",ptr_b);

  pf("Enter the c term:");
  scanf("%s",ptr_c);

  int match_ptr_a;
  int match_ptr_b;
  int match_ptr_c;

  match_ptr_a = regcomp(&regex,"[0-9]",0);
  match_ptr_a= regexec(&regex,ptr_a, 0, NULL, 0);

  match_ptr_b = regcomp(&regex,"[0-9]",0);
  match_ptr_b= regexec(&regex,ptr_b, 0, NULL, 0);

  match_ptr_c = regcomp(&regex,"[0-9]",0);
  match_ptr_c= regexec(&regex,ptr_c, 0, NULL, 0);

  if(match_ptr_a == REG_NOMATCH || match_ptr_b ==REG_NOMATCH || match_ptr_c == REG_NOMATCH){
    pf("C'est incorrect vous devez rentrer un nombre !");
  }else{
 
    ptr_a_match=atoi(ptr_a);
    ptr_b_match=atoi(ptr_b);
    ptr_c_match=atoi(ptr_c);

    int delta=sqrt(getDeltaValue(
      ptr_a_match,
      ptr_b_match,
      ptr_c_match));
      getSolutionCase(delta,ptr_a_match,ptr_b_match,ptr_c_match);
  }
  return 0;
}