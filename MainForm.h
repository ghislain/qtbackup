#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QProcess>

namespace Ui {
    class MainForm;
}

class MainForm : public QWidget {
    Q_OBJECT
public:
    MainForm(QWidget *parent = 0, Qt::WFlags f = 0);
    ~MainForm();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainForm *ui;

private slots:
    void on_pushButtonBackup_clicked();
};

#endif // MAINFORM_H
