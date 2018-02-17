
#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOsc.h"
#include "ofxRPiezoParams.h"
#include "ofxRPiezosConstants.h"
#include "ofxOscParameterSync.h"
#include "ofxXmlSettings.h"


struct PiezoGraphicsData {
    
    int raw;
    float trigger;
    int triggerCounter;
    float envelope;
    
    vector<int> rawPlot;
    int rawPlotIndex;
    vector<float> envPlot;
    int envPlotIndex;
    
};


class ofxRPiezosPanel {

public:

    struct GraphicsSettings {
        int width;
        int height;
        int separator;
    };

    void setupFromFile( string xmlSettingsPath );
    void setup( string serverIP, string name="piezos" );
    void update( );
    void draw();
    
    ofxPanel gui;
    
    vector<ofxRPiezoParams> piezos;
    
    ofParameter<bool> bCalibrate;
    ofParameter<bool> saveOnServer;
    ofParameter<bool> loadFromServer;
    
    GraphicsSettings settings;
    
    ofFbo fbo;
    
private:
    void saveCallback( bool & value );
    void loadCallback( bool & value );

    ofxOscParameterSync sync;    

    ofxOscReceiver receiver;
    
    // graphic variables:
    vector<PiezoGraphicsData> datas;
        
    string rawAddress;
    string envAddress;
    string trigAddress;
};
