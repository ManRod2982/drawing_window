#include "mouse_drawing.h"

MouseDrawing::MouseDrawing()
{
    set_size_request(300, 300);
    this->surface = Cairo::ImageSurface::create(
        Cairo::Format::FORMAT_ARGB32,
        300,
        300
    );
}

MouseDrawing::~MouseDrawing()
{
}

void MouseDrawing::clear_screen()
{
    this->state = DrawState::clear;
    queue_draw();
}

void MouseDrawing::save_screen()
{
    this->state = DrawState::save;
    queue_draw();
}

bool MouseDrawing::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
    auto allocation = this->get_allocation();
    // Restore cairo context
    // each time on_draw is called a fresh context is created
    // this way our surface keeps the history
    cr->save();
    cr->set_source(this->surface, 0.0, 0.0);
    cr->restore();
    cr->paint();

    // Execute action
    switch(this->state)
    {
        case DrawState::clear:
            // Set black background
            cr->set_source_rgb(0.0, 0.0, 0.0);
            cr->paint();
            this->state = DrawState::draw;
            break;

        case DrawState::draw:
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
            break;
        case DrawState::save:
            this->surface->write_to_png("image");
            this->state = DrawState::draw;
            break;
        default:
            break;
    }

    // Save surface
    Cairo::RefPtr<Cairo::Context> t_context = Cairo::Context::create(this->surface);
    t_context->set_source(cr->get_target(), -allocation.get_x(), -allocation.get_y());
    t_context->paint();

    return true;
}
