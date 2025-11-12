#include "calculator.h"
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <cmath>

Calculator::Calculator(QWidget *parent)
    : QDialog(parent), currentValue(0.0), storedValue(0.0), waitingForOperand(true)
{
    // Create display
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);
    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);
    display->setMinimumHeight(50);

    // Create main layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(display);

    // Create button grid
    QGridLayout* gridLayout = new QGridLayout;
    mainLayout->addLayout(gridLayout);

    // Number buttons (0-9)
    for (int i = 1; i <= 9; i++) {
        int row = (9 - i) / 3 + 1;
        int col = (i - 1) % 3;
        QPushButton* button = createButton(QString::number(i), SLOT(digitClicked()));
        gridLayout->addWidget(button, row, col);
    }

    // Zero button
    QPushButton* zeroButton = createButton("0", SLOT(digitClicked()));
    gridLayout->addWidget(zeroButton, 4, 0, 1, 2);

    // Decimal point button
    QPushButton* decimalButton = createButton(".", SLOT(decimalClicked()));
    gridLayout->addWidget(decimalButton, 4, 2);

    // Operation buttons
    QPushButton* addButton = createButton("+", SLOT(operatorClicked()));
    gridLayout->addWidget(addButton, 1, 3);

    QPushButton* subButton = createButton("-", SLOT(operatorClicked()));
    gridLayout->addWidget(subButton, 2, 3);

    QPushButton* mulButton = createButton("×", SLOT(operatorClicked()));
    gridLayout->addWidget(mulButton, 3, 3);

    QPushButton* divButton = createButton("÷", SLOT(operatorClicked()));
    gridLayout->addWidget(divButton, 4, 3);

    // Special buttons
    QPushButton* equalButton = createButton("=", SLOT(equalClicked()));
    gridLayout->addWidget(equalButton, 5, 3);

    QPushButton* clearButton = createButton("C", SLOT(clearClicked()));
    gridLayout->addWidget(clearButton, 0, 0, 1, 2);

    // Exit button
    QPushButton* exitButton = createButton("Exit", SLOT(accept()));
    gridLayout->addWidget(exitButton, 0, 2);

    setWindowTitle("Calculator");
    setMinimumSize(300, 400);
}

Calculator::~Calculator()
{
}

QPushButton* Calculator::createButton(const QString& text, const char* slot)
{
    QPushButton* button = new QPushButton(text);
    QFont font = button->font();
    font.setPointSize(font.pointSize() + 2);
    button->setFont(font);
    button->setMinimumSize(60, 40);
    connect(button, SIGNAL(clicked()), this, slot);
    return button;
}

void Calculator::digitClicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    QString digitValue = clickedButton->text();

    if (waitingForOperand) {
        display->setText(digitValue);
        waitingForOperand = false;
    } else {
        if (display->text() == "0") {
            display->setText(digitValue);
        } else {
            display->setText(display->text() + digitValue);
        }
    }
}

void Calculator::decimalClicked()
{
    if (waitingForOperand) {
        display->setText("0.");
        waitingForOperand = false;
    } else if (!display->text().contains(".")) {
        display->setText(display->text() + ".");
    }
}

void Calculator::operatorClicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    QString clickedOperator = clickedButton->text();

    currentValue = display->text().toDouble();

    if (!currentOperator.isEmpty()) {
        calculate();
        display->setText(QString::number(storedValue));
    } else {
        storedValue = currentValue;
    }

    currentOperator = clickedOperator;
    waitingForOperand = true;
}

void Calculator::equalClicked()
{
    currentValue = display->text().toDouble();
    
    if (!currentOperator.isEmpty()) {
        calculate();
        display->setText(QString::number(storedValue));
        currentOperator.clear();
    }
    
    waitingForOperand = true;
}

void Calculator::calculate()
{
    if (currentOperator == "+") {
        storedValue = storedValue + currentValue;
    } else if (currentOperator == "-") {
        storedValue = storedValue - currentValue;
    } else if (currentOperator == "×") {
        storedValue = storedValue * currentValue;
    } else if (currentOperator == "÷") {
        if (currentValue != 0.0) {
            storedValue = storedValue / currentValue;
        } else {
            display->setText("Error");
            storedValue = 0.0;
        }
    }
}

void Calculator::clearClicked()
{
    display->setText("0");
    currentValue = 0.0;
    storedValue = 0.0;
    currentOperator.clear();
    waitingForOperand = true;
}
