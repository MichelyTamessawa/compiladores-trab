/* 
Este teste contém as seguintes validações semânticas e escrita de intermediario e assembly:
    - Expressão binária
        - Operações de soma, subtração e multiplicação estão funcionando corretamente.
        - Para essas operações, é possível tanto realizar elas com valores inteiros quanto
        com valores de variáveis (desde que seja do tipo inteiro)
        - Quantos valores forem necessário (não funciona com parenteses, tem que ser o valor solto)
        - A precedência dos operadores está funcionando, observe a linha 24
    - As operações "imprimei" foram utilizadas apenas para validação no terminal.
*/

Tipo:
    a = inteiro
    c = a

global:
b : inteiro := 10
c : c := b

ação:
    b := c + 2;
    imprimei(b);
    b := 5 - 2 + 1;
    imprimei(b);
    b := c * c + c - c * b; /* resultado esperado: 70 */
    imprimei(b)