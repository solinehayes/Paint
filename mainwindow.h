#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Drawzone.h"
#include "lines.h"

#include <QMainWindow>
#include <QTextEdit>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent *event);

public slots:
    void openFile();
    void saveFile();
    void quitApp();
    void openColor ();
    void selectSize(int k);
    void selectStyle(QString k );



private:
    Ui::MainWindow *ui=nullptr;
    Drawzone * draw=nullptr;



};

#endif // MAINWINDOW_H
