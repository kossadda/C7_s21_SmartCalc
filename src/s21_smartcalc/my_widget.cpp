#include "my_widget.h"
#include "ui_my_widget.h"

my_widget::my_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::my_widget)
{
    ui->setupUi(this);

    // Создаем компоненты
    comboBox = new QComboBox(this);
    addButton = new QPushButton("Добавить", this);
    removeButton = new QPushButton("Удалить", this);
    dateEdit = new QDateEdit(this); // Добавлено
    amountLineEdit = new QLineEdit(this); // Добавлено

    // Настройка макета
    QVBoxLayout *layout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    // Добавляем компоненты в макет
    layout->addWidget(comboBox);
    comboBox->setStyleSheet("border: 1px solid gray; font-size: 13px;");
    layout->addWidget(dateEdit);
    dateEdit->setStyleSheet("QDateEdit { text-align: right; font-size: 15px; border: 1px solid gray }");
    dateEdit->setDate(QDate::currentDate());
    layout->addWidget(amountLineEdit);
    amountLineEdit->setStyleSheet("border: 1px solid gray; font-size: 15px;");
    amountLineEdit->setPlaceholderText("Введите сумму");
    buttonLayout->addWidget(addButton);
    addButton->setStyleSheet("background-color: rgb(22, 89, 22);");
    removeButton->setStyleSheet("background-color: rgb(99, 27, 27);");
    buttonLayout->addWidget(removeButton);
    layout->addLayout(buttonLayout);

    // Устанавливаем макет для виджета
    setLayout(layout);

    // Подключаем сигналы к слотам
    connect(addButton, &QPushButton::clicked, this, &my_widget::onAddButtonClicked);
    connect(removeButton, &QPushButton::clicked, this, &my_widget::onRemoveButtonClicked);
}

my_widget::~my_widget()
{
    if(comboBox) delete comboBox;
    if(addButton) delete addButton;
    if(removeButton) delete removeButton;
    if(dateEdit) delete dateEdit;
    if(amountLineEdit) delete amountLineEdit;
    delete ui;
}

bool containsOnlyDigits(const QString &str)
{
    for (const QChar &ch : str) {
        if (!ch.isDigit()) {
            return false;
        }
    }
    return true;
}

void my_widget::onAddButtonClicked()
{
    if (containsOnlyDigits(amountLineEdit->text()) && amountLineEdit->text().length()) {
        QString newItem = QString("%1 : %2").arg(dateEdit->date().toString("dd.MM.yyyy"), amountLineEdit->text());
        comboBox->addItem(newItem);
    }
}

void my_widget::onRemoveButtonClicked()
{
    comboBox->removeItem(comboBox->currentIndex());
}

QComboBox* my_widget::getComboBox() const
{
    return comboBox;
}
