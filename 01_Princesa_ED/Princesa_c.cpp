#include <iostream>
#include <stdio.h>

using namespace std;

int vivo(int *vet, int n, int escPrin);

int main(){

    int n=0;
    int matar=0;

    scanf("%d",&n);
    scanf("%d", &matar);
    int qtdPart[n-1];
    int i=0;
    int cont = 0;
    //encher vetor
    for(i=1;i<=n;i++){
        qtdPart[i] = i;
    }

    while (cont != n-1){
        if(qtdPart[matar] < n ){
            qtdPart[matar+1] = 0;
            matar = matar+1;
            cont++;
        }
        if(matar >= n){
            qtdPart[1] =0; //se a escolha for a ultima morre o primeiro elemento
            matar = 1;
            cont++;
         }

        matar = vivo(qtdPart, n, matar); //ai faz a busca por o prox vivo

        }
    printf("O vencedor %d", vivo(qtdPart,n,matar));

    return 0;
}

int vivo(int *qtdPart,int n,int escPrin){
    int i=0;
    for(i=escPrin;i<=n;i++){
        if(escPrin == n){
            escPrin = 1;
        }
        if(qtdPart[i+1] != 0){
            return escPrin+1;
        }
        escPrin++;
    }
    return 0;
}
