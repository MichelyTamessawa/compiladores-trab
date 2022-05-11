Tipo:
    a = inteiro
    c = a

global:
b : inteiro := 10
c : c := 32
e : c := 10
f : inteiro := c

ação:
    imprimei(c);
    imprimei(20);
    c := 5 + 2;
    imprimei(c);
    c := b - 4;
    imprimei(c);
    c := 2 * 2;
    imprimei(c);
    c := b;
    imprimei(c);
    imprimei(e);
    e := e - 12;
    imprimei(e); /* impressao de um numero negativo */
    imprimer(2.5);
    b := gere_inteiro();
    imprimei(b);
    c := inverter(0);
    imprimei(c); /* imprimir 1 */
    c := inverter(5);
    imprimei(c); /* imprimir 0 */
    imprimei(f)