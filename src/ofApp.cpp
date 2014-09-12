#include "ofApp.h"

void ofApp::setup() {
	ofBackground(0, 0, 0);
    //画面の混色の設定を加算合成にする
	//ビットマップ画像の読みこみ
    ofEnableAlphaBlending();
	myImage.loadImage("01.png");
    myImage.setImageType(OF_IMAGE_GRAYSCALE);
    
    asciiCharacters =  string("  ..,,,'''``--_:;^^**""=+<>iv%&xclrs)/){}I?!][1taeo7zjLunT#@JCwfy325Fp6mqSghVd4EgXPGZbYkOA8U$KHDBWNMR0Q");
    font.loadFont("Helvetica", 10);
    infoFont.loadFont("futura_book.otf", 11);
}

void ofApp::update() {}

void ofApp::draw() {
    
	unsigned char * pixels = myImage.getPixels();
    
	int skip = 10;
	ofSetColor(255, 255, 255);
	
	for (int i = 0; i < myImage.width; i += skip){
		for (int j = 0; j < myImage.height; j += skip){
			int brightness = pixels[(j * myImage.width) + i];
			float pct = 1.0 - brightness / 255.0;
			//濃度の応じた文字をとりだし
            if (brightness == 0) {
                float lightness = ofRandom(255.0);
                int character = powf( ofMap(lightness, 0, 255, 0, 1), 2.5) * asciiCharacters.size();
                // draw the character at the correct location
                font.drawString(ofToString(asciiCharacters[character]), i, j);
                
            }
		}
	}
    
    infoFont.drawString("This is a sample for drawing ascii texture.\n\nTyping a key between 0 and 9 display it.", 60, 200);
}

void ofApp::keyPressed(int key) {
    switch (key) {
        case '0':
            changeNumber(10);
            break;
        case '1':
            changeNumber(1);
            break;
        case '2':
            changeNumber(2);
            break;
        case '3':
            changeNumber(3);
            break;
        case '4':
            changeNumber(4);
            break;
        case '5':
            changeNumber(5);
            break;
        case '6':
            changeNumber(6);
            break;
        case '7':
            changeNumber(7);
            break;
        case '8':
            changeNumber(8);
            break;
        case '9':
            changeNumber(9);
            break;
            
        default:
            break;
    }
}

void ofApp::changeNumber(int n) {
    char sNum[32];
    sprintf(sNum, "%02d.png", n);
    printf("number = %s", sNum);
    
    myImage.loadImage(sNum);
    myImage.setImageType(OF_IMAGE_GRAYSCALE);
}
