#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openAction = new QAction(tr("Open"), this);
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
    saveAction = new QAction(tr("Save"), this);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));
    exitAction = new QAction(tr("Exit"), this);
    connect(exitAction, SIGNAL(triggered()), this, SLOT(exit()));
    fileMenu = this->menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip("exit program");
    textEdit = new QTextEdit();
    setCentralWidget(textEdit);
    setWindowTitle(tr("Text Editor"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open(){
    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Open file"), "",
    tr("Text files(*.txt);; Files C++(*.cpp *.h)"));
if(fileName != ""){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, tr("Error"), tr("Can't open the file"));
        return;
    }
    QTextStream in(&file);
    textEdit->setText(in.readAll());
    file.close();
    }
}

void MainWindow::save(){
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save file"), "",
                                                    tr("Text files(*.txt);; Files C++(*.cpp *.h)"));
    if(fileName != ""){
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox msgBox; msgBox.setText("Can't save this file"); msgBox.exec();
    }
    else {
    QTextStream stream(&file);
    stream << textEdit->toPlainText();
    stream.flush();
    file.close();
     }
    }
}
void MainWindow::exit(){
    qApp->quit();
}
