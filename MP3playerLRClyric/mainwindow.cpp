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
    delete player;
}

void MainWindow::on_pushButton_2_clicked()
{
    MusicStop();
    FileName = QFileDialog::getOpenFileName(
               this, tr("Open File"), QDir::currentPath(),
                tr("MP3 file(*.mp3)"));
    QString toLabel;
    for(int i = FileName.length() - 1; i >= 0 ; --i)
    {
        if(FileName[i] != '/')
            toLabel.push_front(FileName[i]);
        else
            break;
    }
    ui->label->setText(toLabel);
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->pushButton->text() == "Play")
        MusicPlay();
    else if(ui->pushButton->text() == "Stop")
        MusicStop();
    else
        player->error();
}

void MainWindow::MusicPlay()
{
    player->setMedia(QUrl::fromLocalFile(FileName));
    player->setVolume(50);
    player->play();
    ui->pushButton->setText("Stop");
}

void MainWindow::MusicStop()
{
    player->stop();
    ui->pushButton->setText("Play");
}
