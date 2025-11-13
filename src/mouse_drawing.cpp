#include "mouse_drawing.h"
#include <gdk/gdkkeysyms.h>
#include <iostream>

MouseDrawing::MouseDrawing()
{
    set_size_request(drawing_area_w, drawing_area_h);
    this->surface = Cairo::ImageSurface::create(
        Cairo::Format::FORMAT_ARGB32,
        drawing_area_w,
        drawing_area_h
    );

    // Enable the events you wish to receive
    add_events(Gdk::BUTTON_PRESS_MASK | Gdk::BUTTON_RELEASE_MASK | Gdk::POINTER_MOTION_MASK);
}

MouseDrawing::~MouseDrawing()
{
}

void MouseDrawing::clear_screen()
{
    this->state = DrawState::clear;
    points.clear();
    queue_draw();
}

void MouseDrawing::save_screen()
{
    this->surface->write_to_png("image");
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
            this->state = DrawState::wait;
            break;

        case DrawState::draw:
            // Draw a white circle
            cr->save();
            cr->set_line_width(0);
            cr->set_source_rgb(1.0, 1.0, 1.0);
            // Draw circles where the mouse has moved
            for(const auto& point:points)
            {
                cr->arc(point.x, point.y, brush_size, 0, 2*M_PI);
                cr->fill();
            }
            cr->restore();
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

bool MouseDrawing::on_button_press_event(GdkEventButton* event) {
    if (event->button == 1) { // Left mouse button
        this->state = DrawState::draw;
        points.push_back({event->x, event->y});
        std::cout << event->x << " " <<event->y << std::endl;
        return true; // Event handled
    }
    return false;
}

bool MouseDrawing::on_button_release_event(GdkEventButton* event) {
    if (event->button == 1) {
        this->state = DrawState::wait;
        return true; // Event handled
    }
    return false;
}

bool MouseDrawing::on_motion_notify_event(GdkEventMotion* event) {
    if (this->state == DrawState::draw) {
        points.push_back({event->x, event->y});
        queue_draw(); // Request a redraw
        std::cout << event->x << " " << event->y << std::endl;
        return true; // Event handled
    }
    return false;
}