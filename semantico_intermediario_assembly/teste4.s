/* 
Este teste contém as seguintes validações semânticas e escrita de intermediario e assembly:
    - Outras funções padrões da biblioteca de Simples
        - Função imprimer
            - Valida corretamente se o nome da função existe
            - Funciona somente para valores direto (não funciona com variável)
        - Função gere_inteiro
            - Valida corretamente se o nome da função existe
            - Retorna um inteiro aleatório entre 0 e 100.
        - Função inverter
            - Valida corretamente se o nome da função existe
            - Funciona apenas para valores direto (não funciona com variável)
            - Retorna o valor correto de acordo com a especificação da função
    - As operações "imprimei" foram utilizadas apenas para validação no terminal.
*/

global:
b : inteiro := 10

ação:
    imprimer(2.23);
    b := gere_inteiro();
    imprimei(b);
    b := inverter(0);
    imprimei(b);
    b := inverter(50);
    imprimei(b)
