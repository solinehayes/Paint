#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Drawzone.h"

#include <QMenuBar>
#include <QAction>
#include <QMenu>
#include <QString>
#include <QFileDialog>
#include <QTextEdit>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <QDialogButtonBox>
#include <QCloseEvent>
#include <QSlider>
#include <QColorDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QComboBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    this->statusBar();
    QMenuBar * menuBar=this->menuBar();
    QMenu * fileMenu=menuBar->addMenu(tr("&File"));
    QMenu * penMenu = menuBar->addMenu(tr("&Pen Style"));
    QToolBar * toolBar=this->addToolBar(tr("File"));

    draw= new Drawzone(this);



    QAction * open= new QAction(QIcon(":/images/open.png"), tr("&Open"), this);
    QAction * save= new QAction(QIcon(":/images/save.png"),tr("&Save"), this);
    QAction * quit= new QAction(QIcon(":/images/quit.png"),tr("&Quit"), this);
    QAction * color = new QAction(QIcon(":/images/size.png"), tr("&Color"), this);



    QSlider *slider = new QSlider(Qt::Horizontal,this);
    QComboBox * selectStyle= new QComboBox(this);

    selectStyle->addItem(tr("Solid Line"), 1);
    selectStyle->addItem(tr("Dotted Line"),2);
    selectStyle->addItem(tr("Dashed Line"), 3);

    toolBar->addAction(open);
    toolBar->addAction(save);
    toolBar->addAction(quit);
    toolBar->addAction(color);
    toolBar->addWidget(selectStyle);
    toolBar->addWidget(slider);


    setCentralWidget(draw);

    open->setShortcut(tr("Ctrl+O"));
    open->setToolTip(tr("Open a new file"));
    save->setShortcut(tr("Ctrl+S"));
    save->setToolTip(tr("Save the current file"));
    quit->setShortcut(tr("Ctrl+Q"));
    quit->setToolTip(tr("Quit"));


    fileMenu->addAction(open);
    fileMenu->addAction(save);
    fileMenu->addAction(quit);

    penMenu->addAction(color);




    connect(open, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(save, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(quit, SIGNAL(triggered()), this, SLOT(quitApp()));
    connect(color,SIGNAL(triggered()), this, SLOT(openColor()));
    connect(slider,SIGNAL(valueChanged(int )),this,SLOT(selectSize(int)));
    connect(selectStyle, SIGNAL(currentIndexChanged(QString)), this, SLOT(selectStyle(QString)));





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile() {
    QString fileName=QFileDialog::getOpenFileName(this,tr("Open File"), "/cal/homes/shayes");
    std::cout << qPrintable(fileName) << std::endl;

    QFile file(fileName);
    if (file.open(QFile::ReadOnly)){
        QTextStream out(&file);
        //text->setHtml(out.readAll());


    }


}

void MainWindow::saveFile() {
     QString fileName=QFileDialog::getSaveFileName(this,tr("Save File"), "/cal/homes/shayes");

     std::cout << qPrintable(fileName) << std::endl;

     QFile file(fileName);
     if (file.open(QFile::WriteOnly)){
         QTextStream out(&file);
         //out << text->toPlainText();
     }

}

void MainWindow::quitApp(){
    int rep= QMessageBox::question(this,"Quit", "Are you sure?", QMessageBox::Yes | QMessageBox::No);
    if (rep== QMessageBox::Yes){
        this->close();
    }

}

void MainWindow::closeEvent (QCloseEvent *event) {
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, tr("Quit?"),tr("Are you sure?\n"),QMessageBox::No |QMessageBox::Yes);
    if (resBtn== QMessageBox::Yes) {
       event->accept();
    }
}

void MainWindow::openColor () {
    QColor color=QColorDialog::getColor(Qt::black,this);
    draw->setColor(color);

}

void MainWindow::selectSize(int k) {
    draw->setSize(k);
}

void MainWindow::selectStyle(QString k) {
    if(k=="Solid Line"){
        draw->setStyle(Qt::SolidLine);}
    else if (k=="Dotted Line") {
        draw->setStyle(Qt::DotLine);
    }
    else if (k=="Dashed Line") {
        draw->setStyle(Qt::DashLine);
    }
}
