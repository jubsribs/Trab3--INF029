#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10
#include "EstruturaVetores.h"


void dobrar(int *x){

    *x = *x * 2;


}
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int tamanho, int posicao){

    int retorno = SUCESSO;
    
        if(!ehPosicaoValida(posicao))
            retorno = POSICAO_INVALIDA;
    
       else if(tamanho <=0)
            retorno = TAMANHO_INVALIDO;
    
        else if(vetorprincipal[posicao-1].aux != NULL)
	retorno = JA_TEM_ESTRUTURA_AUXILIAR;
	
	else{        
        vetorprincipal[posicao-1].aux = (int *) malloc(tamanho*sizeof(int));
    
        if(vetorprincipal[posicao-1].aux == NULL)
            retorno = SEM_ESPACO_DE_MEMORIA;
	
	else
	vetorprincipal[posicao-1].tamanho = tamanho;
	}
    return retorno;

}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int valor, int posicao){

    int retorno = 0;
    

    if(!ehPosicaoValida(posicao))
        retorno = POSICAO_INVALIDA;

    else if(vetorprincipal[posicao-1].aux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;

    else if(vetorprincipal[posicao-1].qtd == vetorprincipal[posicao-1].tamanho)
        retorno = SEM_ESPACO;

    else{
        vetorprincipal[posicao-1].aux[vetorprincipal[posicao-1].qtd] = valor;
            
        vetorprincipal[posicao-1].qtd ++;
	retorno = SUCESSO;
    }

    return retorno;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao){
    
    int retorno = SUCESSO;

    if(!ehPosicaoValida(posicao))
        retorno = POSICAO_INVALIDA;

    else if(vetorprincipal[posicao-1].aux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;

    else if(vetorprincipal[posicao-1].qtd == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;

    else
    	vetorprincipal[posicao-1].qtd --;
   
  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){
    
    int retorno = SUCESSO;

    if(!ehPosicaoValida(posicao))
        retorno = POSICAO_INVALIDA;

    else if(vetorprincipal[posicao-1].qtd == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;

    else if(vetorprincipal[posicao-1].aux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;

    else if(elemento(valor,posicao) == -1 )
        
        retorno = NUMERO_INEXISTENTE;

    else{
        for(int i = elemento(valor, posicao); i < vetorprincipal[posicao - 1].qtd; i++){

            vetorprincipal[posicao - 1].aux[i]= vetorprincipal[posicao - 1].aux[i+1];
        }
            vetorprincipal[posicao - 1].qtd--;
    }

    return retorno;
    }

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    int retorno = 0;
    
    if (posicao < 1 || posicao > 10){
        
        retorno = 0;
    }else retorno = 1;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    
    int retorno = SUCESSO;
    
    if(!ehPosicaoValida(posicao))
        retorno = POSICAO_INVALIDA;
    
    else if(vetorprincipal[posicao-1].aux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else{
        int x;

        for(x=0; x<vetorprincipal[posicao-1].qtd; x++)
        {
            vetorAux[x] = vetorprincipal[posicao-1].aux[x];
        }
    }
    return retorno;

}


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){

   int retorno = SUCESSO;
    
    if(!ehPosicaoValida(posicao))
        retorno = POSICAO_INVALIDA;
    
    else if(vetorprincipal[posicao-1].aux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    
     else{
        int x;

        for(x=0; x<vetorprincipal[posicao-1].qtd; x++)
        {
            vetorAux[x] = vetorprincipal[posicao-1].aux[x];
        }
        ordenar(vetorAux,vetorprincipal[posicao-1].qtd);
    }

    return retorno;

}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = SUCESSO;
    int x,y,z=0;
    int qtdtotal = 0;
    
        for(x=0 ; x< 10; x++)
            qtdtotal = qtdtotal+ vetorprincipal[x].qtd;
        
        if( qtdtotal == 0)
            retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
        else{
            for( y=0 ; y< 10 ; y++)
                for(x=0; x<vetorprincipal[y].qtd; x++)
                {
                    vetorAux[z] = vetorprincipal[y].aux[x];
                    z++;
                }
        }
    return retorno;

}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = SUCESSO;
    int x,y,z=0;
    int qtdtotal=0;
        
    for(x=0 ; x< 10; x++)
        qtdtotal = qtdtotal+ vetorprincipal[x].qtd;
        
    if( qtdtotal == 0)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else{
        for( y=0 ; y< 10 ; y++)
            for(x=0; x<vetorprincipal[y].qtd; x++)
            {
                vetorAux[z] = vetorprincipal[y].aux[x];
                z++;
            }
        ordenar(vetorAux,qtdtotal);
    }    
        
    return retorno;

}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){

    int retorno = SUCESSO;
    int tam2;
    
    tam2 = vetorprincipal[posicao-1].qtd + novoTamanho;
    
    if(!ehPosicaoValida(posicao))
        retorno = POSICAO_INVALIDA;
    else if(vetorprincipal[posicao-1].aux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else if(tam2 <= 0)
        retorno = NOVO_TAMANHO_INVALIDO;
    else{
        
        vetorprincipal[posicao - 1].aux = (int*)realloc(vetorprincipal[posicao - 1].aux , tam2*sizeof(int));
        
        if(vetorprincipal[posicao - 1].aux == NULL)
            retorno = SEM_ESPACO_DE_MEMORIA;
        
        else{
            
            if(novoTamanho < 0 && vetorprincipal[posicao-1].qtd == vetorprincipal[posicao-1].tamanho)
                vetorprincipal[posicao-1].qtd = vetorprincipal[posicao-1].qtd + novoTamanho;
            vetorprincipal[posicao-1].tamanho = tam2;
        }
     
    }
    return retorno;

}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){

    int retorno = SUCESSO;
    
    if(!ehPosicaoValida(posicao))
        retorno = POSICAO_INVALIDA;
    else if(vetorprincipal[posicao-1].aux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else if(vetorprincipal[posicao-1].qtd == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else{
        retorno = vetorprincipal[posicao-1].qtd;
    }

    return retorno;

}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No* montarListaEncadeadaComCabecote(){
  
    No*inicio = (No*) malloc(sizeof(No));
    
        inicio->prox=NULL;
    
    int x , qtdtotal=0;
    
    for(x=0 ; x< 10; x++)
        qtdtotal = qtdtotal+ vetorprincipal[x].qtd;
    
    int vetorAux[qtdtotal];
    
    getDadosDeTodasEstruturasAuxiliares(vetorAux);
    
    int y;
    
    for(y=0; y<qtdtotal; y++)
        inserefinal(&inicio , vetorAux[y]);
    
    if(qtdtotal==0)
    return NULL;
    
    
    return inicio;

}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){
    
    No*aux;

    aux = inicio->prox;
    
    int x=0;
    
    while(aux!= NULL){

       vetorAux[x] = aux->conteudo;
       aux = aux->prox;
       x++;
    }

}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No** inicio){
   
        No *li;
    
        while((*inicio)!= NULL){
            li = (*inicio);
            (*inicio) = (*inicio)->prox;
            free(li);
        }
        free(*inicio);
}
            

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar(){
    
	int x;

	for(x=0;x<10;x++)
	{
	vetorprincipal[x].aux = NULL;
	vetorprincipal[x].qtd = 0; 
	vetorprincipal[x].tamanho = 0;
	}
        LerArquivo();
        
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar(){
    
    int x;
        EscreverArquivo();
        
    for(x=0 ; x<10; x++){
        free(vetorprincipal[x].aux);
    }
}

int elemento(int valor, int posicao){

    int i;
    
  for(i = 0; i < vetorprincipal[posicao - 1].qtd; i++ ){
    if(valor == vetorprincipal[posicao - 1].aux[i])
      return i;
  }
  return -1;
}

void ordenar (int vetorAux[] , int qtd) {
    
    int x , aux2;
    int y;
    
    for ( x=0 ; x< qtd; x++){
        for( y= x+1 ; y <qtd ; y++)
        {
            if (vetorAux[x]>vetorAux[y])
            {
                aux2 = vetorAux[x];
                vetorAux[x]= vetorAux[y];
                vetorAux[y] = aux2;
            }
        }
    }
}

        
int inserefinal(No **inicio , int valor){
    
    No *aux;

    No*li = (No*)malloc(sizeof(No));
    
    if(li == NULL){
        return SEM_ESPACO_DE_MEMORIA;
    }
    
li->conteudo = valor;
li->prox = NULL;

if((*inicio)->prox == NULL){
    (*inicio)->prox = li;
}

else{
    aux = (*inicio);
    
    while( aux->prox!= NULL){
        aux = aux->prox;
    }
    aux->prox=li;
  }
  
  return 1;
}
void LerArquivo(){
     FILE *input;
     char linha[1001];
     int x,j=0;
     char numero[1000];
     int vetor[1000],tamanho,posicao;
     
    input = fopen("arquivo.txt","r");
    
     if(input == NULL){
         
    input = fopen("arquivo.txt","w");
    
     }
     
     else if(input){
         while(!feof(input)){
             fgets(linha, 1001, input);
             
             
             int h=0;

            for(x=0; x<strlen(linha); x++){
                            
                if(linha[x]!= ';'){
                    numero[j] = linha[x];
                    j++;
                }
                else if(linha[x] == ';'){
                    numero[j] = '\0';
                    vetor[h] = atoi(numero);
                    h++;
                    j=0;
                    
                }
            }
                for(x=0; x<h; x++){
                    if(x==0){
                        posicao = vetor[x]+1;
                    }
                    else if(x==1){
                        tamanho = vetor[x];
                        criarEstruturaAuxiliar(tamanho,posicao);
                        
                    }
                    else{
                        inserirNumeroEmEstrutura(vetor[x],posicao);
                    }
                }
    
             
             }
                  
             
         }
             

    }

void EscreverArquivo(){
    
    FILE *output;
    int i,x;
    
    output = fopen("arquivo.txt","w");
    
    for(i=0; i<10; i++){
       fprintf(output,"%d",i);
    fprintf(output,"%s",";");
    
    fprintf(output,"%d",vetorprincipal[i].tamanho);
    fprintf(output,"%s",";");
    
         for(x=0; x<vetorprincipal[i].qtd; x++)
        {
            fprintf(output,"%d",vetorprincipal[i].aux[x]);
            fprintf(output,"%s",";");
        }
        fprintf(output,"%s","\n");
    }
    
    fclose(output);
}
        

    
    
     
