C++

#include <QApplication>
#include <QDateTime>
#include <QSettings>
#include <QMessageBox>
#include "mainwindow.h"

bool checkTrialStatus() {
    QSettings settings("VSTech", "VSDTPWord");
    if (!settings.contains("first_run")) {
        settings.setValue("first_run", QDateTime::currentDateTime());
    }

    QDateTime firstRun = settings.value("first_run").toDateTime();
    QDateTime current = QDateTime::currentDateTime();

    qint64 days = firstRun.daysTo(current);

    if (days > 5) {
        QMessageBox::critical(nullptr, "Trial Expired", "Your 5-Day Free Trial has expired. Please enter a valid Product Key.");
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    if (!checkTrialStatus()) {
        return 0;
    }

    MainWindow w;
    w.show();
    return a.exec();
}
