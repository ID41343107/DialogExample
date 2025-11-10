/********************************************************************************
** Form generated from reading UI file 'byterconverter.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BYTERCONVERTER_H
#define UI_BYTERCONVERTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ByterConverter
{
public:

    void setupUi(QDialog *ByterConverter)
    {
        if (ByterConverter->objectName().isEmpty())
            ByterConverter->setObjectName("ByterConverter");
        ByterConverter->resize(800, 600);

        retranslateUi(ByterConverter);

        QMetaObject::connectSlotsByName(ByterConverter);
    } // setupUi

    void retranslateUi(QDialog *ByterConverter)
    {
        ByterConverter->setWindowTitle(QCoreApplication::translate("ByterConverter", "ByterConverter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ByterConverter: public Ui_ByterConverter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BYTERCONVERTER_H
