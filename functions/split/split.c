char** cria_lista_palavras(char *linha_atual, int tam_lin, char delimitador) {
    char **teste;
    int indice_palavra = 0;
    teste = malloc(tam_lin*sizeof(char*));

    for (int i = 0, j = 0; i <= tam_lin; i++, j++ ) {

        if (linha_atual[i] == delimitador || i == tam_lin) {

            teste[indice_palavra] = malloc(sizeof(char)*j);
            j = 0;
            indice_palavra++;
        }

    }

    return teste;
}


void preenche_lista_palavras (char *linha_atual, int tam_lin, char** lista_palavras, char delimitador) { 
    char atual;
    int indice_palavra = 0;
    printf("[");
    int j = 0;
    for (int i = 0; i < tam_lin; i++) {

        if (linha_atual[i] != delimitador) {

            lista_palavras[indice_palavra][j] = linha_atual[i];
            printf("%c", lista_palavras[indice_palavra][j]);
            j++;
        }
        else {
            j = 0;
            indice_palavra++;
            printf(",");
        }
    }
    printf("]");

}

char **split(char * frase, int tam_frase, char delimitador ) {
    char ** resultado;
    resultado = cria_lista_palavras(frase, tam_frase, delimitador);
    preenche_lista_palavras(frase, tam_frase, resultado, delimitador);
    return resultado;
}