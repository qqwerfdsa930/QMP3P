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

void MainWindow::on_OpenBtn_clicked()
{
    OpenFile();
}

void MainWindow::on_PlayBtn_clicked()
{
    Play();
}

void MainWindow::OpenFile()
{
    Stop();
    MP3P.setFileName(QFileDialog::getOpenFileName(
                         this, tr("Open File"), QDir::currentPath(),
                          tr("MP3 file(*.mp3)")));
    ui->NameLab->setText(MP3P.getFileName().split('/').last());
}

void MainWindow::Play()
{
    if(MP3P.getFileName().size() > 0)
    {
        if(MP3P.getStat() == QMediaPlayer::State::StoppedState)
        {
            MP3P.MusicPlay();
            ui->PlayBtn->setText("Stop");
            std::thread timerThread(&MainWindow::showTimer, this);
            timerThread.detach();
        }
        else if(MP3P.getStat() == QMediaPlayer::State::PlayingState)
        {
            MP3P.MusicStop();
            ui->PlayBtn->setText("Play");
        }
        else
            MP3P.getError();
    }
}

void MainWindow::Stop()
{
    MP3P.MusicStop();
    ui->PlayBtn->setText("Play");
}

void MainWindow::showTimer()
{
    while(MP3P.getStat() == QMediaPlayer::State::PlayingState)
    {
        ui->TimerLab->setText(timer.getQTimer());
        timer.show(MP3P.getStat());
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    timer.reset();
    ui->TimerLab->setText(timer.getQTimer());
}
