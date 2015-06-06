#include "Slider.h"
// A Slider!

Slider::Slider()
{
    //ctor
}

void Slider::setup(ofPoint* pos)
{
    fbo.allocate(SLIDER_WIDTH+2,SLIDER_HEIGHT + SLIDER_THING+2,GL_RGBA8);
    position=*pos;
    px=0;
    py=0;
}

void Slider::draw()
{
 fbo.begin();
 ofBackground(0,0,0);
 ofSetColor(255,255,255,170);
 ofNoFill();
 ofRect(1,1,SLIDER_WIDTH-1,SLIDER_THING + SLIDER_HEIGHT-2);
 ofFill();
 float y=ofMap(value,0,1,SLIDER_HEIGHT,0);
 ofSetColor(127,127,255,255);
 ofRect(0,y + SLIDER_THING,SLIDER_WIDTH,SLIDER_HEIGHT - y);
 ofRect(0,y,SLIDER_WIDTH,SLIDER_THING);
 fbo.end();
 ofSetColor(255,255,255);
 fbo.draw(position);
}

void Slider::mousePressed(int x, int y, int button)
{
   px= x;
   py= y-position.y;
}
void Slider::mouseDragged(int x, int y, int button)
{
    if (px == 0 ) {
            px = x;
            py = y-position.y;
    }
    else {
        if (button ==0 )
        {
            y=y-position.y;
            if ((x > position.x) & (x < position.x + SLIDER_WIDTH) & (y > 0) & (y < SLIDER_HEIGHT + SLIDER_THING)) {
                int dy=py-y;
                value+=ofMap(dy,0,SLIDER_HEIGHT,0,1);
            }
            if (value < 0 ) {
                    value = 0;
            }
            if (value > 1) {
                value = 1;
            }
            py=y;


        }
    }
}

float Slider::getValue()
{
    return value;
}

void Slider::setValue(float v)
{
    value=v;
}
