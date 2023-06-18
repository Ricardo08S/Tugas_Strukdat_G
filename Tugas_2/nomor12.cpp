#include <stdio.h>

typedef struct {
    char nrp[15];
    int class1, class2, class3, class4, class5, class6;
} Mengdata;

int indeks;
void readFile(FILE *fileNya, Mengdata sipoke[]){
    int hah = 0;
    while (fscanf(fileNya, "%s %d %d %d %d %d %d", sipoke[hah].nrp, &sipoke[hah].class1, &sipoke[hah].class2, 
                                    &sipoke[hah].class3, &sipoke[hah].class4, &sipoke[hah].class5, &sipoke[hah].class6) != EOF){
        hah++;
        indeks = hah;
    }
}

int main(){
    FILE *fptr;
    fptr = fopen("dataNomor12.txt", "r");
    Mengdata sipoke[100];
    readFile(fptr, sipoke);

    printf("CS20A : \n");
    for(int j = 0; j < indeks; j++){
        if(sipoke[j].class1 == 1){
            printf("%s\n", sipoke[j].nrp);
        }
    }

    printf("CS21A : \n");
    for(int j = 0; j < indeks; j++){
        if(sipoke[j].class2 == 1){
            printf("%s\n", sipoke[j].nrp);
        }
    }

    printf("CS29A : \n");
    for(int j = 0; j < indeks; j++){
        if(sipoke[j].class3 == 1){
            printf("%s\n", sipoke[j].nrp);
        }
    }

    printf("CS30A : \n");
    for(int j = 0; j < indeks; j++){
        if(sipoke[j].class4 == 1){
            printf("%s\n", sipoke[j].nrp);
        }
    }

    printf("CS35A : \n");
    for(int j = 0; j < indeks; j++){
        if(sipoke[j].class5 == 1){
            printf("%s\n", sipoke[j].nrp);
        }
    }

    printf("CS36A : \n");
    for(int j = 0; j < indeks; j++){
        if(sipoke[j].class6 == 1){
            printf("%s\n", sipoke[j].nrp);
        }
    }
    fclose(fptr);
    return 0;
}