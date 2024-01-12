# MangaReader



1. Biblioteca

![tela da biblioteca](/res/images/library.png)

  O programa inicia sempre pela biblioteca do usuário. Nela é possível visualizar e navegar por todos os mangas
disponíveis, também é possível favoritar um manga para que ele apareça primeiro que os outros no catálogo.

1.1 Navegação

    Utilize as teclas de direção para percorrer o catálogo.
    A tecla Enter é utilizada para escolher um mangá para leitura.
    A tecla 'F' favorita ou desfavorita um mangá no catálogo.

1.2 Adição de Capas

    Adicione imagens de capa colocando-as em uma pasta específica no seu computador.
    Configure a variável MANGA_COVER_DIR dentro de constants.hpp com o nome da pasta escolhida.
    O nome da imagem de capa do manga deve ser exatamente o mesmo que o nome do manga.

1.3 Adição de Mangás

    Configure a variável MANGA_DIR dentro de constants.hpp com o caminho da pasta onde os mangás estão localizados.

2. Tela de leitura

![tela de leitura](/res/images/reader.png)

Na tela de leitura será possível ler o manga escolhido, o programa lembra do ultimo capitulo lido de cada 
manga.

    Utilize as teclas de direção <- e -> para alternar entre os capitulos.
    Utilize as teclas de direção (cima) e (baixo) para mover as páginas.
    A tecla Escape retorna à biblioteca.


# Requisitos
- Linux
-  [SFML](https://www.sfml-dev.org/tutorials/2.6/start-linux.php)
-  g++

# Compilação e Execução

>
    