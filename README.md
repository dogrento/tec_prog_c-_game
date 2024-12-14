# tec_prog_c++_game
Repositorio referente ao projeto proposto pela Disciplina Tecnicas de Programacao da UTFPR.

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