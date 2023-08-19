#ifndef EDITA_H
#define EDITA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class EditA; }
QT_END_NAMESPACE

class edita : public QMainWindow
{
    Q_OBJECT

public:
    edita(QWidget *parent = nullptr);
    ~edita();

    void resizeEvent(QResizeEvent* re);

private slots:
    void on_action_about_triggered();

    void on_action_exit_triggered();

    void on_FontSize_valueChanged(int value);

    void on_SelectFont_currentTextChanged(const QString &font);

    void on_action_copy_triggered();

    void on_action_pause_triggered();

    void on_action_shear_triggered();

    void on_FontSize_textChanged(const QString &arg1);

    void on_action_save_triggered();

    void on_action_open_triggered();

private:
    Ui::EditA *ui;
};
#endif // EDITA_H
