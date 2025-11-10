#pragma once

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/grid.h>
#include "mouse_drawing.h"

class Window : public Gtk::Window
{
public:
  Window();
  virtual ~Window();

protected:
  //Signal handlers:
  void on_clear_clicked();
  void on_predict_clicked();

  //Child widgets:
  Gtk::Grid my_grid;
  MouseDrawing mouse_drawing;
  Gtk::Button clear_button, predict_button;
};
