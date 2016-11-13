#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <thread>
#include <chrono>
#include "mp3player.h"
#include "timer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_OpenBtn_clicked();
    void on_PlayBtn_clicked();

private:
    Ui::MainWindow *ui;
    MP3Player MP3P;
    Timer timer;

    void OpenFile();
    void Play();
    void Stop();
    void showTimer();
};

#endif // MAINWINDOW_H
