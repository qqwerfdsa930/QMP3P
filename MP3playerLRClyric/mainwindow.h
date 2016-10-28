#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMediaPlayer>

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
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void MusicPlay();
    void MusicStop();

private:
    Ui::MainWindow *ui;
    QString FileName;
    QMediaPlayer* player = new QMediaPlayer(this);
};

#endif // MAINWINDOW_H
