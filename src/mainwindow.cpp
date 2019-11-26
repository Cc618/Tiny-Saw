#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>

#include "audio.h"
#include "input.h"

// TODO : rm
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    // Only key type
    if (!e->isAutoRepeat())
    {
        // Retrieve the char code (uppercase)
        QChar key = static_cast<QChar>(e->key());
        key = key.toUpper();

        // Test for note
        if (!input::triggerFromKey(key, true))
        {
            // TODO : Other commands
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    // Only key type
    if (!e->isAutoRepeat())
    {
        // Retrieve the char code (uppercase)
        QChar key = static_cast<QChar>(e->key());
        key = key.toUpper();

        // Test for note
        if (!input::triggerFromKey(key, false))
        {
            // TODO : Other commands
        }
    }
}

void MainWindow::setupSlots()
{
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(onExit()));
    connect(ui->mainVolume, SIGNAL(valueChanged(int)), this, SLOT(onMainVolume(int)));
}

void MainWindow::onExit()
{
    QApplication::exit();
}

void MainWindow::onMainVolume(int value)
{
    audio::mainVolume = static_cast<float>(value) * (1.f / 100.f);
}
