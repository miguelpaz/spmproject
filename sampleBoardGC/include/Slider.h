#ifndef SLIDER_H
#define SLIDER_H
#include "ofMain.h"

#define SLIDER_HEIGHT 400
#define SLIDER_WIDTH  50
#define SLIDER_THING 10


class Slider
{
    public:
        Slider();
        void setup(ofPoint* pos);
        void draw();
        void mousePressed(int x, int y, int button);
        void mouseDragged(int x,int y, int button);
        float getValue();
        void setValue(float v);
    protected:
    private:
        float value;
        ofFbo fbo;
        ofPoint position;
        int px;
        int py;
};

#endif // SLIDER_H
