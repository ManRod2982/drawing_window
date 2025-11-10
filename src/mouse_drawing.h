#pragma once

#include <gtkmm/drawingarea.h>

class MouseDrawing : public Gtk::DrawingArea
{
    public:
        MouseDrawing();
        virtual ~MouseDrawing();

    protected:
        virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

};
