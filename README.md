# Trabalho de Algoritmos - Atores de Hollywood

Este repositório contém um código desenvolvido por mim em novembro de 2023 como parte de um trabalho para a disciplina de Algoritmos. O projeto foi criado para gerenciar e manipular dados de atores de Hollywood, incluindo informações como nome, ano de nascimento, filme mais famoso e número de Oscars ganhos.

## Objetivo

O objetivo deste trabalho foi praticar conceitos de programação em C++, como:
- Manipulação de arquivos (leitura e escrita de arquivos CSV e binários).
- Uso de estruturas de dados (`struct`).
- Implementação de algoritmos de ordenação (Insertion Sort).
- Desenvolvimento de uma interface simples para interação com o usuário.

## Funcionalidades

O programa oferece as seguintes funcionalidades:
1. **Imprimir lista completa de atores**.
2. **Imprimir lista com limite de registros**.
3. **Inserir novo registro**.
4. **Remover registro**.
5. **Buscar ator por ID**.
6. **Buscar ator por nome**.
7. **Salvar dados em arquivo binário**.
8. **Ordenar registros por ID**.
9. **Ordenar registros por ano de nascimento**.
10. **Ler dados de arquivo binário**.

## Melhorias Futuras

Desde que este código foi desenvolvido, adquiri mais experiência e consigo identificar várias melhorias que poderiam ser implementadas:
- **Remover espaços em branco do vetor**: Atualmente, o vetor pode possuir espaços não utilizados que poderiam ser otimizados.
- **Utilizar vetores dinâmicos**: Em vez de um vetor estático, utilizar estruturas dinâmicas como `std::vector` para melhor gerenciamento de memória.
- **Simplificar a interface de busca**: Unificar as opções de busca (por ID e por nome) em uma única função mais eficiente.
- **Simplificar a interface de ordenação**: Unificar as opções de ordenação em uma única função com parâmetros flexíveis.
- **Utilizar funções de bibliotecas padrão**: Aproveitar funções da biblioteca padrão do C++ (como `std::sort`) para simplificar o código.
- **Melhorar a modularização**: Dividir o código em funções e arquivos menores para melhor organização e reutilização.
