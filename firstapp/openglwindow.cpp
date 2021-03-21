#include "openglwindow.hpp"

#include <fmt/core.h>
#include <imgui.h>

#include <iostream>
using namespace std;
#include <string>

// 0 = O e 1 igual a X
char xOuO = 'X';
static bool fimDeJogo = false;

void MudaJogador() {
  if (xOuO == 'X') {
    xOuO = 'O';
  } else {
    xOuO = 'X';
  }
}

bool venceu(char xOuBolinha, char matriz[]) {
  if (((matriz[0] == xOuBolinha && matriz[1] == xOuBolinha) &&
       matriz[2] == xOuBolinha) ||
      ((matriz[0] == xOuBolinha && matriz[4] == xOuBolinha) &&
       matriz[8] == xOuBolinha) ||
      ((matriz[3] == xOuBolinha && matriz[4] == xOuBolinha) &&
       matriz[5] == xOuBolinha) ||
      ((matriz[6] == xOuBolinha && matriz[7] == xOuBolinha) &&
       matriz[8] == xOuBolinha) ||
      ((matriz[2] == xOuBolinha && matriz[4] == xOuBolinha) &&
       matriz[6] == xOuBolinha) ||
      ((matriz[0] == xOuBolinha && matriz[3] == xOuBolinha) &&
       matriz[6] == xOuBolinha) ||
      ((matriz[1] == xOuBolinha && matriz[4] == xOuBolinha) &&
       matriz[7] == xOuBolinha) ||
      ((matriz[2] == xOuBolinha && matriz[6] == xOuBolinha) &&
       matriz[8] == xOuBolinha)) {
    fimDeJogo = true;

    return true;

  } else {
    ImGui::Text("É a vez do %c ", xOuBolinha);
    return false;
  }
}

bool comecarDeNovo(char board[]) {
  for (int j = 0; j < 9; j++) {
    board[j] = ' ';
  }
  return false;
}

void OpenGLWindow::initializeGL() {}

void OpenGLWindow::paintGL() {
  // Set the clear color
  glClearColor(m_clearColor[0], m_clearColor[1], m_clearColor[2],
               m_clearColor[3]);
  // Clear the color buffer
  glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLWindow::paintUI() {
  // Parent class will show fullscreen button and FPS meter
  abcg::OpenGLWindow::paintUI();
  // Our own ImGui widgets go below
  {
    ImGui::SetNextWindowSize(ImVec2(600, 600));

    // Window begin
    ImGui::Begin("Tic-Tac-Toe");

    static char nomeBotao[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    ImGui::AlignTextToFramePadding();

    if (fimDeJogo) {
      ImGui::Text("Fim de jogo");
      if (xOuO == 'O') {
        ImGui::Text("X venceu!");
      } else {
        ImGui::Text("O venceu!");
      }
    } else {
      ImGui::Text("É a vez do %c", xOuO);
    }

    ImGui::Columns(3, nullptr, false);

    ImGui::Button(std::string(1, nomeBotao[0]).c_str(), ImVec2(150, 150));

    if (ImGui::IsItemClicked() && fimDeJogo != true) {
      nomeBotao[0] = xOuO;
      fimDeJogo = venceu(xOuO, nomeBotao);
      MudaJogador();
    }

    ImGui::NextColumn();

    ImGui::Button(std::string(1, nomeBotao[1]).c_str(), ImVec2(150, 150));

    if (ImGui::IsItemClicked() && fimDeJogo != true) {
      nomeBotao[1] = xOuO;
      fimDeJogo = venceu(xOuO, nomeBotao);
      MudaJogador();
    }

    ImGui::NextColumn();

    ImGui::Button(std::string(1, nomeBotao[2]).c_str(), ImVec2(150, 150));

    if (ImGui::IsItemClicked() && fimDeJogo != true) {
      nomeBotao[2] = xOuO;
      fimDeJogo = venceu(xOuO, nomeBotao);
      MudaJogador();
    }

    ImGui::NextColumn();

    ImGui::Button(std::string(1, nomeBotao[3]).c_str(), ImVec2(150, 150));

    if (ImGui::IsItemClicked() && fimDeJogo != true) {
      nomeBotao[3] = xOuO;
      fimDeJogo = venceu(xOuO, nomeBotao);
      MudaJogador();
    }

    ImGui::NextColumn();

    ImGui::Button(std::string(1, nomeBotao[4]).c_str(), ImVec2(150, 150));

    if (ImGui::IsItemClicked() && fimDeJogo != true) {
      nomeBotao[4] = xOuO;
      fimDeJogo = venceu(xOuO, nomeBotao);
      MudaJogador();
    }

    ImGui::NextColumn();

    ImGui::Button(std::string(1, nomeBotao[5]).c_str(), ImVec2(150, 150));

    if (ImGui::IsItemClicked() && fimDeJogo != true) {
      nomeBotao[5] = xOuO;
      fimDeJogo = venceu(xOuO, nomeBotao);
      MudaJogador();
    }

    ImGui::NextColumn();

    ImGui::Button(std::string(1, nomeBotao[6]).c_str(), ImVec2(150, 150));

    if (ImGui::IsItemClicked() && fimDeJogo != true) {
      nomeBotao[6] = xOuO;
      fimDeJogo = venceu(xOuO, nomeBotao);
      MudaJogador();
    }

    ImGui::NextColumn();

    ImGui::Button(std::string(1, nomeBotao[7]).c_str(), ImVec2(150, 150));

    if (ImGui::IsItemClicked() && fimDeJogo != true) {
      nomeBotao[7] = xOuO;
      fimDeJogo = venceu(xOuO, nomeBotao);
      MudaJogador();
    }

    ImGui::NextColumn();

    ImGui::Button(std::string(1, nomeBotao[8]).c_str(), ImVec2(150, 150));

    if (ImGui::IsItemClicked() && fimDeJogo != true) {
      nomeBotao[8] = xOuO;
      fimDeJogo = venceu(xOuO, nomeBotao);
      MudaJogador();
    }

    ImGui::NextColumn();

    if (ImGui::Button("Reset Game", ImVec2(50, 50))) {
      comecarDeNovo(nomeBotao);
      fimDeJogo = false;
    }

    ImGui::End();
  }
}
