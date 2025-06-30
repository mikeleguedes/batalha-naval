# 🛡️ Jogo de Batalha Naval com Habilidades Especiais — Projeto em C

## 📌 Descrição

Este projeto implementa um jogo de **batalha naval simplificado**, com foco em habilidades especiais que afetam múltiplas células do tabuleiro. Três tipos de áreas de efeito são modeladas: **Cone**, **Cruz** e **Octaedro**.

Desenvolvido inteiramente em C, o jogo demonstra o uso de estruturas de repetição aninhadas, condicionais e manipulação de matrizes para simular ataques em área num tabuleiro 10x10.

---

## 🎯 Funcionalidades

- ✅ Tabuleiro 10x10 inicializado com água
- ✅ Posição fixa de navios (valor `3`)
- ✅ Geração de três tipos de matriz de habilidade (cone, cruz, octaedro)
- ✅ Sobreposição da habilidade no tabuleiro, com marcação (`5`)
- ✅ Visualização clara em terminal

---

## 🧠 Habilidades Especiais

### 🔺 Cone

Área triangular expandida para baixo, com origem no topo da matriz.

```
0 0 1 0 0
0 1 1 1 0
1 1 1 1 1
```

### ✝️ Cruz

Afeta linha e coluna centrais.

```
0 0 1 0 0
1 1 1 1 1
0 0 1 0 0
```

### 🔷 Octaedro

Simula uma forma losangular (vista frontal de um octaedro).

```
0 0 1 0 0
0 1 1 1 0
1 1 1 1 1
0 1 1 1 0
0 0 1 0 0
```

---

## 📐 Estrutura do Projeto

```
batalha_naval/
├── main.c         // Código-fonte do jogo
└── README.md      // Documentação do projeto
```

---

## 🛠️ Como compilar e rodar

### Compilar
```bash
gcc main.c -o batalha
```

### Executar
```bash
./batalha
```

---

## 💻 Exemplo de Saída

```
~ ~ ~ ~ ~ ~ ~ ~ ~ ~
~ ~ ~ * ~ ~ ~ ~ ~ ~
~ ~ N * * ~ ~ ~ ~ ~
~ * * * * * ~ ~ ~ ~
~ ~ ~ * N * ~ ~ ~ ~
~ ~ ~ * * * * * * ~
~ ~ ~ ~ ~ * N * ~ ~
~ ~ ~ ~ ~ ~ * * * ~
~ ~ ~ ~ ~ ~ ~ * ~ ~
~ ~ ~ ~ ~ ~ ~ ~ ~ ~
```

Legenda: `~` Água | `N` Navio | `*` Área Afetada
