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
    QString toLabel;
    for(int i = MP3P.getFileNameLength() - 1;i >= 0; --i)
    {
        if(MP3P.getFileName(i) != '/')
            toLabel.push_front(MP3P.getFileName(i));
        else
            break;
    }
    ui->label->setText(toLabel);
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

