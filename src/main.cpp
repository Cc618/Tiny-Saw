#include <QApplication>
#include <portaudio.h>

#include "mainwindow.h"
#include "audio.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Begin audio
    if (!audio::init())
        return -1;

    // Init the window
    MainWindow w;
    w.show();

    // Main program
    bool noError = a.exec() == 0;

    // Close audio
    noError |= audio::terminate();

    // Terminate port audio even if we have an error
    Pa_Terminate();

    return noError ? 0 : -1;
}
