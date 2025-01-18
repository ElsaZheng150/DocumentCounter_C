#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    int acount = 0, ecount = 0, icount = 0, ocount = 0, ucount = 0, consonants = 0, punct = 0, count = 0, i = 0;
    char w, filename[25];
    FILE *words;
    FILE *out;
    printf("Please enter the name of your file \n");
    scanf("%s", &filename);
    words = fopen(filename, "r+");
    if(words == NULL){
      printf("There was an issue opening the file");
      exit(1);
    }
    out = fopen("output.txt", "w");
    while((w=fgetc(words)) != EOF){
         count++;
         if(ispunct(w)){
           punct++;
         }
         if(isalpha(w)){
           if(w == 'a'){
             acount++;
           }
           if(w == 'e'){
             ecount++;
           }
           if(w == 'i'){
             icount++;
           }
           if(w == 'o'){
             ocount++;
           }
           if(w == 'u'){
             ucount++;
           }
           if(w!='a' && w!='e' && w!='i' && w!='o' && w!='u'){
             consonants++;
           }
        }
     }
     printf("a %.2f\% ; ", (float)acount/count*100);
     printf("e %.2f\% ; ", (float)ecount/count*100);
     printf("i %.2f\% ; ", (float)icount/count*100);
     printf("o %.2f\% ; ", (float)ocount/count*100);
     printf("u %.2f\% ; ", (float)ucount/count*100);
     printf("consonants %.2f\% ; ", (float)consonants/count * 100);
     printf("punct %.2f\% ; \n", (float)punct/count*100);
     fclose(words);
     fclose(out);
     return 0;
}