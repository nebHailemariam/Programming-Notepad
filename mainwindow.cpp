#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QFileDialog"
#include "QTextStream"
#include "QMessageBox"
#include "BalanceCheck.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionNew_triggered()
{
    file_path = "";
    ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }

        QTextStream in(&file);
        QString text = in.readAll();
        ui->textEdit->setText(text);
        file.close();

}

void MainWindow::on_actionSave_triggered()
{

    QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out<<text;
        file.flush();
        file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"Open the file");
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
    }
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out<<text;
        file.flush();
        file.close();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionAbout_Us_triggered()
{
    QString about_text;
    about_text = "Developers :Hanna Adugna, Nebiyou Daniel, Saron Negussie, Yoadan Ephrem\n";
    about_text += "Date   :           \n";
    about_text += "(C) NotePad (R)\n";
    QMessageBox::about(this,"About Notepad", about_text);





}

void MainWindow::on_textEdit_textChanged()
{
string text_string = ui->textEdit->toPlainText().toStdString();


    BalanceCheck check;
    int open = check.balancedCheck(text_string);

    if(open == 1){
        QColor color = Qt::red;
        ui->textEdit->setTextColor(color);
    }else{
        QColor color = Qt::black;
        ui->textEdit->setTextColor(color);
    }
}
