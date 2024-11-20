#include <iostream>
#include <string>

class Media {
public:

    Media(const std::string& _filename): filename(_filename){}
    virtual void play() = 0;
    virtual void pause() = 0;
    const std::string& getFilename() const {
        return filename;
    }

protected:
    std::string filename;
};

class AudioPlayer : virtual public Media {
public:

    AudioPlayer(const std::string& _filename) : Media(_filename) {}

    void play() override{std::cout << "AudioPlayer: playing: " << getFilename() << std::endl;};
    void pause() override{std::cout << "AudioPlayer: paused: " << getFilename() << std::endl;};
    void setVolume(int volume) {
        std::cout << "Setting volume to: "<< volume <<std::endl;
    };
private:

};

class VideoPlayer : virtual public Media {
public:

    VideoPlayer(const std::string& _filename) : Media(_filename) {}

    void play() override{std::cout << "VideoPlayer: playing: " << getFilename() << std::endl;};
    void pause() override{std::cout << "VideoPlayer: paused: " << getFilename() << std::endl;};
    void setBrightness(double brightness) {
        std::cout << "Setting brightness to: " << brightness << std::endl;
    }
private:

};
class AVPlayer : public AudioPlayer, public VideoPlayer {
public:

    AVPlayer(const std::string& _filename) 
    : Media(_filename), AudioPlayer(_filename), VideoPlayer(_filename) {}

    void play() override {
        std::cout << "AVPlayer: synchronizing a/v: " << getFilename() << std::endl;
        AudioPlayer::play();
        VideoPlayer::play();
    }

    void pause() override {
        std::cout << "AVPlayer: pausing: " << getFilename() << std::endl;
        AudioPlayer::pause(); 
        VideoPlayer::pause();
    }
private:

};

int main() {
    AVPlayer c("muzyka");

    c.setBrightness(0.5);
    c.setVolume(5);
    c.play();
    c.pause();

    return 0;
}