# Trabalho de Compiladores


## O que foi implementado:
- Analisador léxico (completo);

- Analisador sintático (completo);

- Árvore sintática abstrata (completo);

- Analisador semântico:
    - Criação de 3 tabelas de símbolos: tipos, variável e função;
    - Declaração de tipos com identificador:
        - a = inteiro
        - b = a
    - Declaração de globais: Validação da variável e do tipo, mas não há validação entre o tipo e o valor  atribuído:
        - a : inteiro := 10; nesse caso, não é verificado se 10 é inteiro;
    - Comando atribuição para inteiro: Validação se a variável existe;
    - Chamada de função: Validação se a função existe;

- Gerador de representação intermediária e código final:
    - Foi considerado que no programa há apenas uma função, a "main".
    - Todas as instruções realizadas no comando "ação:" são executadas dentro do escopo dessa "main".
    - Declaração de globais (inicialização da variável):
        - inteiro -> c : inteiro := 0; d : a := 28
    - Comando atribuição:
        - inteiro -> a := 10;
        - variável -> a := b;
        - operação binária +, - e * -> a := 10 + 5; a := b - 2; a := 2 * 2;
        - retorno de função -> a := gera_inteiro(); a := inverter(1);
    - Chamada de função: 
        - imprimei(inteiro): passando int e variável
            - imprimei(10)
            - imprimei(a)
        - imprimer(real): passando real
            - imprimer(2.5)
        - gere_inteiro() -> Retorna um número inteiro aleatório
        - inverter(i) -> Retorna 1 se a i for zero, ou 0 caso contrário.


A versão do LLVM e clang utilizada foi a 13.
Flex versão 2.6.4
Bison versão 3.7.6

Para realizar a compilação do trabalho: 
    `$ bash script.sh `

Para compilar o arquivo com a linguagem Simples:
    `$ ./sc [-i] [-s] [-o <destino>] <fonte>`

Para rodar o executavel gerado:
    `$ ./<destino>` ou
    `$ ./a.out`

Há um código de exemplo para execução neste repositório, para executa-lo:
    `$ ./sc -i -s test.s` e
    `$ ./a.out`