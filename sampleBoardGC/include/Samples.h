#ifndef SAMPLES_H
#define SAMPLES_H
#include "ofMain.h"

class Samples
{
    public:
        Samples();
        void setup();
        void load();
        void update();
        void play(int64_t d);
    protected:
    private:
        ofSoundPlayer sample[64];
};

#endif // SAMPLES_H
