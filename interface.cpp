#include "interface.h"

  void interface_::init_(int LEN_x___, int LEN_y___) {
    LEN_x = LEN_x___;
    LEN_y = LEN_y___;
    int subSizeX = (LEN_x * square_space_x) / 3;
    int subSizeY = (LEN_y * square_space_y) / 3;
    int subPosX = 100 + (LEN_x * square_space_x) / 4;
    int subPosY = 100 + (LEN_y * square_space_y) / 4;
    __i = 0;
    SDL_Init(SDL_INIT_VIDEO);  // init video
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    window = SDL_CreateWindow("MONKEY IA", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, LEN_x * square_space_x,
                              LEN_y * square_space_y, 0);

    renderer = SDL_CreateRenderer(window, -1, 0);
    m_window = SDL_CreateWindow("IA DADOS", subPosX, subPosY, 400, 300, 0);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 153, 204, 50, 0);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);

    screen = SDL_GetWindowSurface(window);
    DestR.x = 1;
    DestR.y = 1;
    DestR.w = LEN_x * square_space_x;
    DestR.h = LEN_y * square_space_y;

    SDL_RenderClear(renderer);
    SDL_RenderClear(m_renderer);

    texture = IMG_LoadTexture(renderer, "resource\\p_.png");
    SDL_RenderCopy(renderer, texture, NULL, &DestR);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000 * 3);
    clean___();
    SDL_RenderPresent(m_renderer);
  }
  
   void interface_::___print(std::string str) {
    SDL_Color black_ = {255, 255, 255};
    TTF_Font *___font = TTF_OpenFont("resource\\font.ttf", 14);
    if (___font == NULL) {
      printf("Dont't have font\n");
      printf("TTF_OpenFont: %s\n", TTF_GetError());
      system("pause");
      system("exit");
    }
    surfaceMessage = TTF_RenderText_Solid(___font, str.c_str(), black_);
    Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect; 

    Message_rect.x = 0;
    Message_rect.y = __i * 20;
    Message_rect.w = surfaceMessage->w;
    Message_rect.h = surfaceMessage->h;
    SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);
    SDL_RenderPresent(m_renderer);
    __i = __i + 1;
  }

 void interface_::___print_square(pos pos_, std::string str) {
    SDL_Color black_ = {255, 255, 255};
    SDL_Rect Message_rect;
    
    TTF_Font *___font = TTF_OpenFont("resource\\font.ttf", 8);
    if (___font == NULL) {
      printf("Dont't have font\n");
      printf("TTF_OpenFont: %s\n", TTF_GetError());
      system("pause");
      system("exit");
    }
    
    Message_rect.x = pos_.x;
    Message_rect.y = pos_.y;

    surfaceMessage_ = TTF_RenderText_Solid(___font, str.c_str(), black_);
    
    Message_ = SDL_CreateTextureFromSurface(renderer, surfaceMessage_);
    Message_rect.w = 20;
    Message_rect.h = 20;
    
    SDL_RenderCopy(renderer, Message_, NULL, &Message_rect);
    SDL_RenderPresent(renderer);
  }

  void interface_::___print__floor(int i, pos pos_) {
    int c = 0, b = 0, z = 0;
    DestR.x = pos_.x * square_space_x;
    DestR.y = pos_.y * square_space_y;

    if (i==1) {
      c = 181;
      b = 60;
      z = 255;
    } else if (i==0) {
      c = 233;
      b = 14;
      z = 255;
    }
      else if (i==2) {
    c = 255;
    b = 6;
    z = 8;	
   }

    SDL_SetRenderDrawColor(renderer, c, b, z, 255);
    SDL_RenderFillRect(renderer, &DestR);

    SDL_RenderPresent(renderer);
  }

  void interface_::close___() {
    SDL_DestroyWindow(window);
    SDL_DestroyWindow(m_window);
  }

  void interface_::wait_and_continue() {
    x__ = true;

    for (int i = 0; i <= (LEN_y - 1); i++) {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
      SDL_RenderDrawLine(renderer, 0, (i * square_space_y),
                         LEN_x * square_space_x, (i * square_space_y));
    }
    for (int i = 0; i <= (LEN_x - 1); i++) {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
      SDL_RenderDrawLine(renderer, (i * square_space_x), 0,
                         (i * square_space_x), LEN_y * square_space_y);
    }

    SDL_RenderPresent(renderer);
    while (x__) {
      SDL_WaitEvent(&evt);
      SDL_PollEvent(&evt);
      if (evt.type == SDL_KEYUP || evt.type == SDLK_RIGHT) {
        x__ = false;
      }
    }

    clean___();
  }

  void interface_::__image(int p_, pos pos_, int number) {
    int c = 0, b = 0, z = 255;
    char sd[100] = "resource\\";
    char buffer[100];
    DestR.x = pos_.x * square_space_x;
    DestR.y = pos_.y * square_space_y;
    DestR.w = square_space_x;
    DestR.h = square_space_y;
    pos pos__;
    pos__.x = DestR.x;
    pos__.y = DestR.y;
    if (p_ == 0) {
      c = 255;
      b = 255;
      z = 0;
    } else if (p_ == 1) {
      c = 255;
      b = 0;
      z = 0;
    } else if (p_ == 2) {
      c = 35;
      b = 94;
      z = 33;
    }

    SDL_SetRenderDrawColor(renderer, c, b, z, 255);
    SDL_RenderFillRect(renderer, &DestR);

    strcat(sd,
            (p_ == 0) ? "tigre" : (p_ == 1) ? "aguia" : (p_ == 2) ? "cobra" : (p_ == 4) ? "monkey_king" : "monkey");
   
    strcat(sd, ".png");
   
    texture = IMG_LoadTexture(renderer, sd);

    SDL_RenderCopy(renderer, texture, NULL, &DestR);

    SDL_RenderPresent(renderer);
    sprintf(buffer, "%d", number);
   ___print_square(pos__, std::string(buffer));
  }

  void interface_::clean___() {
    SDL_DestroyTexture(Message);
    SDL_DestroyRenderer(renderer);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 153, 204, 50, 255);

    SDL_RenderClear(renderer);
    screen = SDL_GetWindowSurface(window);

    SDL_RenderPresent(renderer);
    __i = 0;
  }

  void interface_::clean_m() {
    SDL_DestroyTexture(Message);
    SDL_DestroyRenderer(m_renderer);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(renderer);
  }
  
