Tipo:
a = inteiro
b = real
c = cadeia

/* inicio comentario
linha
linha
fim comentario */

regaluno = {idade: inteiro, peso: real, nome: cadeia}

vetdeinteiros = [1,2] de inteiro
vetdereal = [4] de real
vetdecadeia = [1,2] de cadeia
vettipodeclarado = [1,3] de d
vetalunos = [3] de regaluno

/* globais */
gloBal:
globalinteiro : inteiro := 10
globalreal : real := 1.2
globalcadeia : cadeia := "Alface"

pessoa1 : registroaluno := {idade = 20+10, peso = 80.2, nome = "Alguem"}
pessoa2 : registroaluno := {idade = idademichely, peso = pesomichely, nome = nomemichely}

vetint: vetdeinteiros := 0
vetreal: vetdereal := 0.0
vetcadeia: vetdecadeia := nulo

/* funções */
FUNÇÃO:
/* procedimentos */
imprimemedia (valor nome: cadeia, ref notas: vetdereal) =
local:
soma: real := 0.0
media: real := 0.0
ação:
soma := notas[0] + notas[1] + notas[2] + notas[3];
media := soma / 4;
imprime(nome, media)

procsemargs() =
ação:
imprimemedia("aluno1", notas);
imprime("Cebola")

/* função */
calculamedia (ref notas: vetdereal) : real =
local:
media: real := 0.0
ação:
media := (notas[0] + notas[1] + notas[2] + notas[3])/4;
regmichely := {idade = 21, peso = 50.3, nome = "Michely"};
retorne media

func1() : inteiro =
local:
x: real := 0
ação:
x := 1 + 5 * 2;
x := (1 + 5) * 2;
x := calculamedia(notas);
retorne x

AÇÃO:
regmichely := {idade = 21, peso = 50.3, nome = "Michely"};

regbanoff.idade := 4;
regbanoff.peso := 3.0;
regbanoff.nome := "banoff";

notasdamichely[0] := 2.3/0.1;
notasdamichely[1] := 5.2 - 2;
notasdamichely[1+1] := 7.6;
notasdamichely[6/2] := 4.9;

se a & b verdadeiro
imprimemedia(regmichely, notasdamichely)
fse;

se a == (b | c) verdadeiro
imprimemedia(regmichely, notasdamichely)
falso
procsemargs()
fse;

para a de 0 limite 10 faça
a := calculamedia(notasdamichely);
se a <= 3 | a >= 3 | a < 3 | a > 3 verdadeiro
pare
falso
continue
fse
fpara;

enquanto a != 0 faça
a := func1()
fenquanto