#include <iostream>
#include <malloc.h>
#include <locale.h>

using namespace std;

void completaMatriz(float matriz[2][4], int comando);

float *det(float matriz[2][4]);

void impirmeMatriz(float matriz[2][4], int comando);

void completaMatriz2(float matriz[3][4], int comando);

float *det2(float matriz[3][4]);

void imprimeMatriz2(float matriz[3][4], int comando);

int main()
{
    setlocale(LC_ALL, "");

    int comando = 0;

    do{
		system("cls");          
    	cout << "  +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+" << endl;
    	cout << "  |    Sistema Lineares - Regra de Cramer     |" << endl;
    	cout << "  +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+" << endl;
    	cout << "  |                                           |" << endl;
		cout << "  | Entre com uma opcao:                      |" << endl;
    	cout << "  |                                           |" << endl;
    	cout << "  | [1] 2 Variaveis                           |" << endl;
    	cout << "  | [2] 3 Variaveis                           |" << endl;
    	cout << "  | [0] Sair                                  |" << endl;
    	cout << "  |                                           |" << endl;
    	cout << "  +-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+" << endl;
    	cout << "\n Digite a opção desejada: ";
    	cin >> comando;
    	
        float matriz[comando + 1][4], *determinante, x, y, z;
        char tc;
        
        switch (comando)
		{
            case 1:
                system("cls");
                completaMatriz(matriz, comando);
                impirmeMatriz(matriz, comando);
                determinante = det(matriz);

                x = determinante[1] / determinante[0];
                y = determinante[2] / determinante[0];

				if(determinante[0] == 0)
					cout << "Esse sistime e impossvel pois a determinante é igual 0.";
				else{
	                cout << endl << "Determinante: " << determinante[0] << endl << endl;
	                cout << "Valor x: " << x << endl;
	                cout << "Valor y: " << y << endl;
                }

            	cin >> tc;
                break;
                
            case 2:
                system("cls");
                completaMatriz2(matriz, comando);
                imprimeMatriz2(matriz, comando);
                determinante = det2(matriz);

                x = determinante[1] / determinante[0];
                y = determinante[2] / determinante[0];
                z = determinante[3] / determinante[0];

				if(determinante[0] == 0)
					cout << "Esse sistime e impossvel pois a determinante é igual 0.";
				else{
	                cout << endl << "Determinante: " << determinante[0] << endl << endl;
	                cout << "Valor x: " << x << endl;
	                cout << "Valor y: " << y << endl;
	                cout << "Valor z: " << z << endl;
            	}

                cin >> tc;
                break;
            case 0: return 0;
		}
	} while(comando < 2 || comando > 4);
}

void completaMatriz (float matriz[2][4], int comando)
{
    char coef[2] = {'x', 'y'}; 
	
	cout << "Insira seu sistema:" << endl;
    for(int i = 0; i < comando + 1; i++){
        cout << endl << i+1 << "a Expressao: " << endl << endl;
        for(int j = 0; j < comando + 1; j++){
            cout << "  Coeficiente da variavel " << coef[j] << ": ";
            cin >> matriz[i][j];

            if(j == 1){
                cout << "  Resultado da expressao: ";
                cin >> matriz[i][2];
            }
        }
    }
}

float *det(float matriz[2][4]) 
{
    float *determinanteGeral;
    determinanteGeral = (float *)malloc(3 * sizeof(float));
    
    determinanteGeral[0] = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];

    //Determinante de x
    determinanteGeral[1] = matriz[0][2] * matriz[1][1] - matriz[1][2] * matriz[0][1];
    
    //determinanteerminante de y
    determinanteGeral[2] =  matriz[0][0] * matriz[1][2] - matriz[0][2] * matriz[1][0];
    
    return determinanteGeral;
}

void impirmeMatriz (float matriz[2][4], int comando) 
{
	char coef[2] = {'x', 'y'}; 
	char tc;

    cout << endl << "Sistema Linear:" << endl;
    
    for(int i = 0; i < comando + 1; i++){
        for(int j = 0; j <= comando + 1; j++){
            if (matriz[i][j] < 0)
                cout << "+ " << "(" << matriz[i][j] << coef[j] << ")" << " ";
            else
			cout << "+ " << matriz[i][j] << coef[j] << " ";

            if(j == 1){
                cout << "= " << matriz[i][2] << endl;
                break;
            }
        }
    }
}

void completaMatriz2 (float matriz[3][4], int comando)
{
    char coef[3] = {'x', 'y', 'z'}; 

	cout << "Insira seu sistema:" << endl;
	
    for(int i = 0; i < comando + 1; i++) {
        cout << endl << i+1 << "a Expressao: " << endl << endl;
        for(int j = 0; j < comando + 1; j++) {
            cout << "  Coeficiente da variavel " << coef[j] << ": ";
            cin >> matriz[i][j];

            if( j == 2 ) {
                cout << "  Resultado da expressao: ";
                cin >> matriz[i][3];
            }
        }
    }
}

float *det2(float matriz[3][4]) 
{
    float *determinanteGeral;
    determinanteGeral = (float *)malloc(4 * sizeof(float));
    
    determinanteGeral[0] = 
    (matriz[0][0] * matriz[1][1] * matriz[2][2] + matriz[0][1] * matriz[1][2] * matriz[2][0] + matriz[0][2] * matriz[1][0] * matriz[2][1])  - (matriz[0][2] * matriz[1][1] * matriz[2][0] + matriz[0][0] * matriz[1][2] * matriz[2][1] + matriz[0][1] * matriz[1][0] * matriz[2][2]); 

    determinanteGeral[1] = 
    (matriz[0][3] * matriz[1][1] * matriz[2][2] + matriz[0][1] * matriz[1][2] * matriz[2][3] + matriz[0][2] * matriz[1][3] * matriz[2][1])   - (matriz[0][2] * matriz[1][1] * matriz[2][3] + matriz[0][3] * matriz[1][2] * matriz[2][1] + matriz[0][1] * matriz[1][3] * matriz[2][2]);
    
    determinanteGeral[2] = 
    (matriz[0][0] * matriz[1][3] * matriz[2][2] + matriz[0][3] * matriz[1][2] * matriz[2][0] + matriz[0][2] * matriz[1][0] * matriz[2][3])  - (matriz[0][2] * matriz[1][3] * matriz[2][0] + matriz[0][0] * matriz[1][2] * matriz[2][3] + matriz[0][3] * matriz[1][0] * matriz[2][2]);
    
    _flushall();
    determinanteGeral[3] = 
    (matriz[0][0] * matriz[1][1] * matriz[2][3] + matriz[0][1] * matriz[1][3] * matriz[2][0] + matriz[0][3] * matriz[1][0] * matriz[2][1])    - (matriz[0][3] * matriz[1][1] * matriz[2][0] + matriz[0][0] * matriz[1][3] * matriz[2][1] + matriz[0][1] * matriz[1][0] * matriz[2][3]);
 
    return determinanteGeral;
}

void imprimeMatriz2 (float matriz[3][4], int comando) 
{
    char coef[3] = {'x', 'y', 'z'}; 

    cout << endl << "Sistema Linear:" << endl;

    for(int i = 0; i < comando + 1; i++) {
        for(int j = 0; j <= comando + 1; j++) {
            if (matriz[i][j] < 0)
                cout << "+ " << "(" << matriz[i][j] << coef[j] << ")" << " ";
            else 
                cout << "+ " << matriz[i][j] << coef[j] << " ";
				
            if( j == 2) {
                cout << "= " << matriz[i][3] << endl;
                break;
            }
        }
    }
}
