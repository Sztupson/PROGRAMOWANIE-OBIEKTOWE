#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>

class PlaybackType { // Strategy 
public:
    virtual ~PlaybackType() = default;
    virtual int getNextIndex(size_t currentIndex, size_t size) = 0;
    virtual std::string name() const = 0;
};

class NormalPlayback : public PlaybackType {
public:
    int getNextIndex(size_t currentIndex, size_t size) override {
        return (currentIndex + 1) % size;
    }
    std::string name() const override { return "Normal"; }
};
    
class RepeatPlayback : public PlaybackType {
public:
    int getNextIndex(size_t currentIndex, size_t size) override {
        return currentIndex;
    }
    std::string name() const override { return "Repeat"; }
};

class ShufflePlayback : public PlaybackType {
public:
    int getNextIndex(size_t currentIndex, size_t size) override {
        size_t next = currentIndex;
        while (next == currentIndex && size > 1) {
            next = rand() % size;
        }
        return next;
    }
    std::string name() const override {
        return "Shuffle";
    }
};


class MusicPlayer { // Singleton
private:
    std::vector <std::string> playlist;
    size_t currentIndex = 0;

    PlaybackType* strategy = nullptr;

    static MusicPlayer* instance;
    MusicPlayer() = default;
public:
    static MusicPlayer* getInstance() {
        if(!instance) { instance = new MusicPlayer(); }
        return instance;
    }
    void setStrategy(PlaybackType* strat) {
        strategy = strat;
        std::cout << "Tryb odtwarzania: " << strategy->name() << std::endl;
    }

    void addSong(const std::string& song) {
        playlist.push_back(song);
    }
    void play() const {
        if(playlist.empty()) { 
            std::cout << "Playlista jest pusta.\n"; 
            return; 
        }
        std::cout << "Odtwarzanie: " << playlist[currentIndex] << std::endl; 
    }

    void next() {
        if(!strategy || playlist.empty()) return;
        currentIndex = strategy->getNextIndex(currentIndex, playlist.size());
        play();
    }
};

MusicPlayer* MusicPlayer::instance = nullptr;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    MusicPlayer* player = MusicPlayer::getInstance();

    player->addSong("Imagine - John Lennon");
    player->addSong("Billie Jean - Michael Jackson");
    player->addSong("Bohemian Rhapsody - Queen");
    player->addSong("Shape of You - Ed Sheeran");

    NormalPlayback normal;
    RepeatPlayback repeat;
    ShufflePlayback shuffle;

<<<<<<< HEAD
    std::cout << "\nZmiana trybu na Shuffle:\n";
    player->setStrategy(&shuffle);
    player->next();
    player->next();

=======
>>>>>>> 77effad7dbca26e1f9d827d6cb9d6f1f3cd04e19
    player->setStrategy(&normal);
    player->play();
    player->next();
    player->next();

    std::cout << "\nZmiana trybu na Repeat:\n";
    player->setStrategy(&repeat);
    player->next();
    player->next();

<<<<<<< HEAD
    

=======
    std::cout << "\nZmiana trybu na Shuffle:\n";
    player->setStrategy(&shuffle);
    player->next();
    player->next();
>>>>>>> 77effad7dbca26e1f9d827d6cb9d6f1f3cd04e19

    return 0;
}