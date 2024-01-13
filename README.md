# Manga Reader

Estre programa teve como objetivo me ajudar no aprendizado em C++ e proporcionar uma experiência de leitura dos meus mangas de forma simples e leve. 

Com ele consegui desenvolver
meus conhecimentos nas seguintes areas

- Funcionamento e uso da biblioteca SFML
- Técnicas de gerenciamento de memória como unique_ptr e shared_ptr e boas práticas da programação em C++ em geral
- Uso correto e melhor entendimento de referências, ponteiros e cópias de variáveis
- Orientação a Objetos com as classes [Scene](include/scene/scene.hpp) e [Component](include/component/component.hpp) que facilitaram a criação de diferentes telas para a aplicação assim como a criação e reutilização de componentes (widgets) para as telas
- Computação concorrente na utilização de [threads](src/component/chapter.cpp) e [mutex](src/util/texture_pool.cpp) que serviram para acelerar o carregamento das imagens de cada capitulo
- Organização e disposição das pastas e arquivos de um pequeno projeto assim como a utilização de um arquivo Makefile para o processo de compilação


# Funcionamento

## Biblioteca

![tela da biblioteca](/res/images/library.png)

  O programa inicia sempre pela biblioteca do usuário. Nela é possível visualizar e navegar por todos os mangas
disponíveis, também é possível favoritar um manga para que ele apareça primeiro que os outros no catálogo.

###  Navegação

> Utilize as teclas de direção para percorrer o catálogo.

> A tecla Enter é utilizada para escolher um mangá para leitura.

> A tecla 'F' favorita ou desfavorita um mangá no catálogo.

### Mangas e imagens de capa

####  Adição de Capas

>Adicione imagens de capa colocando-as na pasta /mangas/capa.
O nome da imagem de capa do manga deve ser exatamente o mesmo que o nome do manga.

####  Adição de Mangás

> Adicone mangas colocando-os na pasta /mangas/manga

## Tela de leitura

![tela de leitura](/res/images/reader.png)

Na tela de leitura será possível ler o manga escolhido, o programa lembra do ultimo capitulo lido de cada 
manga.

>Utilize as teclas de direção <- e -> para alternar entre os capitulos.

>Utilize as teclas de direção (cima) e (baixo) para mover as páginas.

>A tecla Escape retorna à biblioteca.

# Requisitos

- Linux
- [SFML](https://www.sfml-dev.org/tutorials/2.6/start-linux.php)
- g++

# Compilação


    make

# Execução

    ./build/apps/manga_reader.out
  

# Exemplo de utilizaçao

Dentro da pasta [mangas](mangas) crie as seguintes pastas

![](res/images/pastas.png)

Na pasta **capa** coloque as imagens de capa

![](res/images/capas.png)

Na pasta manga coloque os mangas

![](res/images/mangas.png)

O nome em cada imagem na pasta **capa** deve ser exatamente o mesmo
que o nome na pasta correspondente de seu manga

Dentro de cada pasta de cada manga estão uma pasta
para cada capitulo, é importante que **cada capitulo tenha um número associado** para seja possível ler o manga em ordem.

Exemplo: Dentro da pasta de Attack on Titan existe uma pasta para cada capitulo e cada pasta tem o número do capitulo em seu nome

![](res/images/capitulos.png)

Dentro de cada pasta de cada capitulo as imagens devem estar enumeradas em uma ordem que reflita a ordem de leitura das imagens

![](res/images/imagens.png)


# ThreadPool

O projeto de [Barak Shoshany](https://github.com/bshoshany) que implementa uma [ThreadPool](https://github.com/bshoshany/thread-pool) em C++ foi usado neste programa