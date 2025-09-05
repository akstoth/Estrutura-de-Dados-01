# Guia de Desenvolvimento - Estrutura de Dados I

Este arquivo documenta as convenções e padrões adotados neste repositório para garantir a qualidade e a consistência do código e do histórico de versões.

## 1. Padrões e Convenções

### 1.1. Glossário de Commits (Conventional Commits)

Para manter o histórico do projeto organizado, este repositório seguirá o padrão [Conventional Commits](https://www.conventionalcommits.org/pt-br/v1.0.0/). Abaixo estão indicados os tipos mais comuns a serem utilizados.

**Estrutura:** `<tipo>(<escopo>): <descrição>`

| Tipo         | Descrição                                                                                                      |
| :----------- | :------------------------------------------------------------------------------------------------------------- |
| **feat**     | Adiciona uma nova funcionalidade ou um novo recurso (ex: implementação de uma nova função no exercício).       |
| **fix**      | Corrige um bug ou um erro no código.                                                                           |
| **docs**     | Altera apenas a documentação (como o `README.md`, comentários no código).                                      |
| **style**    | Altera apenas a formatação do código (identação, espaços), sem mudar a lógica.                                 |
| **refactor** | Altera o código, mas sem corrigir bugs ou adicionar funcionalidades (melhora a estrutura, remove redundância). |
| **chore**    | Atualiza tarefas de manutenção e configurações (ex: ajustes no `.gitignore`, `tasks.json`).                    |

### 1.2. Padrão de Comentários (Doxygen)

Para garantir que o código seja autoexplicativo, adotamos um subconjunto do padrão **Doxygen** para comentar arquivos e funções em C.

#### Cabeçalho de Arquivos

Todo arquivo `.c` deve começar com o seguinte bloco de documentação:

```c
/**
 * @file [Nome do Arquivo.c]
 * @author Aleksander Da Silva Toth
 * @brief Descrição curta (uma linha) do propósito do arquivo.
 * @version 1.0
 * @date [Data de criação ou última modificação, ex: 2025-09-05]
 *
 * @copyright Copyright (c) 2025
 *
 * ===============================================================================
 * @details
 * Descrição mais longa e detalhada do que o arquivo faz, suas
 * principais funcionalidades e os algoritmos implementados.
 * ===============================================================================
 */
```
