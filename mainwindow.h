#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_actionUndo_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionRedo_triggered();

    void on_actionAbout_Us_triggered();

    void on_actionPaste_triggered();

    void on_textEdit_textChanged();

private:
    Ui::MainWindow *ui;
    QString file_path;
    int semi_colon_right;
    int semi_colon_left;
};

#endif // MAINWINDOW_H
