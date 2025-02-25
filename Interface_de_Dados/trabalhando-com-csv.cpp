
/*

trabalho feito por: Lucas Torquato

tema: Atores de Hollywood

*/

#include <iostream>     //inclui as bibliotecas
#include <fstream>
#include <algorithm>


using namespace std;

struct Dados {          //struct que armazena os registros
    int id;
    string ator;
    int nascimento;
    string filme;
    int oscar;
};

void escreverBinario(Dados dados[], int tamanho, const string& nomeArquivo) {
    ofstream saida(nomeArquivo, ios_base::out | ios_base::binary);
    if (!saida) {
        cerr << "Erro ao abrir o arquivo para escrita." << endl;
        return;
    }

    for (int i = 0; i < tamanho; ++i) {
        // Escreve os campos inteiros
        saida.write(reinterpret_cast<char*>(&dados[i].id), sizeof(dados[i].id));
        saida.write(reinterpret_cast<char*>(&dados[i].nascimento), sizeof(dados[i].nascimento));
        saida.write(reinterpret_cast<char*>(&dados[i].oscar), sizeof(dados[i].oscar));

        // Escreve o tamanho da string e depois a string em si
        size_t tamanhoAtor = dados[i].ator.size();
        saida.write(reinterpret_cast<char*>(&tamanhoAtor), sizeof(tamanhoAtor));
        saida.write(dados[i].ator.c_str(), tamanhoAtor);

        size_t tamanhoFilme = dados[i].filme.size();
        saida.write(reinterpret_cast<char*>(&tamanhoFilme), sizeof(tamanhoFilme));
        saida.write(dados[i].filme.c_str(), tamanhoFilme);
    }

    saida.close();
}

void lerBinario(Dados dados[], int tamanho, const string& nomeArquivo) {
    ifstream entrada(nomeArquivo, ios_base::in | ios_base::binary);
    if (!entrada) {
        cerr << "Erro ao abrir o arquivo para leitura." << endl;
        return;
    }

    for (int i = 0; i < tamanho; ++i) {
        // Lê os campos inteiros
        entrada.read(reinterpret_cast<char*>(&dados[i].id), sizeof(dados[i].id));
        entrada.read(reinterpret_cast<char*>(&dados[i].nascimento), sizeof(dados[i].nascimento));
        entrada.read(reinterpret_cast<char*>(&dados[i].oscar), sizeof(dados[i].oscar));

        // Lê o tamanho da string e depois a string em si
        size_t tamanhoAtor;
        entrada.read(reinterpret_cast<char*>(&tamanhoAtor), sizeof(tamanhoAtor));
        dados[i].ator.resize(tamanhoAtor);
        entrada.read(&dados[i].ator[0], tamanhoAtor);

        size_t tamanhoFilme;
        entrada.read(reinterpret_cast<char*>(&tamanhoFilme), sizeof(tamanhoFilme));
        dados[i].filme.resize(tamanhoFilme);
        entrada.read(&dados[i].filme[0], tamanhoFilme);
    }

    entrada.close();
}

void imprimir(Dados p){     //imprime um registro
if(p.id!=-1){
	cout << p.id << "\t" << p.ator << "\t" << p.nascimento << "\t" << p.filme << "\t" << p.oscar;
	cout<<endl;
    }
}

void imprimeVetor(Dados dados[],int tamanho){      //imprime todos os registros
	cout << endl;
	for(int i = 0; i < tamanho; i++){
		imprimir(dados[i]);//imprime os dados
	}
}

void ler(Dados dados[], int tamanho,const string& nomeArquivo) {   //le o arquivo e manda para o struct
    ifstream arquivo(nomeArquivo);
    int total;
    char lixo;
    string linha;
    arquivo>>total;
    arquivo.ignore();
    getline(arquivo, linha);

    for(int i = 0; i < tamanho; i++){
			arquivo>>dados[i].id; //le o identificador
			arquivo>>lixo; //coloca o separador numa variavel que eu não vou usar (decarta a virgula q separa as colunas)
			getline(arquivo, dados[i].ator, ','); //nome com espaço
			arquivo>>dados[i].nascimento; //le a data
			arquivo>>lixo;
			getline(arquivo, dados[i].filme, ','); //le o filme com espaços
			arquivo>>dados[i].oscar; //le numero de oscars
			arquivo.ignore();
    }
}

Dados* inserirRegistro(Dados dados[], int &tamanho) {  //adiciona um registro novo no arquivo
Dados* novo = new Dados[tamanho+1];
string nome1,nome2,filme1,filme2;
copy(dados,dados+tamanho,novo);
tamanho+=1;
novo[tamanho-1].id=tamanho;
cout<<"Digite o nome:"<<endl;
cin>>nome1>>nome2;
novo[tamanho-1].ator=nome1+" "+nome2;
cout<<"Digite o ano de nascimento:"<<endl;
cin>>novo[tamanho-1].nascimento;
cout<<"Digite o filme:"<<endl;
cin>>filme1>>filme2;
novo[tamanho-1].filme=filme1+" "+filme2;
cout<<"Digite quantos oscars:"<<endl;
cin>>novo[tamanho-1].oscar;
delete[] dados;
return novo;
}

void removerRegistro(Dados dados[], int tam,int a) {  //remove um registro do arquivo
for(int i=0;i<tam;i++){
    if(dados[i].id==a){
    dados[i].id=-1;
    }
}
}

void buscarPorID(Dados dados[], int tamanho) {  //busca um registro por id
    int id;
    bool j;
    cout << "Digite o id a ser buscado: "<<endl;
    cin >> id;

    for (int i = 0; i < tamanho; ++i) {
        if (dados[i].id == id) {
            imprimir(dados[i]);
            j=true;
        }
    }
    if(not(j)){
        cout<<"ID nao encontrado";
    }
}

void buscarPorNome(Dados dados[], int tamanho) {  //busca um registro por nome
    string nome1,nome2;
    bool j;
    cout << "Digite o nome a ser buscado: "<<endl;
    cin >> nome1>>nome2;

    for (int i = 0; i < tamanho; ++i) {
        if (dados[i].ator == nome1+" "+nome2) {
            imprimir(dados[i]);
            j=true;
        }
    }
    if(not(j)){
        cout<<"Nome nao encontrado";
    }
}

void ordenaPorID(Dados dados[],int tamanho){
    Dados aux;


    for(int j=0;j<tamanho-1;j++){
        for(int i=j+1;i>0;i--){
            if(dados[i].id<dados[i-1].id){              //insertion sort
                aux = dados[i];
                dados[i]=dados[i-1];
                dados[i-1]=aux;
            }
        }
    }
}

void ordenaPornascimento(Dados dados[],int tamanho){
    Dados aux;


    for(int j=0;j<tamanho-1;j++){
        for(int i=j+1;i>0;i--){
            if(dados[i].nascimento<dados[i-1].nascimento){              //insertion sort
                aux = dados[i];
                dados[i]=dados[i-1];
                dados[i-1]=aux;
            }
        }
    }
}

int main() {
    int a;                              //variavel que recebe qual registro o usuario quer remover
    int tam=100;                        //variavel global que mostra o tamanho do vetor
    Dados* dados = new Dados[100];      //inicializacao do vetor
    int opcao,limite;              //variavel pra saber a opcao do menu
    do {
        cout << "\nMenu:\n";
        cout << "1. Imprimir lista"<<endl;
        cout << "2. Imprimir com limite"<<endl;
        cout << "3. Inserir novo registro"<<endl;
        cout << "4. Remover registro"<<endl;                   //imprime o menu na tela
        cout << "5. Buscar por ID"<<endl;
        cout << "6. Buscar por Nome"<<endl;
        cout << "7. Transformar em binario"<<endl;
        cout << "8. Ordenar por ID"<<endl;
        cout << "9. Ordenar por nascimento"<<endl;
        cout << "10. Ler arquivo binario"<<endl;
		cout << "11. Ler arquivo csv"<<endl;
        cout << "0. Sair"<<endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;                           //recebe a opcao



        switch (opcao) {                //faz a funcao de acordo com a opcao que foi escolhida
            case 1:
            
                    imprimeVetor(dados,tam);            //imprime todo o vetor

                break;
            case 2:
                {
                    cout<<"Digite ate qual elemento quer imprimir:"<<endl;
                    cin>>limite;
                    if(limite>tam){                                     //imprime vetor porem com limite
                        imprimeVetor(dados,tam);
                    }
                    else{
                        imprimeVetor(dados,limite);
                    }
                }
                break;
            case 3:
                {
                    
                    dados=inserirRegistro(dados,tam);                             //novo registro

                }
                break;
            case 4:
                {
                    
                    
                    cout<<"Escolha o id do registro que deseja remover: ";        //remove registro //diminuir tamanho do vetor
                    cin>>a;                
                    removerRegistro(dados,tam,a);
                
                }
                break;
            case 5:
                {
                    buscarPorID(dados,tam);
                } 
                
                break;
            case 6:
                {
                    
                    buscarPorNome(dados,tam);

                }
                break;
			case 7: {

					escreverBinario(dados, tam, "pasBinario.bin");

				}
                break;
             case 8:
                {
                    
                    ordenaPorID(dados,tam);

                }
                break;
             case 9:
                {
                    
                    ordenaPornascimento(dados,tam);

                }
                break;
			case 10: {

					lerBinario(dados, tam, "pasBinario.bin");

				}
                break;
			case 11: {

					ler(dados,tam,"dados.csv");         //le o arquivo e armazena no vetor

				}
            case 0:
                cout << "Saindo do programa.\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    } while (opcao != 0);



    delete[] dados;  // Libera a memória 

    return 0;
}
