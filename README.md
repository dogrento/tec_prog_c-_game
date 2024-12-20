# tec_prog_c++_game
Repositorio referente ao projeto proposto pela Disciplina Tecnicas de Programacao da UTFPR.

### Requisitos Funcionais
1. Apresentar graficamente menu de opções aos
usuários do Jogo, no qual pode se escolher fases,
escolher ver colocação (ranking) de jogadores e
escolher demais opções pertinentes (previstas nos
demais requisitos).

2. Permitir um ou dois jogadores com representação
gráfica aos usuários do Jogo, sendo que no último
caso é para que os dois joguem de maneira
concomitante.

3. Disponibilizar ao menos duas fases distintas que
podem ser jogadas sequencialmente ou
selecionadas, via menu, nas quais jogadores
tentam neutralizar inimigos por meio de algum
artifício e vice-versa.

4. Ter pelo menos três tipos distintos de inimigos,
cada qual com sua representação gráfica, sendo
que ao menos um deles deve poder lançar projetil
contra o(s) jogador(es) e um dos inimigos dever
ser um ‘chefão’.

5. Ter a cada fase ao menos dois tipos de inimigos
(um deles exclusivo nela) com número aleatório de
instâncias, podendo ser várias instâncias
(definindo um máximo) e sendo pelo menos 3
instâncias para cada tipo que estiver na fase.

6. Ter três tipos de obstáculos, cada qual com sua
representação gráfica, sendo que ao menos um
causa dano em jogador se colidirem.

7. Ter em cada fase ao menos dois tipos de
obstáculos (um deles exclusivo nela) com número
aleatório (definindo um máximo) de instâncias
(i.e., objetos), sendo pelo menos 3 instâncias por
tipo.

8. Ter em cada fase um cenário de jogo constituído
por obstáculos, sendo que parte deles devem ser
plataformas ou similares, sobre as quais pode
haver inimigos e podem subir jogadores. Em cada
fase, só poder ter um tipo coincidente de imigo e
um tipo coincidente de obstáculo (que é a plataforma) 
em relação as demais fases.

9. Gerenciar colisões entre jogador para com
inimigos e seus projeteis, bem como entre jogador
para com obstáculos. Ainda, todos eles devem
sofrer o efeito de alguma ´gravidade´ no âmbito
deste jogo de plataforma vertical e 2D.

10. Permitir: (1) salvar nome do usuário, manter/salvar
pontuação (incrementada via neutralização de
inimigos) do jogador controlado pelo usuário e
gerar lista de pontuação (ranking). E (2) Pausar e
Salvar/Recuperar Jogada.

### Compilacao.
---
Para compilar o projeto, siga os seguintes passos:

1. Vá o diretorio /build
```bash
cd build/
```

2. Execute cmake utilizando o arquivo CMakeLists.txt
```bash
cmake ..
```

3. Execute make.
```bash
make
```

Apos isto, sera gerado um executavel. Para executa-la:
```bash
./sfml-app
```

OU EXECUTE TUDO DE UMA VEZ (**ATENCAO AO DIR EM QUE SE ENCONTRA!**)...
```bash
make clean;cd build; cmake ..;make;./sfml-app
```