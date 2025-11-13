#pragma once

#include <gtkmm/drawingarea.h>

class MouseDrawing : public Gtk::DrawingArea
{
    public:
        MouseDrawing();
        void clear_screen(void);
        void save_screen(void);
        virtual ~MouseDrawing();
        enum class DrawState
        {
            clear,
            draw,
            save
        };

    protected:
        virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

    private:
        DrawState state = DrawState::draw;
        Cairo::RefPtr<Cairo::Surface> surface;

};
