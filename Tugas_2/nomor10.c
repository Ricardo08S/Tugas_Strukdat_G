#include <stdio.h>

typedef struct 
{
    char name[20];
    int distance;
} Mengdata;

int indeks;

void readFile(FILE *fileNya, Mengdata peserta[]){
    int count = 0;
    while (fscanf(fileNya, "%s %d", peserta[count].name, &peserta[count].distance) != EOF){
        count++;
        indeks = count;
    }
}

void swap(Mengdata *temp1, Mengdata *tempDua){
    Mengdata temp = *temp1;
    *temp1 = *tempDua;
    *tempDua = temp;
}

void sorting(Mengdata peserta[], int tempData){
    for(int i = 0; i < tempData-1; i++){
        int maxTemp = i;
        for(int j = i+1; j < tempData; j++){
            if(peserta[j].distance > peserta[maxTemp].distance){
                maxTemp = j;
            }
        }
        swap(&peserta[maxTemp], &peserta[i]);
    }
}

int main(){
    FILE *fptr;
    fptr = fopen("dataNomor10.txt", "r");
    Mengdata peserta[20];
    readFile(fptr, peserta);
    sorting(peserta, indeks);
    for(int i = 0; i < indeks; i++){
        printf("%s %d\n", peserta[i].name, peserta[i].distance);
    }
    fclose(fptr);
    return 0;
}