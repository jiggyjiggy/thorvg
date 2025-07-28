#include "Example.h"

struct UserExample : tvgexam::Example
{
    tvg::Shape* cursor;

    bool content(tvg::Canvas* canvas, uint32_t w, uint32_t h) override {
        cursor = tvg::Shape::gen();
        cursor->appendCircle(0, 0, 30, 30);
        cursor->fill(255, 0, 0);

        canvas->push(cursor);

        return true;
    }

    bool motion(tvg::Canvas* canvas, int32_t x, int32_t y) override {
        cursor->translate(x, y);
        
        canvas->update();
        return true;
    }
};

int main(int argc, char** argv) 
{
    return tvgexam::main(new UserExample, argc, argv);
}
