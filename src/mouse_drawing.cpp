#include "mouse_drawing.h"

MouseDrawing::MouseDrawing()
{
    set_size_request(300, 300);
}

MouseDrawing::~MouseDrawing()
{
}

void MouseDrawing::clear_screen()
{
    this->clear = true;
    queue_draw();
}

bool MouseDrawing::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    // Clear screen
    if(this->clear)
    {
        // Set black background
        cr->set_source_rgb(0.0, 0.0, 0.0);
        cr->paint();
        this->clear = false;

        return true;
    }

    // Set black background
    cr->set_source_rgb(0.0, 0.0, 0.0);
    cr->paint();

    // Draw a white circle
    cr->save();
    cr->set_line_width(0);
    cr->set_source_rgb(1.0, 1.0, 1.0);
    cr->arc(150, 150, 10.0, 0, 2*M_PI);
    cr->fill();
    cr->restore();

    return true;
}
