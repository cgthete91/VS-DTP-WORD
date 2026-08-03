C++

#include "translation_engine.h"

TranslationEngine::TranslationEngine(QObject *parent) : QObject(parent) {
    loadDictionaries();
}

void TranslationEngine::loadDictionaries() {
    // Roman English to Marathi Basic Rule Mapping
    romanToMarathiMap["BHARAT EK MAHAN DESH AAHE"] = "भारत एक महान देश आहे";
    romanToMarathiMap["BHARATACHA SWAATANTRY DIVAS PANDHRA AUGAST AAHE"] = "भारताचा स्वातंत्र्य दिवस पंधरा ऑगस्ट आहे";
    romanToMarathiMap["SHIVAJI MAHARAJ EK MAHAN RAJA HOTE"] = "शिवाजी महाराज एक महान राजा होते";

    // Roman English to Hindi Basic Rule Mapping
    romanToHindiMap["BHARAT KA AAJADI DIN PANDHRA AUGAST HAI"] = "भारत का आजादी दिन पंधरा ऑगस्ट है";
    romanToHindiMap["BHARAT EK MAAHAN DESH HAI"] = "भारत एक महान देश है";
    romanToHindiMap["SHIVAJI MAHARAJ EK MAAHAN RAJA THE"] = "शिवजी महाराज एक महान राजा थे";
}

QString TranslationEngine::transliterateRomanToNative(const QString &romanText, const QString &targetLang) {
    QString trimmed = romanText.trimmed().toUpper();
    
    if (targetLang.toLower() == "marathi") {
        if (romanToMarathiMap.contains(trimmed)) {
            return romanToMarathiMap[trimmed];
        }
    } else if (targetLang.toLower() == "hindi") {
        if (romanToHindiMap.contains(trimmed)) {
            return romanToHindiMap[trimmed];
        }
    }
    
    return romanText; 
}

QString TranslationEngine::translateText(const QString &inputText, const QString &targetLang, TransMode mode) {
    if (mode == TransMode::RomanToNativeScript) {
        return transliterateRomanToNative(inputText, targetLang);
    }
    
    if (targetLang.toLower() == "marathi") {
        if (inputText.contains("SACHIN TENDULKAR IS GREAT PLAYER", Qt::CaseInsensitive))
            return "सचिन तेंडुलकर एक महान खेळाडू आहे";
        if (inputText.contains("INDIA IS GREAT COUNTRY", Qt::CaseInsensitive))
            return "भारत एक महान देश आहे";
        if (inputText.contains("SHIVAJI MAHARAJ IS GREAT KING", Qt::CaseInsensitive))
            return "शिवाजी महाराज हे एक महान राजे आहेत";
    }
    
    return inputText;
}
