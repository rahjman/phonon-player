#include <QtCore/QCoreApplication>
#include <phonon/mediaobject.h>
#include <phonon/audiooutput.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    a.setApplicationName("phonon-player");

    Phonon::MediaObject *mediaObject = new Phonon::MediaObject( &a );
    Phonon::AudioOutput *audioOutPut = new Phonon::AudioOutput(Phonon::MusicCategory, &a);
    Phonon::createPath(mediaObject, audioOutPut);

    mediaObject->setCurrentSource(Phonon::MediaSource(argv[1]));

    mediaObject->play();

    return a.exec();
}
