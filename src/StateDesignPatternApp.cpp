#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "SimpleObject.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class StateDesignPatternApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Device mDevice;
    
};

void StateDesignPatternApp::setup()
{
}

void StateDesignPatternApp::mouseDown( MouseEvent event )
{
    if( event.getX() < getWindowWidth()/2 ) mDevice.somethingHappend();
    if( event.getX() > getWindowWidth()/2 ) mDevice.somethingElseHappend();
}

void StateDesignPatternApp::update()
{
    
    mDevice.printState();
    
    getWindow()->setTitle("click on either side of the screen to change mDevice state");
}

void StateDesignPatternApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( StateDesignPatternApp, RendererGl )
