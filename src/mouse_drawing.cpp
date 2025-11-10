#include "mouse_drawing.h"

MouseDrawing::MouseDrawing()
{
    set_size_request(300, 300);
}

MouseDrawing::~MouseDrawing()
{
}

bool MouseDrawing::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    cr->set_source_rgb(0.0, 0.0, 0.0);

    cr->paint();

    return true;
}
