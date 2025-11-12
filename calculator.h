#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>

class QLineEdit;
class QPushButton;

class Calculator : public QDialog
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void digitClicked();
    void operatorClicked();
    void equalClicked();
    void clearClicked();
    void decimalClicked();
    void derivativeClicked();
    void integralClicked();

private:
    QLineEdit* display;
    
    // Calculator state
    double currentValue;
    double storedValue;
    QString currentOperator;
    bool waitingForOperand;
    
    // Buttons
    QPushButton* createButton(const QString& text, const char* slot);
    void calculate();
};

#endif // CALCULATOR_H
