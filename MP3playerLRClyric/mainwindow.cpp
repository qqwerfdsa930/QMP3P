#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    MP3P.MusicStop();
    ui->pushButton->setText("Play");
    MP3P.setFileName(QFileDialog::getOpenFileName(
                         this, tr("Open File"), QDir::currentPath(),
                          tr("MP3 file(*.mp3)")));
    ui->label->setText(MP3P.getFileName().split('/').last());
}

void MainWindow::on_pushButton_clicked()
{
    if(MP3P.getStat() == QMediaPlayer::State::StoppedState)
    {
        MP3P.MusicPlay();
         ui->pushButton->setText("Stop");
    }
    else if(MP3P.getStat() == QMediaPlayer::State::PlayingState)
    {
        MP3P.MusicStop();
        ui->pushButton->setText("Play");
    }
    else
        MP3P.getError();
}

