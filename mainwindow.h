#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void open();// to open
    void save();// to save
    void exit();//to exit
private:
    Ui::MainWindow *ui;
    QTextEdit *textEdit; //pointer to the entering field
    QAction *openAction; //pointer to "OPEN"
    QAction *saveAction; //pointer to "SAVE"
    QAction *exitAction; //pointer to "EXIT"
    QMenu *fileMenu; //pointer to "MENU"
};
#endif // MAINWINDOW_H
