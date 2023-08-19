#include "edita.h"
#include "./ui_edita.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QClipboard>
#include <iostream>

edita::edita(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EditA)
{
    ui->setupUi(this);
    // ui->tool->addWidget(ui->Font_B);
    // ui->tool->addWidget(ui->Font_I);
    // ui->tool->addWidget(ui->Font_U);
    ui->tool->addWidget(ui->TextFontSize);
    ui->tool->addWidget(ui->FontSize);
    ui->tool->addWidget(ui->TextSelectFont);
    ui->tool->addWidget(ui->SelectFont);

    ui->Edit->setStyleSheet("font-size: 13px; font-family: 微软雅黑;");
}


edita::~edita()
{
    delete ui;
}


void edita::on_action_about_triggered()
{
    QMessageBox::information(this, "关于 \"EditA\"",
                "EditA 版本 1.0\n版权所有 NaiTap Studio.",
                QMessageBox::Ok, QMessageBox::Ok);
}


void edita::on_action_exit_triggered()
{
    this->close();
    exit(0);
}

void edita::resizeEvent(QResizeEvent* re)
{
    ui->Edit->setGeometry(0, 0, this->width(), this->height() - 68);
}

void edita::on_FontSize_valueChanged(int value) {}

QString FONT_FAMILY = "微软雅黑";
QString FONT_SIZE = "10";

void edita::on_SelectFont_currentTextChanged(const QString &font)
{
    QString TMP = ui->Edit->toPlainText();
    std::string S_TMP = TMP.toStdString();
    const char* C_TMP = S_TMP.c_str();

    qDebug(C_TMP);
    ui->Edit->setText(TMP);
    ui->Edit->setStyleSheet("font-family: '" + font + "'; font-size: " + FONT_SIZE + ";");

    FONT_FAMILY = font;

    QString TMP_S =  ui->Edit->styleSheet();
    std::string S_TMP_S = TMP.toStdString();
    const char* C_TMP_S = S_TMP_S.c_str();
    (ui->Edit->styleSheet());
}

void edita::on_action_copy_triggered()
{
    QClipboard *clip = QApplication::clipboard();
    clip->setText(ui->Edit->toPlainText());
}


void edita::on_action_pause_triggered()
{
    QString TMP = ui->Edit->toPlainText();
    QClipboard *clip = QApplication::clipboard();
    ui->Edit->setText(TMP + clip->text());
}


void edita::on_action_shear_triggered()
{
    QClipboard *clip = QApplication::clipboard();
    clip->setText(ui->Edit->toPlainText());
    ui->Edit->setText("");
}


void edita::on_FontSize_textChanged(const QString &arg1)
{
    FONT_SIZE = arg1;
    QString TMP = ui->Edit->toPlainText();
    ui->Edit->setStyleSheet("font-size:" + arg1 + "px; font-family: '" + FONT_FAMILY + "';");
    ui->Edit->setText(TMP);
}


void edita::on_action_save_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, "另存至...", ".", "文本文档 (*.txt)\n所有文件 (*.*)");
    if(path.isEmpty() == false)
    {
        QFile file;
        file.setFileName(path);
        bool isok = file.open(QIODevice::WriteOnly);
        if(isok == true)
        {
            QString str = ui->Edit->toPlainText();
            file.write(str.toUtf8());
        }
        file.close();
    }
}


void edita::on_action_open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择一个文件打开"),".","文本文档 (*.txt)\n所有文件 (*.*)");
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"警告","请选择一个文件");
    }
    else
    {
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QByteArray baData = file.readAll();
        ui->Edit->setText(QString(baData));
        file.close();
    }
}

