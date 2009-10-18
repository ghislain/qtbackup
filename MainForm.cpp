#include "MainForm.h"
#include "ui_MainForm.h"

MainForm::MainForm(QWidget *parent, Qt::WFlags f) :
    QWidget(parent, f),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainForm::on_pushButtonBackup_clicked()
{
    QString window_title;
    QMessageBox msg_box;
    int exit_code;

    // Check if qtbackup.conf exists
    if(QFile::exists("qtbackup.conf")) {
        // Check if /media/card/qtbackup.tgz exists
        if(QFile::exists("/media/card/qtbackup.tgz")) {
            msg_box.setText(tr("Backup already exists. Overwrite?"));
            msg_box.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
            msg_box.setDefaultButton(QMessageBox::No);
            if(msg_box.exec() == QMessageBox::No) {
                close();
            }
        }

        if(QFile::exists("qtbackup.sh")) {
            if(!QFile::setPermissions("./qtbackup.sh", (QFile::Permission)0x7777)) {
                QMessageBox::warning(this,tr("QtBackup"),tr("Failed to set permissions."));
            }
            // Show Message 'Please Wait'
            window_title = this->windowTitle();
            setWindowTitle(tr("Please Wait"));
            // Execute script
            exit_code = QProcess::execute("./qtbackup.sh");
            // Remove Message 'Please Wait'
            setWindowTitle(window_title);
            // Show exit-status
            if (exit_code != 0) {
                QMessageBox::warning(this,tr("QtBackup"),tr("Backup failed."));
            } else {
                QMessageBox::information(this,tr("QtBackup"),tr("Backup Created."));
            }
        } else {
            QMessageBox::warning(this,tr("QtBackup"),tr("qtbackup.sh not found."));
        }
    } else {
        QMessageBox::warning(this,tr("QtBackup"),tr("qtbackup.conf not found."));
    }
    close();
}
