#include <iostream>
#include <allegro5/allegro_primitives.h>

#include "../includes/allegro.hpp"

#include <stdlib.h>

allegro::allegro(const int x, const int y)
  : display(x, y)
{
  if(!al_init())
    {
      std::cerr << "Impossible d'initialiser Allegro !" << std::endl;
      exit(-1);
    }
  if ((this->window = al_create_display(x * SQUARE_SIZE, y * SQUARE_SIZE))
      == NULL)
    {
      std::cerr << "Impossible d'initialiser une fenêtre !" << std::endl;
      exit(-1);
    }
  if ((this->event_queue = al_create_event_queue()) == NULL)
    {
      std::cerr << "Impossible d'initialiser une queue d'event !" << std::endl;
      exit(-1);
    }
  al_install_keyboard();
  al_init_primitives_addon();
  al_register_event_source(this->event_queue, al_get_keyboard_event_source());
  al_set_window_title(this->window, "Nibbler");
}

allegro::~allegro()
{
  al_destroy_display(this->window);
  al_destroy_event_queue(this->event_queue);
}

void		allegro::refreshScreen(const snakeHead &snake,
				       const nomNom &miam)
{
  std::queue<int> qX;
  std::queue<int> qY;

  qX = snake.getQueueX();
  qY = snake.getQueueY();
  al_clear_to_color(al_map_rgb(0,0,0));
  al_draw_circle(miam.getXPos() * SQUARE_SIZE, miam.getYPos() * SQUARE_SIZE,
		 SQUARE_SIZE / 4, al_map_rgb(0, 255, 0), 5);
  al_draw_circle(snake.getPosX() * SQUARE_SIZE, snake.getPosY() * SQUARE_SIZE,
		 SQUARE_SIZE / 1.5, al_map_rgb(255, 0, 0), 2);
  while (!qX.empty() && !qY.empty())
    {
      al_draw_rectangle(qX.front() * SQUARE_SIZE - SQUARE_SIZE / 2,
			qY.front() * SQUARE_SIZE - SQUARE_SIZE / 2,
			qX.front() * SQUARE_SIZE + SQUARE_SIZE / 2,
			qY.front() * SQUARE_SIZE + SQUARE_SIZE / 2,
			al_map_rgb(255, 0, 255), 0);
      qX.pop();
      qY.pop();
    }
  al_flip_display();
}

gameKeys	allegro::getPressedKey()
{
  ALLEGRO_EVENT	ev;

  if (al_get_next_event(this->event_queue, &ev) == false)
    return (NONE);
  al_flush_event_queue(this->event_queue);
  if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
    {
      if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT)
	return (RIGHT);
      else if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT)
	return (LEFT);
      else if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
	return (ESCAPE);
      else
	return (NONE);
    }
  return (NONE);
}

void		allegro::gameOver(const game &game)
{
  (void)game;
  std::cout << "Game over !" << std::endl;
}
