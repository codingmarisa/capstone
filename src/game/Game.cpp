/* ..............................................
  @file Game.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "Game.h"

/* ..............................................SS
  @brief Construct a new Game:: Game object
  
.............................................. */
Game::Game()
{
  /* initialize ncurses */
  initscr();
  keypad(stdscr, TRUE);
  cbreak();
  noecho();

  /* initialize colors */
  start_color();
  init_pair(GRASS_PAIR, COLOR_YELLOW, COLOR_GREEN);
  init_pair(WATER_PAIR, COLOR_CYAN, COLOR_BLUE);
  init_pair(MOUNTAIN_PAIR, COLOR_BLACK, COLOR_WHITE);
  init_pair(PLAYER_PAIR, COLOR_RED, COLOR_MAGENTA);

  clear();

  /* initialize the game map */
  draw_map();
  this->player.setX(LINES-1);
  this->player.setY(0);
}

/* ..............................................
  @brief Destroy the Game:: Game object
  
.............................................. */
Game::~Game()
{
  /* Destroy ncurses */
  endwin();

  /* Destroy player */
  player.~Player();
}

/* ..............................................
  @brief 
  
.............................................. */
void Game::process()
{
  /* by default, you get a blinking cursor - use it to
      indicate player * */
  attron(COLOR_PAIR(PLAYER_PAIR));
  mvaddch(player.getY(), player.getX(), PLAYER);
  attroff(COLOR_PAIR(PLAYER_PAIR));
  move(player.getY(), player.getX());
  refresh();

  this->ch = getch();
}

/* ..............................................
  @brief 
  
.............................................. */
void Game::update()
{
  switch (this->ch) {
    case KEY_UP:
    case 'w':
    case 'W':
        if ((player.getY() > 0) && is_move_okay(player.getY() - 1, player.getX())) {
            attron(COLOR_PAIR(EMPTY_PAIR));
            mvaddch(player.getY(), player.getX(), EMPTY);
            attroff(COLOR_PAIR(EMPTY_PAIR));
            player.setY(player.getY() - 1);
        }
        break;
    case KEY_DOWN:
    case 's':
    case 'S':
        if ((player.getY() < LINES - 1) && is_move_okay(player.getY() + 1, player.getX())) {
            attron(COLOR_PAIR(EMPTY_PAIR));
            mvaddch(player.getY(), player.getX(), EMPTY);
            attroff(COLOR_PAIR(EMPTY_PAIR));
            player.setY(player.getY() + 1);
        }
        break;
    case KEY_LEFT:
    case 'a':
    case 'A':
        if ((player.getX() > 0) && is_move_okay(player.getY(), player.getX() - 1)) {
            attron(COLOR_PAIR(EMPTY_PAIR));
            mvaddch(player.getY(), player.getX(), EMPTY);
            attroff(COLOR_PAIR(EMPTY_PAIR));
            player.setX(player.getX() - 1);
        }
        break;
    case KEY_RIGHT:
    case 'd':
    case 'D':
        if ((player.getX() < COLS - 1) && is_move_okay(player.getY(), player.getX() + 1)) {
            attron(COLOR_PAIR(EMPTY_PAIR));
            mvaddch(player.getY(), player.getX(), EMPTY);
            attroff(COLOR_PAIR(EMPTY_PAIR));
            player.setX(player.getX() + 1);
        }
        break;
    case 'q':
    case 'Q':
        setIsComplete(true);
        break;
    }
}

/* ..............................................
  @brief 
  
.............................................. */
void Game::render()
{

}

/* ..............................................
  @brief  runs the game while the game is not
          complete
.............................................. */
void Game::run()
{
  do {
      process();  // process player input
      update();   // update the game state
    }
    while (getIsComplete() != true);
}

/* ..............................................
  @brief 
  
  @param isComplete 
.............................................. */
void Game::setIsComplete(bool isComplete)
{
  this->isComplete = isComplete;
}

/* ..............................................
  @brief 
  
  @return true 
  @return false 
.............................................. */
bool Game::getIsComplete()
{
  return this->isComplete;
}

/* ..............................................
  @brief 
  
  @return char 
.............................................. */
char Game::getCh() {
  return this->ch;
}

/* ..............................................
  @brief 
  
  @param y 
  @param x 
  @return int 
.............................................. */
int Game::is_move_okay(int y, int x)
{
  int testch;

  /* return true if the space is okay to move into */

  testch = mvinch(y, x);
  return (((testch & A_CHARTEXT) == GRASS)
          || ((testch & A_CHARTEXT) == EMPTY));
}

/* ..............................................
  @brief 
  
.............................................. */
void Game::draw_map()
{
    int y, x;

    /* draw the quest map */

    /* background */
    attron(COLOR_PAIR(GRASS_PAIR));
    for (y = 0; y < LINES; y++) {
        mvhline(y, 0, GRASS, COLS);
    }
    attroff(COLOR_PAIR(GRASS_PAIR));
}