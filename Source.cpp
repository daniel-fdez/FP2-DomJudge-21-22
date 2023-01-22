//// Autor/a: Daniel Fernández Ortiz
//// email: danief17@ucm.es
//// Compilador y S.O. utilizado: VS 2019
//// Nombre del problema: Diversión con matrices Parte 2
//// Comentario general sobre la solución: Casos de prueba ilimitados acotado con un caso de prueba especial
//
//#include <iostream>
//#include <fstream>
//#include <iomanip>
//using  namespace std;
//// Constantes globales que delimitan el tamaño de la matriz y el numero maximo de tranformaciones
//const int FILAS = 20, COLUMNAS = 20, TRANSFORMACIONES = 10;
//// Matriz que guarda el contenido de la entrada
//typedef int tMatriz[FILAS][COLUMNAS];
//
//// Procedimiento que rota la fila de una matriz hacia la dcha o hacia la izq segun el valor de f
//void rotarFila(tMatriz matriz, int filas, int columnas, int f);
//// Procedimiento que rota la fila de una matriz hacia arriba o hacia abajo segun el valor de c
//void rotarCol(tMatriz matriz, int filas, int columnas, int c);
//// Procedimiento que muestra la matriz
//void mostrar(const tMatriz& matriz, int filas, int columnas);
//
//// función que resuelve el problema
//// comentario sobre el coste, O(f(N)), donde N es ...
//void resolver(tMatriz matriz, int filas, int columnas, string operacion, int operando) {
//    if (operacion == "rotarFila") {
//        rotarFila(matriz, filas, columnas, operando);
//    }
//    else if (operacion == "rotarCol") {
//        rotarCol(matriz, filas, columnas, operando);
//    }
//}
//
//// resuelve un caso de prueba, leyendo de la entrada la
//// configuración, y escribiendo la respuesta
//bool resuelveCaso() {
//    tMatriz matriz;
//    string operacion; // Representa la operacion que se quiere realizar
//    int operando; // Representa la fila o la columna sobre la que se quiere operar
//    int filas = 0, columnas = 0, transformaciones = 0; // Variables para la dimension de la matriz y para el numero de transformaciones
//    int t = 0; // Representa el numero de transformaciones
//    // leer los datos de la entrada
//    cin >> filas >> columnas;
//    if (filas <= FILAS && columnas <= COLUMNAS) {
//        for (int i = 1; i <= filas; i++) {
//            for (int j = 1; j <= columnas; j++) {
//                cin >> matriz[i][j];
//            }
//        }
//    }
//    cin >> t;
//    if (t <= TRANSFORMACIONES) {
//        for (int i = 1; i <= t; i++) {
//            cin >> operacion >> operando;
//            resolver(matriz, filas, columnas, operacion, operando);
//        }
//    }
//
//    if (filas == 0 && columnas == 0)
//        return false;
//
//    //Solucion sol = resolver(datos);
//
//    // escribir sol
//    mostrar(matriz, filas, columnas);
//    return true;
//}
//
//int main() {
//    // ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    std::ifstream in("input.txt");
//    auto cinbuf = std::cin.rdbuf(in.rdbuf());
//    std::ofstream out("output.txt");
//    auto coutbuf = std::cout.rdbuf(out.rdbuf());
//#endif
//
//    while (resuelveCaso());
//
//    // para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//    std::cin.rdbuf(cinbuf);
//    std::cout.rdbuf(coutbuf);
//    system("PAUSE");
//#endif
//    return 0;
//}
//
//void rotarFila(tMatriz matriz, int filas, int columnas, int f) {
//    int aux = -1000; // Varible auxiliar para poder rotar los valores
//    if (f < 0) { // Rotar hacia la izq
//        int fila = abs(f);
//        aux = matriz[fila][1]; // Guardo en aux el valor de la fila fila y columna 1
//        // Solo recorro las columnas porque es lo que me interesa
//        for (int j = 1; j < columnas; j++) { // Desde la primera columna hasta la ultima
//            // En la columna j guardo el elemento de la siguiente columna (j + 1) de la misma fila
//            matriz[fila][j] = matriz[fila][j + 1];
//        }
//        matriz[fila][columnas] = aux; // Guardo en la pos fila, columnas el valor almacenado en aux
//        // que era el elemento en la pos fila,1
//    }
//    else if (f > 0) { // Rotar hacia la dcha
//        aux = matriz[f][columnas]; // Guardo en aux el valor de la pos f,columnas
//        for (int j = columnas; j > 1; j--) { // Desde la ultima columna hasta la primera
//            // En la columna j guardo el elemento de la columna anterior (j - 1) de la misma fila
//            matriz[f][j] = matriz[f][j - 1];
//        }
//        matriz[f][1] = aux; // Guardo en la pos fila,1 el valor almacenado en aux
//        // que era el valor de la pos fila,columnas
//    }
//}
//
//void rotarCol(tMatriz matriz, int filas, int columnas, int c) {
//    int aux = -1000; // Varible auxiliar para poder rotar los valores
//    if (c < 0) { // Rotar hacia arriba
//        int col = abs(c);
//        aux = matriz[1][col]; // Guardo en aux el valor de la pos 1,col
//        for (int i = 1; i < filas; i++) { // Desde la primera fila hasta la ultima
//            // En la fila 1 guardo el valor de la fila siguiente, de la misma columna
//            matriz[i][col] = matriz[i + 1][col];
//        }
//        // En la ultima fila guardo el valor de la primera pos
//        matriz[filas][col] = aux;
//    }
//    else if (c > 0) { // Rotar hacia abajo
//        // En aux guardo el valor de la ultima fila
//        aux = matriz[filas][c];
//        for (int i = filas; i > 1; i--) { // Desde la ultima fila hasta la primera
//            // En la fila i guardo el valor de la fila anterior, dentro de la misma columna
//            matriz[i][c] = matriz[i - 1][c];
//        }
//        // En la primera fila guardo el valor de aux (ultima fila)
//        matriz[1][c] = aux;
//    }
//}
//
//void mostrar(const tMatriz& matriz, int filas, int columnas) {
//    for (int i = 1; i <= filas; i++) {
//        for (int j = 1; j <= columnas; j++) {
//            if (j == columnas) {
//                cout << matriz[i][j] << endl;
//            }
//            else {
//                cout << matriz[i][j] << " ";
//            }
//        }
//    }
//    cout << "---";
//}