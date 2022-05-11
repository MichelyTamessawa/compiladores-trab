/* 
Este teste contém as seguintes validações semânticas e escrita de intermediario e assembly:
    - Validação se a declaração do tipo é válida (o tipo sendo atribuido existe);

    - Validação de declaração de global:
        - Valida se o tipo da variável sendo criada existe;
        - Aloca espaço para a variável b no sistema; (intermediário e assembly)
        - Atribui o valor 15 para o endereço alocado; (intermediário e assembly)
    - Validação de chamada de função:
        - Valida se o nome da função existe
        - Chama a função externa passando o valor do parâmetro para a função (intermediario e assembly)
        - Para a função imprimei, os parâmetros aceitos são um literal inteiro e uma variável com valor inteiro
*/

Tipo:
    a = inteiro

global:
b : a := 15

ação:
    imprimei(10);
    imprimei(b)