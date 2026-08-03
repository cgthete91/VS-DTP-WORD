C++

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>
#include <QCloseEvent>
#include "translation_engine.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void onTranslateClicked();
    void onSaveClicked();
    void onSaveAsClicked();

private:
    void setupUI();
    
    QTextEdit *editor;
    QComboBox *languageCombo;
    QComboBox *modeCombo;
    TranslationEngine *aiEngine;
    
    bool isFileSaved;
    QString currentFilePath;
};

#endif // MAINWINDOW_H
