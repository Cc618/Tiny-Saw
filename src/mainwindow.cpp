#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>

#include "audio.h"

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
