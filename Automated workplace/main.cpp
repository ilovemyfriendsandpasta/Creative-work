#include "mainwindow.h"
#include "secondwindow.h"
#include "dialog.h"

#include <QApplication>
#include <QProgressBar>
#include <QTimer>
#include <QVBoxLayout>
#include <QDialog>

#include <QApplication>
#include <QProgressBar>
#include <QTimer>
#include <QVBoxLayout>
#include <QDialog>
#include "mainwindow.h"

class LoadingDialog : public QDialog
{
    Q_OBJECT

public:
    LoadingDialog(QWidget *parent = nullptr) : QDialog(parent)
    {
        setWindowTitle("Loading...");
        setFixedSize(300, 100);

        QVBoxLayout *layout = new QVBoxLayout(this);

        progressBar = new QProgressBar();
        progressBar->setRange(0, 0);  // Устанавливаем значение ProgressBar
        progressBar->setTextVisible(false);

        layout->addWidget(progressBar);
        setLayout(layout);

        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &LoadingDialog::startLoading);
        timer->start(50);
    }

    ~LoadingDialog()
    {
        delete progressBar;
        delete timer;
    }

signals:
    void loadingFinished();

public slots:
    void startLoading()
    {
        if(progressBar->value() < progressBar->maximum())
        {
            progressBar->setRange(0, progressBar->value() + 1);
        }
        else
        {
            timer->stop();
            close();
            emit loadingFinished();  // Сигнал "loadingFinished"
        }
    }

private:
    QProgressBar *progressBar;
    QTimer *timer;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoadingDialog loadingDialog;
    loadingDialog.show();

    MainWindow w;
    QObject::connect(&loadingDialog, &LoadingDialog::loadingFinished, &w, [&w](){ w.show(); });

    QTimer::singleShot(3000, &loadingDialog, &QDialog::close);

    return a.exec();
}

#include "main.moc"  // Для подключения метаобъектного компилятора
