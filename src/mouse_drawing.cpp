#include "mouse_drawing.h"

MouseDrawing::MouseDrawing()
{
    set_size_request(200, 200);
}

MouseDrawing::~MouseDrawing()
{
}

bool MouseDrawing::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    cr->set_source_rgb(1.0, 1.0, 1.0);

    return true;
}
