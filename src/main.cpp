/*

    Se caso houver problemas de compatibilidade com o compilador
    executar o código no site https://www.onlinegdb.com/

*/ 

#include <iostream> 
#include <string>
#include <math.h>
#include <unistd.h>

using namespace std;

string virgulaParaPonto(string entrada);
bool checaDigito(string input);
void loadingScreen(); 

void telaProblema1(){
    cout<<" ╔══════════════════════════════════════╕"<<endl;
    cout<<" ║              Problema 1              │▒"<<endl;
    cout<<" ╚══════════════════════════════════════╛▒"<<endl;
    cout<<"   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒"<<endl;
    cout<<endl;
}

void telaProblema2(){
    cout<<" ╔══════════════════════════════════════╕"<<endl;
    cout<<" ║              Problema 2              │▒"<<endl;
    cout<<" ╚══════════════════════════════════════╛▒"<<endl;
    cout<<"   ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒"<<endl;
    cout<<endl;
}


int main() {
    setlocale(LC_ALL, "");

    string input;
    bool loop2;
    bool loop1;
    int op;

    while(op!=3) {

        while(true) {
            
            loop1 = true;
            loop2 = true;

            system("cls||clear");
            cout<<endl<<endl;
            cout<<"         ╔════════════════════════════════════╕"<<endl;
            cout<<"         ║              Cálculo I             │▒"<<endl;
            cout<<"         ║       Problemas De Otimização      │▒"<<endl;
            cout<<"         ║                                    │▒"<<endl;
            cout<<"         ║           [1] Problema 1           │▒"<<endl;
            cout<<"         ║           [2] Problema 2           │▒"<<endl;
            cout<<"         ║           [3] Sair                 │▒"<<endl;
            cout<<"         ║                                    │▒"<<endl;
            cout<<"         ║                                    │▒"<<endl;
            cout<<"         ╚════════════════════════════════════╛▒"<<endl;
            cout<<"           ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒"<<endl<<endl;
            cout<<"                        Opcão: ";
            cin>>input;

            if(input.length() < 2 && (input[0] == '1' || input[0] == '2' || input[0] == '3'))
                break;
        }

        op = stof(input);


        switch(op) {
            case 1:
                float alturaCilindro, volumeCilindro, custoBase, custoLateral,
                    raioCilindro, dimensaoBase, dimensaoLateral, custoEmbalagem;
                int opcaoTampa;
                
                
                while(loop1) {

                    loop2 = true;

                    system("cls||clear");
                    telaProblema1();
                    while(true) {
                        cout<<"   Volume do recipiente "<<endl;
                        cout<<"   Valor: ";
                        cin>>input;
                        cout<<endl;
                    
                        input = virgulaParaPonto(input);

                        if(checaDigito(input)) {
                            volumeCilindro = stof(input) ;
                            break;
                        } else {
                            system("cls||clear");
                            telaProblema1();
                            cout<<"         *** Somente números! ***"<<endl<<endl;
                        }
                    
                    }

                    system("cls||clear");
                    telaProblema1();
                    while(true) {
                        cout<<"         .-----.           .-----.  "<<endl;
                        cout<<"        |._____.|         |///////| "<<endl;
                        cout<<"        |       |         |       | "<<endl;
                        cout<<"        |       |         |       | "<<endl;
                        cout<<"        '._____.'         '._____.' "<<endl<<endl;
                        cout<<"     [1] Sem tampa      [2] Com tampa"<<endl<<endl;
                        cout<<"                 Opcão: ";
                        cin>>input;

                        if(input.size() < 2 && (input[0] == '1' || input[0] == '2')) {
                            opcaoTampa = stoi(input);
                            break;
                        } else {
                            system("cls||clear");
                            telaProblema1();
                            cout<<"          *** Opcao Inválida! ***"<<endl<<endl;
                        }

                    }

                    system("cls||clear");
                    telaProblema1();
                    while(true) {
                        cout<<"   Custo da base do recipiente "<<endl;
                        cout<<"   Valor: ";
                        cin>>input;

                        input = virgulaParaPonto(input);

                        if(checaDigito(input)) {
                            custoBase = stof(input);
                            break;
                        } else {
                            system("cls||clear");
                            telaProblema1();
                            cout<<"         *** Somente números! ***"<<endl<<endl;
                        }
                    
                    }

                    system("cls||clear");
                    telaProblema1();
                    while(true) {
                        cout<<"   Custo do material usado na lateral "<<endl;
                        cout<<"   Valor: ";
                        cin>>input;

                        input = virgulaParaPonto(input);

                        if(checaDigito(input)) {
                            custoLateral = stof(input);
                            break;
                        } else {
                            system("cls||clear");
                            telaProblema1();
                            cout<<"         *** Somente números! ***"<<endl<<endl;
                        }

                    }

                    //Calculo...
                    raioCilindro = pow(((custoLateral * volumeCilindro) / (M_PI * custoBase)), 1/3.0);

                    alturaCilindro = volumeCilindro / (M_PI * pow(raioCilindro, 2));
                    dimensaoBase = opcaoTampa * M_PI * pow(raioCilindro, 2);
                    dimensaoLateral = 2 * M_PI * raioCilindro * alturaCilindro;
                    
                    custoEmbalagem = dimensaoBase*custoBase + dimensaoLateral*custoLateral;
                    custoBase = dimensaoBase * custoBase;
                    custoLateral = dimensaoLateral * custoLateral;
                    
                    loadingScreen();

                    while(loop2) {
                        system("cls||clear");
                        cout<<endl<<endl;
                        printf("        ╔════════════════════════════════════╕\n");
                        printf("        ║               Solução              │\n");
                        printf("        ╚════════════════════════════════════╛\n");
                        printf("        | Base: % 25.2fcm³ |\n", dimensaoBase);
                        printf("        | Lateral:   % 20.2fcm³ |\n", dimensaoLateral);
                        printf("        | Custo da Base R$: %16.2f |\n", custoBase);
                        printf("        | Custo da Lateral R$: %13.2f |\n", custoLateral);
                        printf("        | Custo da Embalagem R$: %11.2f |\n", custoEmbalagem);
                        printf("        +------------------------------------+\n\n");

                        cout<<"                [1] Calcular novamente"<<endl;
                        cout<<"                [2] Menu principal"<<endl;
                        cout<<endl;
                        cout<<"                       Opção: ";
                        cin>>input;

                        if(input.length() < 2 && (input[0] == '1' || input[0] == '2')) {
                                
                            if(input[0] == '1')
                                loop2 = false; 

                            else if(input[0] == '2') {
                                loop1 = false;
                                loop2 = false;
                            }

                        }
                    }
                }
                break;
            case 2:
                float distMargemRio, distFabrica, custoPorRio, custoPorTerra,
                    varAuxTerra, varAuxRio, aux, icognita, percorridoTerra, 
                    percorridoRio, menorCusto;
                
                while(loop1) {

                    loop2 = true;
                    
                    system("cls||clear");
                    telaProblema2();
                    while(true) {
                        cout<<"   Distancia em metros da Fabrica "<<endl;
                        cout<<"   Metros: ";
                        cin>>input;
                        cout<<endl;

                        input = virgulaParaPonto(input);

                        if(checaDigito(input)) {
                            distFabrica = stof(input);
                            break;
                        } else {
                            system("cls||clear");
                            telaProblema2();
                            cout<<"         *** Somente números! ***"<<endl<<endl;
                        }
                    
                    }
                    system("cls||clear");
                    telaProblema2();
                    while(true) {

                        cout<<"   Distancia da margem do Rio "<<endl;
                        cout<<"   Metros: ";
                        cin>>input;
                        cout<<endl;
                    
                        input = virgulaParaPonto(input);

                        if(checaDigito(input)) {
                            distMargemRio = stof(input);
                            break;
                        } else {
                            system("cls||clear");
                            telaProblema2();
                            cout<<"         *** Somente números! ***"<<endl<<endl;
                        }
                    
                    }

                    system("cls||clear");
                    telaProblema2();
                    while(true) {
                    
                        cout<<"   Custo da distancia pelo rio por metro"<<endl;
                        cout<<"   Valor: R$ ";
                        cin>>input;
                        cout<<endl;
                    
                        input = virgulaParaPonto(input);

                        if(checaDigito(input)) {
                            custoPorRio = stof(input);
                            break;
                        } else {
                            system("cls||clear");
                            telaProblema2();
                            cout<<"         *** Somente números! ***"<<endl<<endl;
                        }
                    
                    }
                    system("cls||clear");
                    telaProblema2();
                    while(true) {
                    
                        cout<<"   Custo da distancia pela terra por metro"<<endl;
                        cout<<"   Valor: R$ ";
                        cin>>input;
                        cout<<endl;
                    
                        input = virgulaParaPonto(input);

                        if(checaDigito(input)) {
                            custoPorTerra = stof(input);
                            break;
                        } else {
                            system("cls||clear");
                            telaProblema2();
                            cout<<"         *** Somente números! ***"<<endl<<endl;
                        }
                    
                    }
                    
                    //Calculo da distancia..
                    varAuxRio = pow(custoPorRio, 2);
                    varAuxTerra = pow(custoPorTerra, 2);
                    aux = abs(varAuxRio - varAuxTerra);
                    icognita = sqrt(varAuxTerra * pow(distMargemRio, 2) / aux);
                    
                    percorridoRio = sqrt(pow(distMargemRio, 2) + pow(icognita, 2)); 
                    percorridoTerra = distFabrica - icognita; 
                    
                    //Calculo do menor custo...
                    menorCusto = (custoPorRio * percorridoRio) + (custoPorTerra * percorridoTerra);

                    loadingScreen();
                    while(loop2) {
                        system("cls||clear");
                        cout<<endl<<endl;
                        printf("        ╔════════════════════════════════════╕\n");
                        printf("        ║               Solução              │\n");
                        printf("        ╚════════════════════════════════════╛\n");
                        printf("        | Menor Custo R$: %18.2f |\n", abs(menorCusto));
                        printf("        | Por terra: %22.2fm |\n", abs(percorridoTerra));
                        printf("        | Por rio:   %22.2fm |\n", abs(percorridoRio));
                        printf("        +------------------------------------+\n\n");

                        cout<<"                [1] Calcular novamente"<<endl;
                        cout<<"                [2] Menu principal"<<endl;
                        cout<<endl;
                        cout<<"                       Opção: ";
                        cin>>input;

                        if(input.length() < 2 && (input[0] == '1' || input[0] == '2')) {
                            
                            if(input[0] == '1')
                                loop2 = false; 

                            else if(input[0] == '2') {
                                loop1 = false;
                                loop2 = false;
                            }

                        }
                    }
                }

                break;
            
            case 3:
                break;
        }
    }



   return 0;
}

bool checaDigito(string input) {

    for(int i = 0; i < (int)input.length(); i++) 
        if(!((input[i] >= 48 && input[i] <= 57) || input[i] == 46)){ 
            return false;
        }
    return true;

}

string virgulaParaPonto(string input) {

    int i, inputLength = input.length();

    for(i = 0; i < inputLength; i++)
        if(input[i] == ',')
            input[i] = '.';
    
    return input;
}

void loadingScreen() {

    string progressBar = "";
    system("clear");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                      Calculando"<<endl;
    cout<<"             ";
    for(int i = 0; i < 8; i++) {
        cout<<progressBar<<flush;
        progressBar += "▒";
        usleep(100000);
    }
}

