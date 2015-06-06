/* button board
 *
 * Display a board with pressable buttons for sample playing - cycles through all of them.
 */

#include "buttonBoard.h"


buttonBoard::buttonBoard()
{
    //ctor
}

void buttonBoard::setup()
{
    speed=16.0; // columns per second
    time=0.0; // the time counter - to figure out which column we're in.
    windowResize();

    // empty the status
    for (int i=0; i< BB_COLS; i++ ){
        s[i]=0;
    }
    cnt=0;


}

void buttonBoard::windowResize()
{
    width=ofGetWindowWidth();
    height=ofGetWindowHeight();
    float w=min(width,height);
    cw=int(w/BB_COLS);
    rh=int(w/BB_ROWS);
    mx=(width-64*cw)/2.0; // margins used for centering
    my=(height-64*rh)/2.0;
    border=10.0; // border of the single pusbuttons
    fbo.allocate(cw*64,rh*64,GL_RGBA8); //fbo to draw in.
}
void buttonBoard::update(float dt)
// update the board.
{
    time+=dt;
    int newcol=int(time*speed)%BB_COLS;
    if (column!=newcol) {
            if (newcol==0) { cnt++; };
            nc=true;
            column=newcol;
    }
    else {
        nc=false;
    }
}

bool buttonBoard::buttonActive(int row, int col)
// Check whether a button is active.
{
    int64_t c=s[col];
    return (((c>>row) & 1) == 1);
}

void buttonBoard::draw()
// draw the board...
{
    fbo.begin();
    ofBackground(0,0,0);

    for (int col=0;col<BB_COLS; col++){
        if (col==column) {
            ofSetColor(127,127,255,255);
            ofFill();
            ofRect(col*cw,0,cw,height);
        }
        for (int row=0; row<BB_ROWS;row++){
            if (buttonActive(row,col)){
                if (col==column) {
                        ofSetColor(255,255,255,255);
                }
                else {
                    ofSetColor(255,255,255,170);
                }
            }
            else {
                ofSetColor(64,64,64,255);
            }
            ofFill();
            ofRect(col*cw+border,row*rh+border,cw-(border *2),rh-(border * 2));
        }
    }
    ofSetColor(255,255,255);
    fbo.end();
    fbo.draw(mx,my);


}

void buttonBoard::toggleButton(int row, int col)
// toggle the button in row and column
{
        int64_t i = 1;
        s[col]=s[col] ^ i<<row;
}

void buttonBoard::mousePressed(int x, int y, int button)
{
    int col=(x-mx)/cw;
    int row=(y-my)/rh;
    if (col<BB_COLS && row < BB_ROWS)
    {
      toggleButton(row,col);
    }

}

int64_t buttonBoard::getActiveCol()
// return the active column
{
    return s[column];
}

bool buttonBoard::newCol()
{
    return nc;
}

int buttonBoard::getCount()
{
    return cnt;
}

void buttonBoard::setSample(int64_t ns[BB_COLS])
{
    for(int i=0;i<BB_COLS;i++){
        s[i]=ns[i];
    }
    cnt=0;
}
