#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int tamanhoDoArray(char caminho[]);
int dadosDoArquivo();
void selectionSort(int num[], int TAM);
void insertionSort(int num[], int TAM);
void bubbleSort(int num[], int TAM);
void pastaDoArquivo(char caminho[]);
void abrirArquivoOrdenar(int opcao);
void salvandoArquivoOrdenado(char caminho[], int numeros[], int TAM);
void nomeDoArquivo(char caminho[]);

int main()
{
    int escolha = 0;
    printf("Escolha o tipo de ordenação\n Digite 1 - SelectSort\n Digite 2 - InsertionSort\n Digite 3 - BubbleSort\n");
    scanf("%i", &escolha);

    abrirArquivoOrdenar(escolha);

    return 0;
}

void abrirArquivoOrdenar(int opcao)
{
    char caminho[100];
    nomeDoArquivo(caminho);
    int m, i = 0;
    int TAM = tamanhoDoArray(caminho);
    int vetor[TAM - 1];

    FILE *arquivo = fopen(caminho, "r");
    if (arquivo == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo.txt.");
    }
    while ((fscanf(arquivo, "%d", &m)) != EOF)
    {
        vetor[i] = m;
        i++;
    }

    switch (opcao)
    {
    case 1:
        selectionSort(vetor, TAM - 1);
        fclose(arquivo);
        salvandoArquivoOrdenado("C:\\ordenado_selectionSort.txt", vetor, TAM);
        break;
    case 2:
        insertionSort(vetor, TAM - 1);
        fclose(arquivo);
        salvandoArquivoOrdenado("C:\\ordenado_insertionSort.txt", vetor, TAM);
        break;
    case 3:
        bubbleSort(vetor, TAM - 1);
        fclose(arquivo);
        salvandoArquivoOrdenado("C:\\ordenado_bubbleSort.txt", vetor, TAM);
        break;
    default:
        break;
    }
}

void pastaDoArquivo(char caminho[])
{
    char pasta[100];

    printf("Digite o caminho e da pasta onde estao arquivo\n exemplo: C:\\\\arquivos\\\\ \n");
    scanf("%s", pasta);
    strcpy(caminho, pasta); //colocar o caminho
}

void nomeDoArquivo(char caminho[])
{
    pastaDoArquivo(caminho);
    char nomeArquivo[20];
    printf("Digite nome do Arquivo: ");
    scanf("%s", nomeArquivo);
    strcat(caminho, nomeArquivo);
    printf("%s", caminho);
}

int tamanhoDoArray(char caminho[])
{
    //FILE *arquivo = fopen("/home/before/Área de Trabalho/ordena/aleatorio.txt", "r");
    FILE *arquivo = fopen("/home/before/numeros.txt", "r");
    if (arquivo == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo.txt.");
        return 1;
    }

    int contagem = 0;
    int caractere = 0;
    do
    {
        caractere = fgetc(arquivo);
        if (caractere == ' ')
        {
            contagem++;
        }
    } while (caractere != EOF);


    printf("\n quantidade do registro %i",contagem);
    fclose(arquivo);
    return contagem;
}

void selectionSort(int num[], int TAM)
{
    clock_t tempIniS, tempFimS = 0;
    tempIniS = clock();

    int i, x, j, min, aux = 0;
    for (i = 0; i < (TAM - 1); i++)
    {
        min = i;
        for (j = (i + 1); j < TAM; j++)
        {
            if (num[j] < num[min])
                min = j;
        }
        if (num[i] != num[min])
        {
            aux = num[i];
            num[i] = num[min];
            num[min] = aux;
        }
    }
    printf("\nSelectionSort\n\n");
    //for (x = 0; x < (TAM); x++){
    //    printf("%d ", num[x]);
    //}
    tempFimS = clock();
    printf("\n\n Tempo: %f \n\n", ((tempFimS - tempIniS) / (double)CLOCKS_PER_SEC));
}

void insertionSort(int num[], int TAM)
{
    clock_t tempIniI, tempFimI = 0;
    tempIniI = clock();

    int i, x, j, valorAtual = 0;
    for (j = 1; j < TAM; j++)
    {
        valorAtual = num[j];
        i = j - 1;
        while (i >= 0 && num[i] > valorAtual)
        {
            num[i + 1] = num[i];
            i--;
        }
        num[i + 1] = valorAtual;
    }

    printf("\nInsertionSort\n\n");
    //for (x = 0; x < (TAM); x++){
    //    printf("%d ", num[x]);
    //}

    tempFimI = clock();
    printf("\n\n Tempo: %f \n\n", ((tempFimI - tempIniI) / (double)CLOCKS_PER_SEC));
}

void bubbleSort(int num[], int TAM)
{
    clock_t tempIniB, tempFimB = 0;
    tempIniB = clock();

    int x, i, j, aux = 0;
    for (i = 1; i < TAM; i++)
    {
        for (j = 0; j < TAM - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                aux = num[j];
                num[j] = num[j + 1];
                num[j + 1] = aux;
            }
        }
    }
    printf("\nBubbletSort\n\n");
    //for (x = 0; x < (TAM); x++){
    //    printf("%d ", num[x]);
    //}
    tempFimB = clock();
    printf("\n\n Tempo: %f \n\n", ((tempFimB - tempIniB) / (double)CLOCKS_PER_SEC));
}

void salvandoArquivoOrdenado(char caminho[], int numeros[], int TAM)
{

    FILE *arquivo = fopen(caminho, "w");
    if (arquivo == NULL)
    {
        fprintf(stderr, "Erro ao abrir o arquivo.txt.");
    }
    //usando fprintf para armazenar a string no arquivo
    for (int i = 0; i < TAM; i++)
    {
        fprintf(arquivo, "%d ", numeros[i]);
    }

    //usando fclose para fechar o arquivo
    fclose(arquivo);
}