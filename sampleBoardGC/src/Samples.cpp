#include "Samples.h"

Samples::Samples()
{

}

void Samples::setup()
{
    load();
    ofSoundSetVolume(0.2);
}

void Samples::load() {
    ofBuffer f=ofBufferFromFile("samples.txt",false);
    for (int i=0;i<64;i++){
        string filename=f.getNextLine();
        sample[i].loadSound(filename);
        if (f.isLastLine()) {
            f.resetLineReader();
        }
    }

}
void Samples::update()
{
    ofSoundUpdate();
}

void Samples::play(int64_t d)
{
    for(int i=0; i<64; i++)
    if (((d>>i) & 1) == 1) {
        sample[i].play();
        sample[i].setVolume(0.5);
    }
}
