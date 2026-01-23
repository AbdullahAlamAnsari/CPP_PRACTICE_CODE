#include <iostream>
using namespace std;

class Media
{
    protected:
    string medianame;

    public:

    Media(string medianame)
    {
        this->medianame = medianame;
    }
    
};

class Audio : public Media
{
    protected:
    int audiolength = 0;

    public:
    Audio(int audiolength,string medianame) : Media(medianame)
    {
        this->medianame = medianame;
        this->audiolength = audiolength;
    }

};

class Video : public Audio
{
    protected:
    int resolution = 1024;

    public:
    Video(int resolution,int audiolength,string medianame) : Audio (audiolength,medianame)
    {
        this->audiolength = audiolength;
        this->medianame = medianame;
        this->resolution = resolution;
    }

};

class Video
{
    
};

int main()
{

}