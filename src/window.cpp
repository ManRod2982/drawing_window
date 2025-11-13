#include "window.h"
#include <iostream>

Window::Window() :
    clear_button("Clear"),
    predict_button("Predict")
{
  set_title("Window");
  set_border_width(10);
  add(my_grid);
  my_grid.set_column_homogeneous(true);

  my_grid.attach(mouse_drawing, 0, 0, 2, 1);

  clear_button.signal_clicked().connect( sigc::mem_fun(*this,
              &Window::on_clear_clicked) );

  my_grid.attach_next_to(clear_button, mouse_drawing, Gtk::POS_BOTTOM, 1, 1);

  predict_button.signal_clicked().connect( sigc::mem_fun(*this,
              &Window::on_predict_clicked) );

  my_grid.attach_next_to(predict_button, clear_button, Gtk::POS_RIGHT, 1, 1);


  show_all_children();
}

Window::~Window()
{
}

void Window::on_clear_clicked()
{
    // Clear screen
    mouse_drawing.clear_screen();
    std::cout << "Clear clicked!" << std::endl;
}

void Window::on_predict_clicked()
{
    // Save screen to file
    // TODO call NN on file and determine the digit
    std::cout << "Predict clicked!" << std::endl;
    mouse_drawing.save_screen();
}
