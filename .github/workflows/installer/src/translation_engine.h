C++

#ifndef TRANSLATION_ENGINE_H
#define TRANSLATION_ENGINE_H

#include <QString>
#include <QMap>
#include <QObject>

enum class TransMode {
    OriginalToSelected,
    RomanToNativeScript,
    NativeToNative,
    ForeignToEnglishToIndian
};

class TranslationEngine : public QObject {
    Q_OBJECT

public:
    explicit TranslationEngine(QObject *parent = nullptr);
    
    // Core Functions
    QString translateText(const QString &inputText, const QString &targetLang, TransMode mode);
    QString transliterateRomanToNative(const QString &romanText, const QString &targetLang);

private:
    void loadDictionaries();
    QMap<QString, QString> romanToMarathiMap;
    QMap<QString, QString> romanToHindiMap;
};

#endif // TRANSLATION_ENGINE_H
