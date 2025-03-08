#include <iostream>
using namespace std;

class MediaFile{    //one parent for both visual and audio media  (hierchial inheritance)
    protected:
        int size;
        string path;

    public:
        MediaFile (int s , string p) : size(s) , path(p) { 
            cout << "PARENT CONTRUCTOR!!" << endl;
        }

        virtual void play(){
            cout << "START PLAYING!!" << endl;
        }

        virtual void stop(){
            cout << "STOP PLAYING!!" << endl;
        }

        virtual ~MediaFile(){
            cout << "PARENT DESTRUCTOR!!" << endl;
        }
};

class VisualMedia : virtual public MediaFile {   //one of the parent for vedio file (multiple inheritance) | virtul ensures that parent class exists only once instead of copying
    public:
        VisualMedia(int s, string p) : MediaFile(s,p) {
            cout << "CHILD 1 CONTRUCTOR!!" << endl;
        }

        ~VisualMedia(){
            cout << "CHILD 1 DESTRUCTOR!!" << endl;
        }
};

class AudioMedia :virtual public MediaFile {     //one of the parent for vedio file (multiple inheritance)
    public:
        AudioMedia(int s, string p) : MediaFile(s,p) {
            cout << "CHILD 2 CONTRUCTOR!!" << endl;
        }

        ~AudioMedia(){
            cout << "CHILD 2 DESTRUCTOR!!" << endl;
        }
};

class VedioFile : public VisualMedia , public AudioMedia {  //under multi level inheritance of visual and audio media and media file at top (diamond)
    public:
        VedioFile(int s, string p) : MediaFile(s, p), VisualMedia(s,p) , AudioMedia(s,p) {
            cout << "CHILD'S CHILD CONTRUCTOR!!" << endl;
        }

        void play() override {                    // Override the play method
            cout << "Playing video: " << path << endl;
        }
    
        void stop() override {                      // Override the stop method
            cout << "Stopping video playback." << endl;
        }

        ~VedioFile(){
            cout << "CHILD'S CHILD DESTRUCTOR!!" << endl;
        }
};

int main() {
    MediaFile* media = new VedioFile(45, "mp4");     // Polymorphism
    media->play();
    media->stop();
    delete media;

    // Can also call play and stop functions in VisualMedia and AudioMedia by passing pointer of MedioFile in it's function's paramter (MediaFile* file and in definition file->play()) and call them in the main function.

    return 0;
}