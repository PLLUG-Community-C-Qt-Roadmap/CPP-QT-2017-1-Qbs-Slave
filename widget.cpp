#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    mProcces{new QbsProcces(this)}
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->comboBox->addItem(QString("\0"));
    ui->comboBox->addItem(QString("Compile"));
    setLayout(ui->verLayout);

    mProcces->setPath("C:/Users/Bohdan/Documents/Qt/Pllug/Qbs/qbs-windows-x86_64-1.7.2/bin/qbs.exe");
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotProccesCommamd(int)));

    connect(mProcces, &QbsProcces::outputRead, ui->textEdit, &QTextEdit::append);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotProccesCommamd(int index)
{
    if(comboItem::Compiler == index)
        mProcces->slotCommand();
    if(comboItem::Empty == index)
        ui->textEdit->clear();
}
