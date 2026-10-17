# Criptografia em C

## O que o programa faz

O programa pede:

1. Uma palavra de até 15 letras, sem espaços, acentos ou caracteres especiais.
2. Um valor de `SHIFT` entre 1 e 25.
3. Uma sequência numérica:
   - `1` — Progressão Aritmética (PA): `1, 3, 5, 7, ...`
   - `2` — Progressão Geométrica (PG): `1, 2, 4, 8, ...`
   - `3` — Fibonacci: `1, 1, 2, 3, 5, 8, ...`
   - `4` — Números primos: `2, 3, 5, 7, 11, ...`

Para cada letra, o deslocamento é calculado assim:

```text
deslocamento = SHIFT + valor_da_sequência
```

As letras são convertidas para minúsculas. A posição resultante é calculada módulo 26, de modo que, ao passar de `z`, o alfabeto recomeça em `a`.

## Requisitos

- Um compilador C, como o GCC.
- No Windows, pode-se instalar o GCC pelo [MSYS2](https://www.msys2.org/) usando o ambiente **UCRT64**.

## Compilar e executar no MSYS2 UCRT64

Abra o terminal **MSYS2 UCRT64**, navegue até a pasta do projeto e compile:

```bash
cd /c/Users/abner/OneDrive/Desktop/Faculdade/SABADO
gcc criptografia.c -o criptografia.exe
./criptografia.exe
```

Se o projeto estiver em outra pasta, substitua o caminho do comando `cd` pelo caminho correto.

## Exemplo

Entrada:

```text
Palavra: sigilo
SHIFT: 5
Sequencia (1-PA 2-PG 3-Fibonacci 4-Primos): 3
```

Com Fibonacci, os valores usados para as seis letras são `1, 1, 2, 3, 5, 8`. Assim, os deslocamentos são `6, 6, 7, 8, 10, 13`, e o resultado é:

```text
Palavra criptografada: yonqvb
```

## Arquivos gerados

Os arquivos são criados na pasta de onde o programa é executado:

- `resultado_criptografia.txt` — contém a palavra codificada e os parâmetros usados. É sobrescrito a cada execução.
- `log_execucao.txt` — registra data e hora, parâmetros e o cálculo de cada letra. Novas execuções são acrescentadas ao final.

## Observação

Esta versão realiza a criptografia; ela não oferece uma opção para descriptografar.
