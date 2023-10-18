Trabalho para disciplina de Sistemas Operacionais I - INE5412
---

## Compilação do executável
    make all

## Compilação e execução do programa
    make run

## Limpa arquivos gerados pela compilação
    make clean

## Utilização do Valgrind
    valgrind --leak-check=full \         
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./bin/main