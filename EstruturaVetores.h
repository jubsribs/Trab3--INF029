#define SUCESSO -1
#define SEM_ESPACO -2
#define SEM_ESTRUTURA_AUXILIAR -3
#define JA_TEM_ESTRUTURA_AUXILIAR -4
#define POSICAO_INVALIDA -5
#define SEM_ESPACO_DE_MEMORIA -6
#define TAMANHO_INVALIDO -7
#define ESTRUTURA_AUXILIAR_VAZIA -8
#define NUMERO_INEXISTENTE -9
#define NOVO_TAMANHO_INVALIDO -10
#define TODAS_ESTRUTURAS_AUXILIARES_VAZIAS -11
#define FALHA_ABRIR_ARQUIVO -12
#define FIM_DO_ARQUIVO -13
typedef struct reg {
	int conteudo;
  struct reg *prox;
} No;

typedef struct Lista{
    int qtd;
    int tamanho;
    int *aux;
}lista;

lista vetorprincipal[10];

int ehPosicaoValida(int posicao);
int criarEstruturaAuxiliar(int tamanho, int posicao);
int inserirNumeroEmEstrutura(int valor, int posicao);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
int elemento(int valor, int posicao);
No* montarListaEncadeadaComCabecote();
int inserefinal(No **inicio , int valor);


void inicializar();
void finalizar();
void dobrar(int *x);
void LerArquivo();
void EscreverArquivo();
void ordenar (int vetorAux[] , int qtd);
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(No** inicio);
