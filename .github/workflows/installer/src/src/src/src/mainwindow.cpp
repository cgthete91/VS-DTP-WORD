C++

#include "mainwindow.h"
#include <QToolBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), isFileSaved(true) {
    aiEngine = new TranslationEngine(this);
    setupUI();
    setWindowTitle("VS DTP WORD - [Untitled.dtpx]");
    resize(1024, 768);
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI() {
    QToolBar *toolbar = addToolBar("Text Formatting & AI Tools");

    languageCombo = new QComboBox(this);
    languageCombo->addItems({"MARATHI", "HINDI", "ENGLISH", "URDU", "BENGALI", "TAMIL", "KANNADA", "MALAYALAM", "TELUGU", "ODIA", "PUNJABI", "GUJARATI", "SANSKRIT"});
    toolbar->addWidget(languageCombo);

    modeCombo = new QComboBox(this);
    modeCombo->addItem("1. Original English -> Native", static_cast<int>(TransMode::OriginalToSelected));
    modeCombo->addItem("2. Roman English -> Native Script", static_cast<int>(TransMode::RomanToNativeScript));
    toolbar->addWidget(modeCombo);

    QPushButton *btnTranslate = new QPushButton("Start Translation", this);
    connect(btnTranslate, &QPushButton::clicked, this, &MainWindow::onTranslateClicked);
    toolbar->addWidget(btnTranslate);

    QPushButton *btnSave = new QPushButton("Save (.dtpx)", this);
    connect(btnSave, &QPushButton::clicked, this, &MainWindow::onSaveClicked);
    toolbar->addWidget(btnSave);

    editor = new QTextEdit(this);
    setCentralWidget(editor);

    connect(editor, &QTextEdit::textChanged, [this]() {
        this->isFileSaved = false;
    });
}

void MainWindow::onTranslateClicked() {
    QString inputText = editor->toPlainText();
    QString selectedLang = languageCombo->currentText();
    TransMode mode = static_cast<TransMode>(modeCombo->currentData().toInt());

    QString result = aiEngine->translateText(inputText, selectedLang, mode);
    editor->setText(result);
}

void MainWindow::onSaveClicked() {
    if (currentFilePath.isEmpty()) {
        onSaveAsClicked();
    } else {
        QFile file(currentFilePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << editor->toHtml();
            file.close();
            isFileSaved = true;
        }
    }
}

void MainWindow::onSaveAsClicked() {
    QString filePath = QFileDialog::getSaveFileName(this, "Save As", "", "DTP Word File (*.dtpx);;Word Document (*.docx);;PDF (*.pdf);;RTF (*.rtf);;Text (*.txt)");
    if (!filePath.isEmpty()) {
        currentFilePath = filePath;
        onSaveClicked();
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (!isFileSaved) {
        QMessageBox::StandardButton resBtn = QMessageBox::question(
            this, "VS DTP WORD", "DO YOU WANT TO SAVE THIS TEXT?",
            QMessageBox::No | QMessageBox::Yes | QMessageBox::Cancel,
            QMessageBox::Yes
        );

        if (resBtn == QMessageBox::Yes) {
            onSaveClicked();
            event->accept();
        } else if (resBtn == QMessageBox::No) {
            event->accept();
        } else {
            event->ignore();
        }
    } else {
        event->accept();
    }
}
