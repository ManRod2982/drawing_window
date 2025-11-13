#pragma once

#include <gtkmm/drawingarea.h>
#include <vector>

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
            wait
        };

    protected:
        virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
        // Event handlers
        bool on_button_press_event(GdkEventButton* event);
        bool on_button_release_event(GdkEventButton* event);
        bool on_motion_notify_event(GdkEventMotion* event);
    private:
        int drawing_area_w = 250;
        int drawing_area_h = 250;
        double brush_size = 10.0;
        DrawState state = DrawState::clear;
        Cairo::RefPtr<Cairo::Surface> surface;
        struct Point
        {
            double x, y;
        };
        std::vector<Point> points;

};
