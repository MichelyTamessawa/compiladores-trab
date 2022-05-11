/* 
Este teste contém as seguintes validações semânticas e escrita de intermediario e assembly:
    - Criação de um tipo a partir de outro tipo (é validado se esse outro tipo existe)
    - Declaração de variável global:
        - Criação de uma variável com o tipo igual ao nome da variável (Funciona pois são diferentes tabelas de símbolos);
        - Atribuição do valor de uma variável pré declarada para essa nova variável (intermediario e assembly)
    - Utilização da função "imprimei" apenas para validar o resultado no terminal.
*/

Tipo:
    a = inteiro
    c = a

global:
b : inteiro := 10
c : c := b

ação:
    imprimei(c)