# Jogo da Velha - Computação Gráfica

Esse jogo foi desenvolvido utilizando OpenGL com C++.

Foi desenvolvido e compliado utilizando Visual Studio Code com a ferramenta CMake.

Para controlar as vez de cada jogador, estou utilizando a varíavel xOuO. A variável foi inciada como X, então sempre começará a jogar quem for o X.
Sempre que o botão for pressionado, esssa variável é alterada para X ou O dependendo de quem foi a jogada anterior.

Para decidir quem venceu, foi criado o método venceu, que avalia através de uma matriz que possuí o valor de cada uma das jogadas todas as combinações que determinam se um dos jogadores venceram. Se foi detectado que um dos jogadores venceu, é avisado na tela. Caso contrário, também é avisado na tela quem é o próximo jogador.

Para avisar os jogares, sobre o término do jogo ou sobre quem deve jogar em cada momento, foi utilizado o componente: ImGui::Text("É a vez do %c", xOuBolinha).

Caso algum jogador queira começar novamente, basta clicar no botão reset. Esse botão invocará a função comecarDeNovo que zerará a matriz e limpará todos os botões.

Para exibir os botões na tela apropriadamente foi utilizado o componente ImGui::Columns(3, nullptr, false) que criará 3 colunas na tela. Ao criar os botões, para cada botão que é criado eu inseri um  ImGui::NextColumn(); para organizar a disposição deles na tela.

Para trocar o texto que vai dentro do botão, o código utilizado foi o código abaixo:

ImGui::Button(std::string(1, nomeBotao[2]).c_str(), ImVec2(150, 150));

O componente ImGui::Button é responsável por criar de fato o botão. O párâmetro inserido na criação std::string(1, nomeBotao[2]).c_str() trata-se de uma matriz que armazena se está com X ou O naquele determinado botão. Já o ImVec2(150, 150) é utilizado para determinar tamanho do botão.

Link da compilção e execução do vídeo: https://youtu.be/2m850gsMUC4
