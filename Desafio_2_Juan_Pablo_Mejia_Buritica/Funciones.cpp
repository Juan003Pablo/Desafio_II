#include "Funciones.h"
#include <cstring>
using namespace std;

char** split(const char* str, char delimitador, int& cantidad) {
    int len = strlen(str);
    int partes = 1;
    for (int i = 0; i < len; i++) {
        if (str[i] == delimitador) partes++;
    }

    char** resultado = new char*[partes];
    cantidad = 0;
    int inicio = 0;
    for (int i = 0; i <= len; i++) {
        if (str[i] == delimitador || str[i] == '\0') {
            int tamanio = i - inicio;
            resultado[cantidad] = new char[tamanio + 1];
            strncpy(resultado[cantidad], &str[inicio], tamanio);
            resultado[cantidad][tamanio] = '\0';
            cantidad++;
            inicio = i + 1;
        }
    }
    return resultado;

}
